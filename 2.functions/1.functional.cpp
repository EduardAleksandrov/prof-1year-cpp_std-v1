#include <iostream>
#include <functional>
#include <string>

using namespace std;

string fun(string s)
{
    return s;
}

string (*funcPtr)(string);

int main()
{
    function<string(string)> f = fun;
    cout << f("Hello") << endl;

    f = [](string d){return d;};
    cout << f("Hi") << endl;

    funcPtr = fun;
    f = funcPtr;
    cout << f("You to") << endl;
 
    return 0;
}