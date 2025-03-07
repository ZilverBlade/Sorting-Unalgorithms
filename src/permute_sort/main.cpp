#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <cstdint>
#include <cstddef>
#include <cassert>

int permute_sort(std::vector<int>& in) {
    int permutations = 0;

    bool unsorted;
    do {
        unsorted = false;
        for (int i = 0; i < in.size() - 1; ++i) {
            if (in[i] > in[i+1]) {
                unsorted = true;
                break;
            }
        }
        if (!unsorted) break;
        ++permutations;
    } while (std::next_permutation(in.begin(), in.end()));
    
    return permutations;
}

int main() {
    std::vector sampleArray = { 1, 8, 2, 0, 2, 3 };
    std::cout << "To sort:\n";
    std::cout << "[ ";
    for (auto& i : sampleArray) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    int permutes = permute_sort(sampleArray);

    std::cout << "Done in " << permutes << " permutations\n";
    std::cout << "[ ";
    for (auto& i : sampleArray) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";
}