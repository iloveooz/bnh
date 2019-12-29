#include "MyGen.h"

MyGen::MyGen(int a, int b) : gen_(time(nullptr)), rand_(a, b) {};

int MyGen::next() {
	return rand_(gen_);
}