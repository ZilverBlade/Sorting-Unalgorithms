#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <atomic>
#include <thread>
#include <cstdint>
#include <cstddef>
#include <cassert>

int parallel_bogo_sort(std::vector<int>& in) {
    std::atomic_bool bSorted = false;
    bool unsorted = false;
    for (int i = 0; i < in.size() - 1; ++i) {
        if (in[i] > in[i + 1]) {
            unsorted = true;
            break;
        }
    }
    if (!unsorted) {
        bSorted = true;
    }
    if (!bSorted) {
        std::vector<int> copyL = in;
        std::vector<int> copyR = in;
        std::thread left([&copyL]() {

        });
        std::thread right([&copyR]() {

        });
    }
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