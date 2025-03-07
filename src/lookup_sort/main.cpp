#include <iostream>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <cstdint>
#include <cstddef>

// serialiser
#include <nlohmann/json.hpp>
// deserialiser
#include <simdjson/simdjson.h>

// ~400 MB of data
constexpr size_t MAX_ARRAY_LENGTH = 9;
constexpr int64_t MIN_ARRAY_VALUE = 0;
constexpr int64_t MAX_ARRAY_VALUE = 8;

using integer_type = int8_t;

struct hashable_list {
	std::vector<integer_type> list;
	bool operator==(const hashable_list& other) const {
		return std::equal(list.begin(), list.end(), other.list.begin(), other.list.end());
	}
};
namespace std {
    template <>
    struct std::hash<hashable_list> {
        std::size_t operator()(const hashable_list& k) const {
            static std::hash<integer_type> hasher;
            size_t seed = k.list.size();
            for (size_t i = 0; i < k.list.size(); ++i) {
                seed ^= -i + hasher(k.list[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}

int factorial(int n) {
    int counter = n;
    int mul = 1;
    while (counter-- > 1) {
        mul *= n;
    }
    return mul;
}

static std::unordered_map<hashable_list, std::vector<integer_type>> lut;

std::vector<std::vector<integer_type>> permute(const std::vector<integer_type>& in) {
    std::vector<std::vector<integer_type>> result = {};
    result.push_back(in);
    while (std::next_permutation(in.begin(), in.end())) {
        result.push_back(in);
    }
    return result;
}

void init_lookup_sort(std::filesystem::path lookup_path) {

}
void generate_lookup_table(std::filesystem::path output_path) {
    std::vector<std::pair<std::vector<integer_type>, std::vector<std::vector<integer_type>>>> matrix;

    for (int i = 0; i <= MAX_ARRAY_LENGTH; ++i) {
        matrix.push_back({});
        for (int j = MIN_ARRAY_VALUE; j <= MAX_ARRAY_VALUE; ++j) {
            matrix[i].first.push_back(j);
        }
        matrix[i].second = permute(matrix[i].first);
    }

}

void lookup_sort(const std::vector<int8_t>& list) {

}

int main() {
    generate_lookup_table("data/lookup_sort/table.json");

}