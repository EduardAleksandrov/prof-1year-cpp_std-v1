#include <iostream>
#include <vector>
#include <ranges>

int main(){
    std::vector numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto odd_numbers = numbers | std::views::filter([](int n){ return n % 2 == 1; }); 
    for (int n : odd_numbers)
        std::cout << n <<"‘,’";
}

