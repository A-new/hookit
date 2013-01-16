using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HookGenerator
{
    class ParsedArgument
    {
        public ParsedArgument()
        {
        }

        public string arg_type;
        public string arg_name; //TODO: consider cases that there is no arg_name
    }
}
