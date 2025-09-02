#include <iostream>
#include <vector>
#include <ranges>

int main(){
    std::vector numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto odd_numbers = numbers | std::views::filter([](int n){ return n % 2 == 1; }); 
    for (int n : odd_numbers)
        std::cout << n <<"‘,’";

    std::cout << "\n"; 
    if (__cplusplus == 202302L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";
}

