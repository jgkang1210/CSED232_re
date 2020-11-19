#include <iostream>
#include <windows.h>
#pragma execution_character_Set("utf-8")

int main() {
	SetConsoleOutputCP(65001);
	std::cout << "한글" << "příšerně" << std::endl;
}