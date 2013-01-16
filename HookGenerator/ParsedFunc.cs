using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HookGenerator
{
    class ParsedFunc
    {
        public ParsedFunc()
        {
        }

        public string return_type;
        public string func_name;
        public List<ParsedArgument> args_list;
    }
}
