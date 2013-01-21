using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace HookGenerator
{
    class Tokenizer
    {
        string m_text;
        public int m_pos;

        public Tokenizer(string text)
        {
            m_text = text;
            m_pos = 0;
        }

        public void reset()
        {
            m_pos = 0;
        }

        private bool IsWhiteSpace(char c)
        {
            if (c <= 32)
                return true;
            return false;
        }

        //private char [] m_symbols = new char[] { '=', '+', '-', '/', ',', '.', '*', '~', '!', '@', '#', '$', '%', '^', '&', '(', ')', '{', '}', '[', ']', ':', ';', '<', '>', '?', '|', '\\' };
        private char[] m_symbols = new char[] { '=', '+', '-', '/', ',', '.', '*', '!', '@', '#', '$', '%', '^', '&', '(', ')', '{', '}', '[', ']', ':', ';', '<', '>', '?', '|', '\\' };

        private bool IsSymbol(char c)
        {
            for (int i = 0; i < m_symbols.Length; i++)
            {
                if (c == m_symbols[i])
                    return true;
            }

            return false;
        }

        public string NextToken()
        {
            if (m_pos == m_text.Length)
            {
                return null;
            }

            // skip white
            while (m_pos != m_text.Length && IsWhiteSpace(m_text[m_pos]))
            {
                m_pos++;
            }

            if (m_pos == m_text.Length)
            {
                //string ended before non white-space character appeared
                return null;
            }

            int start = m_pos;

            bool bFirst = true;


            // read token
            while ((m_pos != m_text.Length) && !IsWhiteSpace(m_text[m_pos]))
            {

                if (!bFirst && IsSymbol(m_text[m_pos]))
                    break;

                m_pos++;

                if (bFirst && IsSymbol(m_text[m_pos - 1]))
                    break;

                bFirst = false;
            }

            int end = m_pos;

            //memcpy(pFillMe,start,end-start);
            //pFillMe[end-start] = NULL;

            string res = m_text.Substring(start, end - start);
            string next = "";

            if ("__declspec" == res)
            {
                next = NextToken();
                res += next;
                if (next != "(")
                {
                    Debug.Print("Error! expected ( token after __declspec\r\n");
                }

                int scope = 1;
                string tok = "";
                while (scope != 0)
                {

                    tok = NextToken();
                    res += tok;
                    if ("(" == tok)
                    {
                        scope++;
                    }
                    else if (")" == tok)
                    {
                        scope--;
                    }
                }
            }

            string [] convert_from  = {  "WINAPI",   "WINAPIV",  "APIENTRY", "APIPRIVATE",   "PASCAL" };
            string[] convert_to = { "__stdcall", "__cdecl", "__stdcall", "__stdcall", "__stdcall" };

            int count = convert_from.Length;

            for (int i=0;i<count;i++)
            {
                if (convert_from[i] == res)
                {
                    return convert_to[i];
                }                
            }         

            return res;
        }
    }
}
