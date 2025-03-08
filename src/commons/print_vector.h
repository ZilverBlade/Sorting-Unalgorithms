#pragma once
#include "integer.h"
#include <iostream>
#include <vector>

void print_vector(const std::vector<integer_type>& vector) {
	std::cout << "[ ";
    bool bFirst = true;
    for (auto& i : vector) {
        if (!bFirst) {
            std::cout << ", ";
        } else {
            bFirst = false;
        }
        std::cout << i;
    }
    std::cout << " ]\n";
}