#include <commons/timer.h>
#include <algorithm>

static int permutations = 0;
void permute_sort(std::vector<integer_type>& in) {
    permutations = 0;
    bool unsorted;
    do {
        unsorted = false;
        for (int i = 0; i < in.size() - 1; ++i) {
            if (in[i] > in[i + 1]) {
                unsorted = true;
                break;
            }
        }
        if (!unsorted) break;
        ++permutations;
    } while (std::next_permutation(in.begin(), in.end()));

}

int main() {
    std::vector sampleArray = { 9, 5, 420, 69, 41, 777, 115, 117, 1984 };

    profile_sorting(sampleArray, permute_sort);

    std::cout << "Sorted after " << permutations << " permutations" << std::endl;
}