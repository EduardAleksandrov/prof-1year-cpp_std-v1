// c++ program that demonstrates async
// library for std::cout
#include <iostream>
//library for std::async and std::future
#include <future>
//library for std::string
#include <string>
#include <functional>
std::string samplefunction(std::string& st, std::string& one)
{
    one = "hello";
    return "This is the output of " + st + one;
}
class SamplefunctionObject
{
public:
    std::string operator()( const std::string& st) const
    {
    return "This is the output of " + st ;
    }
};
int main()
    {
    std::cout << std::endl;
    // future with the help of function
    std::string str1 {"one"};
    std::string str2 {"two"};
    std::future<std::string> f1 = std::async(std::launch::async, samplefunction, std::ref(str2), std::ref(str1));
    
    // future with the help of function object
    SamplefunctionObject samplefunctionObject;
    auto f2= std::async(std::launch::async, samplefunctionObject,"sample function object");
    // future with the help of lambda function
    auto f3= std::async(std::launch::async, []( const std::string& st ){ return "This is the output of " + st ;}, 
                        " lambda function" );
    f1.wait();
    std::cout << str1 << "\n";
    f2.wait();
    f3.wait();
    std::cout << f1.get() << "\n" << f2.get() << "\n" << f3.get() << std::endl;
    std::cout << std::endl;
}