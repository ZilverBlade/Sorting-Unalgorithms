#include <commons/timer.h>
#include "gym.h"

static gym basic_fit_netherlands;

void muscle_sort(std::vector<integer_type>& in) {
    for (size_t i = 1; i < in.size(); ++i) {
        if (in[i - 1] > in[i]) {
            basic_fit_netherlands.workout(in[i], in[i - 1]);
        }
    }
}

int main() {
    std::vector sampleArray = { 529, 1192, 0, 35, 12, -6, 134, 293, 0, 2193, 5, 21, 6, 21, 724, 632, 3, 67, 8 };
    profile_sorting(sampleArray, muscle_sort);
}