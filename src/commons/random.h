#pragma once
#include <random>
size_t generate_uniform_random() {
	static std::random_device UUID_randomDevice;
	static std::mt19937_64 UUID_engine(UUID_randomDevice());
	static std::uniform_int_distribution<size_t> UUID_uniformDistribution;

	return UUID_uniformDistribution(UUID_engine);
}