#pragma once
#include <chrono>
#include <functional>
#include "print_vector.h"

void profile_sorting(std::vector<integer_type> input, std::function<void(std::vector<integer_type>&)> sorting_algorithm) {
    std::cout << "To sort:\n";
    print_vector(input);

    auto initial = std::chrono::high_resolution_clock::now();
    sorting_algorithm(input);
    auto final = std::chrono::high_resolution_clock::now();
    
    double time_ms = std::chrono::duration<double, std::chrono::milliseconds::period>(final - initial).count();
    std::cout << "Sorted in " << time_ms << "ms:\n";
    print_vector(input);
}