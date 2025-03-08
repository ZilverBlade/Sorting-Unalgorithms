#include <unordered_map>
#include <commons/timer.h>
#include <algorithm>

// Space complexity (L = array length, X = num digits)
// O(sigma(n = L, i = 0)(X^i))
// ~400 MB of data
constexpr size_t MAX_ARRAY_LENGTH = 10;
constexpr int64_t MIN_ARRAY_VALUE = 0;
constexpr int64_t MAX_ARRAY_VALUE = MAX_ARRAY_LENGTH - 1;

struct hashable_list {
    hashable_list(const std::vector<integer_type>& l) : list(l) {};

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

static std::unordered_map<hashable_list, std::vector<integer_type>> lut;

std::vector<std::vector<integer_type>> permute(std::vector<integer_type> in) {
    if (in.empty()) return { {} };
    std::vector<std::vector<integer_type>> result = {};
    result.push_back(in);
    while (std::next_permutation(in.begin(), in.end())) {
        result.push_back(in);
    }
    return result;
}

void generate_lookup_table() {
    std::vector<std::pair<std::vector<integer_type>, std::vector<std::vector<integer_type>>>> matrix;

    for (int i = 0; i < MAX_ARRAY_LENGTH; ++i) {
        std::cout << "Generting permutation with array length = " << i << std::endl;
        matrix.push_back({});
        for (int j = MIN_ARRAY_VALUE; j <= i; ++j) {
            matrix[i].first.push_back(j);
        }
        matrix[i].second = permute(matrix[i].first);
        for (auto x : matrix[i].second) {
            lut[x] = matrix[i].first;
        }
    }
}

void lookup_sort(std::vector<integer_type>& list) {
    auto it = lut.find(list);
    if (it == lut.end()) {
        throw std::runtime_error("Illegal array");
    }
    list = it->second;
}

int main() {
    generate_lookup_table();

    std::vector sampleArray = { 8, 3, 6, 5, 2, 4, 1, 0, 7 };
    profile_sorting(sampleArray, lookup_sort);

    std::cout << "lookup from array with " << lut.size() << " entries";
}