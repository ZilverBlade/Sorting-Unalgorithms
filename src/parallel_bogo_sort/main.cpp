#include <commons/timer.h>
#include <commons/random.h>
#include <thread>

void randomize_vector(std::vector<integer_type>& in) {
    for (size_t i = 0; i < in.size(); ++i) {
        std::swap(in[i], in[generate_uniform_random() % in.size()]);
    }
}

static std::atomic_int threads_launched = 0;
void parallel_bogo_sort(std::vector<integer_type>& in) {
    ++threads_launched;
    static std::atomic_bool bSorted = false;
    static std::vector<integer_type> sorted_array;
    
    bool unsorted = false;
    for (size_t i = 0; i < in.size() - 1; ++i) {
        if (in[i] > in[i + 1]) {
            unsorted = true;
            break;
        }
    }
    if (!unsorted) {
        bSorted = true;
        sorted_array = in;
        in = sorted_array;
        return;
    }
    if (!bSorted) {
        randomize_vector(in);
        std::vector copyL = in;
        std::vector copyR = in;
        std::thread left([&copyL, &in]() {
            parallel_bogo_sort(copyL);
        });
        std::thread right([&copyR, &in]() {
            parallel_bogo_sort(copyR);
        });
        if (left.joinable()) {
            left.join();
        }
        if (right.joinable()) {
            right.join();
        }
    }
    // this should only ever be reached once the vector is sorted. stack overflow otherwise!
    in = sorted_array;
}

int main() {
    // WARNING! ONLY DO WITH A SMALL VECTOR! ANY LARGE VECTORS WILL LIKELY MAKE YOUR COMPUTER HANG!
    std::vector sampleArray = { 0, 7, -2, 1, 9, 4 };
    profile_sorting(sampleArray, parallel_bogo_sort);
    std::cout << "threads launched: " << threads_launched << std::endl;
}