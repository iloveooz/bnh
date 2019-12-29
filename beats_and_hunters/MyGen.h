#pragma once
#include <random>
#include <ctime>

class MyGen {
public:
	MyGen(int a, int b);
	int next();
private:
	std::mt19937 gen_;
	std::uniform_int_distribution<> rand_;
};