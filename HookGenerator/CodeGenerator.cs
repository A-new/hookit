using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


namespace HookGenerator
{
    // i don't have a real C/C++ syntax tokenizer, so this is incredebely hacked.
    class CodeGenerator
    {
        //string m_text;
        //int m_pos;
        Tokenizer m_MainTokenizer;

        SortedDictionary<string, int> m_ClassDeclarationLocations;

        public CodeGenerator(string text)
        {
            m_ClassDeclarationLocations = new SortedDictionary<string, int>();
            m_MainTokenizer = new Tokenizer(text);
        }

       

        private ParsedFunc parse_func()
        {
            ParsedFunc func = new ParsedFunc();

            string tok;
            string prev = "";

            bool arg_list_started = false;
            bool arg_list_ended = false;

            func.return_type = ""; //might not have return value - constructor/destructor

            int scope_depth = 0;

            int template_scope_depth = 0;

            func.args_list = new List<ParsedArgument>();

            ParsedArgument arg = new ParsedArgument();

            //bool first_arg = true;

            tok = m_MainTokenizer.NextToken();
            prev = tok;

            //using one lookahead.

            while (tok!=null)
            {
                tok = m_MainTokenizer.NextToken();

                //note: i do not support const functions.
               
                if (";" == tok)
                {
                    if (prev == "}")
                    {
                        return null;
                    }

                    if (func.func_name == func.return_type)
                    {
                        //constructor/destructor
                        func.return_type = "";
                    }

                    return func;
                }

                if ("<" == prev)
                {
                    template_scope_depth++;
                }
                else if (">" == prev)
                {
                    template_scope_depth--;
                }

                if ("{" == prev)
                {
                    scope_depth++;
                }
                else if ("}" == prev)
                {
                    scope_depth--;

                    if (scope_depth < 0)
                        return null;
                }
                else
                {

                    //if we're in deeper scope, then it's function definition which we don't care about.
                    if (0 == scope_depth)
                    {
                        if ("(" == tok)
                        {
                            arg_list_started = true;
                            func.func_name = prev;
                        }
                        else if (")" == prev)
                        {

                            arg_list_ended = true;
                        }
                        else /*if (";" == prev)
                        {
                            if (func.func_name == func.return_type)
                            { 
                                //constructor/destructor
                                func.return_type = "";
                            }


                            return func;
                        }
                        else*/
                        {
                            if (!arg_list_started && !arg_list_ended)
                            {
                                if (func.return_type != "")
                                {
                                    func.return_type += " ";
                                }

                                func.return_type += prev;
                            }
                            else if (arg_list_started == true && !arg_list_ended)
                            {
                                if ( ("(" != prev && "," != prev) || 0!=template_scope_depth)
                                {
                                    if (("," == tok || ")" == tok) && 0 == template_scope_depth) // if next is "," or ")" and we're not inside a template definition
                                    {
                                        arg.arg_name = prev;

                                        func.args_list.Add(arg);
                                        arg = new ParsedArgument();
                                    }
                                    else
                                    {
                                        arg.arg_type += prev + " ";
                                    }
                                }


                            }

                        }
                    }
                }

               

                prev = tok;
            }

            Debug.Print("Error! text ended before func declaration ended.\n");
            return null;
        }

        public string generate_function_code_DEBUG(ParsedFunc func)
        {
            string result = "";

            result += "Return type:[" + func.return_type + "] ";
            result += "Func Name:[" + func.func_name + "] ";
            result += "(";

            foreach( ParsedArgument arg in func.args_list)
            {
                result += "Type:["+arg.arg_type + "] ";
                result += "Name:[" + arg.arg_name + "] ";
            }

            result += ")\r\n";
            result += "{ ... };";

            return result;       
        }

        public string generate_function_code_GlobalFunction(ParsedFunc func)
        {
            string result = "";

            result += "\r\n";
            result += "//////////////////////////////////////////////////////////////////\r\n";
            result += "// " + func.func_name + " Hooking\r\n";
            result += "//////////////////////////////////////////////////////////////////\r\n";
            result += "\r\n";

            //split return type from function description

            Tokenizer t = new Tokenizer(func.return_type);

            string return_type = "";
            string call_type = "";

            string tok = null;
            while (true)
            {
                tok = t.NextToken();

                if (null == tok)
                    break;

                if (tok.Contains("__declspec") || tok.Contains("__stdcall"))
                {
                    if (!tok.Contains("__declspec(dllimport)"))
                    {
                        call_type += tok + " ";
                    }                     
                }
                else
                {
                    return_type += tok + " ";
                }
                
            }


            ////////////
            // typedef
            ////////////

            result += "typedef " + return_type;
            result += " (" + call_type + "*" + func.func_name + "_FPTR)(\r\n";

            bool bFirst = true;

            foreach (ParsedArgument arg in func.args_list)
            {
                result += "\t";
                if (!bFirst)
                {
                    result += ",";
                } 
                
                result += arg.arg_type + " ";
                result += arg.arg_name + "\r\n";

                bFirst = false;
            }

            result += "\t);\r\n";

            //////////////////////////
            // orig func pointer
            //////////////////////////

            result += func.func_name + "_FPTR g_" + func.func_name + "_ORIG = NULL;\r\n";
            
            /////////////////////////////
            // detour function
            /////////////////////////////

            result += return_type + " " + call_type + " " + func.func_name + "_DETOUR (\r\n";

            foreach (ParsedArgument arg in func.args_list)
            {
                result += "\t";
                if (!bFirst)
                {
                    result += ",";
                }

                result += arg.arg_type + " ";
                result += arg.arg_name + "\r\n";

                bFirst = false;
            }

            result += "\t)\r\n";
            result += "{\r\n";

            //assert to test the orig func pointer is valid
            result += "\tassert(g_" + func.func_name + "_ORIG);\r\n";

            //call the orig function

            result += "\t";

            if ("void " != return_type)
            {
                result += "return ";
            }

            result += "\tg_" + func.func_name + "_ORIG(\r\n";

            bFirst = true; 
            foreach (ParsedArgument arg in func.args_list)
            {
                result += "\t\t";
                if (!bFirst)
                {
                    result += ",";
                }

                result += arg.arg_name + "\r\n";

                bFirst = false;
            }

            result += "\t\t);\r\n";

            result += "}\r\n";


            // show to hook code itself

            result += "\r\n...\r\n";

            result += "void Init_" + func.func_name + "_Hook()\r\n";
            result += "{\r\n";

            //HMODULE hUser32 = LoadLibrary("user32.dll");

            //TODO: identify module for system functions

            result += "\tHMODULE hmod = LoadLibrary(\"??????.dll\")\r\n";
            result += "\tassert(hmod);\r\n";
            result += "\tif (hmod)\r\n";
            result += "\t{\r\n";

            result += "\t\tg_" + func.func_name + "_ORIG = (" + func.func_name + "_FPTR) GetProcAddress(hmod,\"" + func.func_name + "\");\r\n";
            result += "\t\tassert(g_" + func.func_name + "_ORIG);\r\n";

            result += "\t\tif (g_" + func.func_name + "_ORIG)\r\n";

            result += "\t\t{\r\n";
            //BOOL hook_res = Mhook_SetHook((PVOID*) &g_MessageBoxA_Orig, MessageBoxA_Detour);
            result += "\t\t\t BOOL hook_res = Mhook_SetHook((PVOID*) &g_" + func.func_name + "_Orig, " + func.func_name + "_Detour);\r\n";
            result += "\t\t\t assert(hook_res);\r\n";



            result += "\t\t}\r\n";

            result += "\t}\r\n";

            result += "}\r\n";


            result += "\r\n...\r\n";
           

            return result;
        }

        public string generate_function_code_MemberFunction(ParsedFunc func)
        {
            string result = "\t";

            result += func.return_type + " ";
            result += func.func_name + " ";
            result += "(";

            bool bFirst = true;

            foreach (ParsedArgument arg in func.args_list)
            {
                if (!bFirst)
                {
                    result += ", ";
                }

                result += arg.arg_type;
                result += arg.arg_name;

                if (bFirst)
                {
                    bFirst = false;
                }
            }

            result += ")\r\n";
            result += "\t{ \r\n";
            result += "\t\t";

            if (!func.return_type.Contains("void"))
            {
                result += "return ";
            }

            result += "m_pOrig->" + func.func_name + "(\r\n";

            bFirst = true;
            foreach (ParsedArgument arg in func.args_list)
            {
                if (!bFirst)
                {
                    result += ",\r\n\t\t\t";
                } else
                {
                    result += "\t\t\t";
                }

                result += arg.arg_name;

                if (bFirst)
                {
                    bFirst = false;
                }
            }

            result += "\r\n\t\t);\r\n";
            result += "\t}\r\n";

            return result;
        }

        public string build_class_code(string class_name)
        {
            string res = build_class_code_helper(class_name, 0);
            return res;
        }

        private string build_class_code_helper(string class_name, int depth)
        {
            string result = "";
            //first step - output the entire class declaration

            if (0 == depth)
            {
                result += "/////////////// Hookit - Copyright (C) Yoel Shoshan - yoelshoshan at gmail.com\r\n";
                result += "class "+class_name+"_Wrapper : public "+class_name+"\r\n";
                result += "{\r\n";
                result += "\t"+class_name + " *m_pOrig;\r\n";

                //constructor
                result += "\t" + class_name + "_Wrapper("+ class_name+" *pOrig )\r\n";
                result += "\t{\r\n";
                result += "\t\tm_pOrig = pOrig;\r\n";
                result += "\t}\r\n";

                //destructor
                result += "\tvirtual ~" + class_name + "_Wrapper(" + class_name + " *pOrig )\r\n";
                result += "\t{\r\n";
                result += "\t\tm_pOrig = NULL;\r\n";
                result += "\t}\r\n";
            }
                        
            //foreach (KeyValuePair<String, int> entry in classes)
            if (!m_ClassDeclarationLocations.ContainsKey(class_name))
            {
                return "Error! class [" + class_name + "] Not found in class defenitions map!\r\n";
            }

            int class_def_start_pos = m_ClassDeclarationLocations[class_name];

            m_MainTokenizer.m_pos = class_def_start_pos;

            int scope_depth = 0;

            string tok;

            bool reached_end = false;

            bool first = true;
            bool first_after_main_scope_start = true;

            string parent = "";

            bool func_decls_start = false;

            while (true)
            {
                if (func_decls_start)
                {
                    ParsedFunc func = parse_func();                    
                    if (null == func)
                    {
                        break;
                    }
                    result += generate_function_code_MemberFunction(func) + "\r\n";
                    continue;
                }

                tok = m_MainTokenizer.NextToken();

                if ("{" == tok)
                {
                    scope_depth++;
                }
                else if ("}" == tok)
                {
                    scope_depth--;
                    if (0 == scope_depth)
                    {
                        reached_end = true;
                        break;
                    }
                }
                else
                {
                    if (first)
                    {
                        if ("public" == tok || "private" == tok)
                        {
                            parent = m_MainTokenizer.NextToken();
                            if (":" == parent) // no inheritence case
                            {
                                parent = "";
                            }
                        }

                        first = false;
                        continue;
                    }

                    if (first_after_main_scope_start && scope_depth > 0)
                    {
                        if ("public" == tok || "private" == tok)
                        {
                            tok = m_MainTokenizer.NextToken();
                            if (":" != tok)
                            {
                                Debug.Print("Error! expected :\n");
                            }
                        }

                        first_after_main_scope_start = false;
                        func_decls_start = true; 
                        continue;
                    }

                    // member function declarations

                    func_decls_start = true;                                     
                }

            }

            /*if (!reached_end)
            {
                Debug.Print("Error! build_class_code::reached end without main function scope closing - } \n");
            }*/

            //string dbg = "";
            //dbg += m_text.Substring(class_def_start_pos,m_pos - class_def_start_pos);

            if (parent != "")
            {
                result += build_class_code_helper(parent, depth+1);
            }


            if (0 == depth)
            {
                result += "};\r\n";
              
            }

            return result;

        }

        public void FindAllClassDeclarations()
        {
            m_MainTokenizer.reset();

            string tok;

            bool class_started = false;
            bool class_declaration_started = false;
            bool class_ended = false;
            //bool found_class_name = false;

            string prev = "";

            int scope_level = 0;

            int inside_class_on_level = -1000;

            while (true)
            {
                tok = m_MainTokenizer.NextToken();

                if ("IUnknown" == tok)
                //if ("IDXGISwapChain" == tok)
                {
                    int d = 0;
                }

                //Debug.Print(tok);
                if (null == tok)
                {
                    break;
                }

                if (class_started)
                {
                    if ("{" == tok)
                    {
                        class_declaration_started = true;
                        Debug.Print("Code definition started for class " + prev + " \n");
                        scope_level++;
                        Debug.Print("scope_level=" + scope_level.ToString());
                    }
                    else if ("}" == tok)
                    {
                        class_started = false;
                        class_declaration_started = false;
                        Debug.Print("Code definition ended.\n");
                        scope_level--;
                        Debug.Print("scope_level=" + scope_level.ToString());

                        if (scope_level == inside_class_on_level)
                        {
                            inside_class_on_level = -1000;
                            Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                        }

                        if (scope_level < 0)
                        {
                            int d = 0;
                        }
                    }
                    else if (":" == tok)
                    {
                        class_declaration_started = true;
                        Debug.Print("Code definition started for class " + prev + " \n");
                    }
                    else if (0 == scope_level && "(" == tok)
                    {
                        class_started = false;
                        class_declaration_started = false;
                        continue;
                    }
                    else if (0 == scope_level && ")" == tok)
                    {
                        class_started = false;
                        class_declaration_started = false;
                        continue;
                    }

                    if (";" == tok)
                    {
                        // we do not have class declaration (because we should have encountered '{' before a ';')
                        class_started = false;
                        class_declaration_started = false;
                        inside_class_on_level = -1000;
                        Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                        //scope_level = 0;
                    }
                    else if (
                        (class_declaration_started && ":" == tok) ||
                        (class_declaration_started && "{" == tok))
                    {
                        //found_class_name = true;
                        if (":" == tok) //inheritance 
                        {
                            if ("struct" == prev)
                            {
                                class_started = false;
                                class_declaration_started = false;
                                inside_class_on_level = -1000;
                                Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                                continue;
                            }

                            if (")" == prev)
                            {
                                class_started = false;
                                class_declaration_started = false;
                                inside_class_on_level = -1000;
                                Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                                continue;
                            }

                            m_ClassDeclarationLocations.Add(prev, m_MainTokenizer.m_pos);

                            Debug.Print("Code defenition added for class " + prev + " at location " + m_MainTokenizer.m_pos.ToString() + " \n");

                            tok = m_MainTokenizer.NextToken();
                            tok = m_MainTokenizer.NextToken();
                            Debug.Print("   \tInherits from " + tok + "\n");

                            class_declaration_started = false;
                            class_started = false;

                        }
                        else if ("{" == tok) //no inheritence
                        {
                            if ("struct" == prev)
                            {
                                class_started = false;
                                class_declaration_started = false;
                                inside_class_on_level = -1000;
                                Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                                continue;
                            }

                            if (")" == prev)
                            {
                                class_started = false;
                                class_declaration_started = false;
                                inside_class_on_level = -1000;
                                Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                                continue;
                            }

                            m_ClassDeclarationLocations.Add(prev, m_MainTokenizer.m_pos);

                            Debug.Print("Code defenition added for class " + prev + " at location " + m_MainTokenizer.m_pos.ToString() + "\r\n");
                            class_started = false;
                        }

                    }
                }
                else
                {
                    if ("{" == tok)
                    {
                        scope_level++;
                        Debug.Print("scope_level=" + scope_level.ToString());
                    }
                    else if ("}" == tok)
                    {
                        scope_level--;
                        Debug.Print("scope_level=" + scope_level.ToString());

                        if (scope_level == inside_class_on_level)
                        {
                            inside_class_on_level = -1000;
                            Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                        }

                        if (scope_level < 0)
                        {
                            int d = 0;
                        }
                    }
                }


                if (-1000 == inside_class_on_level && ("class" == tok || "struct" == tok))
                {
                    //TODO: consider what if I'm already inside a class/struct
                    if (class_started)
                    {
                        Debug.Print("Error: class encountered inside class declaration. Not suported yet.\n");
                    }

                    class_started = true;

                    inside_class_on_level = scope_level;
                    Debug.Print("inside_class_on_level=" + inside_class_on_level.ToString());
                }


                prev = tok;
            }
        }

        public string build_global_functions_hook()
        {
            string res = "";

            //res += "Functions!!!!\r\n";

            m_MainTokenizer.reset();

            ParsedFunc func = null;

            while (true)
            {
                func = parse_func();
                if (null == func)
                    break;

                res+=generate_function_code_GlobalFunction(func);
                res += "\r\n";
            }


            //res += generate_function_code_MemberFunction(func) + "\r\n";
            

            return res;
        }

        //TODO: in the case of class declaration, give a warning if no "#line 187" is used.
        // also inform about how to output the ".i" intermediate files from the compiler.
        public SortedDictionary<string, int> build_class_db()
        {
            FindAllClassDeclarations();           

            return m_ClassDeclarationLocations;
        }
                
        private static readonly char[] end_of_part = ";".ToCharArray();
        private static readonly char[] inheritence_start = ":".ToCharArray();
        private static readonly char[] scope_start = "{".ToCharArray();
        private static readonly char[] scope_end = "}".ToCharArray();

    }
}
