#include <commons/timer.h>

void vacuous_sort(std::vector<integer_type>& in) {
    in.clear();
}

int main() {
    std::vector sampleArray = { 529, 1192, 0, 35, 12, -6, 134, 293, 0, 2193, 5, 21, 6, 21, 724, 632, 3, 67, 8 };

    profile_sorting(sampleArray, vacuous_sort);
}