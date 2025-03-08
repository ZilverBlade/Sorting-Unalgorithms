#include "gym.h"

void gym::workout(volatile integer_type& dude, volatile integer_type target) {
	while (!(++dude > target)) {}
}