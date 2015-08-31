Simply drag and drop any of the following for automatic code generation:

1. Classes:
Input: C++ class definition
Output: class wrappers (support inheritence!)

2. Global Functions:
Input: C global functions declarations
Output: full hooking code (uses mhooks hooking lib)

3. Dlls
Input:DLL file
Output: proxy dll code (Only automation of "Michael Chourdakis" code from http://www.codeproject.com/Articles/16541/Create-your-Proxy-DLLs-automatically)

Disclaimer: C++ syntax parsing was hacked in less than 2 days, I do not claim this is bulletproof, and i did not base my code on GCC or any other external code/tool.
However, it has worked for me very well in 99% of the cases and saved me a lot of boring manual wrapper/proxy creation hours. =)