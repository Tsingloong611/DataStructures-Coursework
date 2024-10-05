#pragma once
#include<iostream>
#include<string>
namespace EH {
	template <typename T>
	void CheckInput(T& input, const char* str) {
		std::cout << str << std::endl;
		while (true) {
			if (std::cin >> input) {
				if (std::cin.peek() != '\n') {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "错误：输入包含额外字符, 需要 " << typeid(T).name() << " ,请重新输入" << std::endl;
				}
				else {
					system("cls");
					std::cout << "输入成功: " << typeid(T).name() << " " << input << std::endl;
					return;
				}
			}
			else {
				std::cin.clear();
				std::string msg;
				std::getline(std::cin, msg);
				std::cout << "错误的输入 " << msg << " 需要 " << typeid(T).name() << " 请重新输入" << std::endl;
			}
		}
	}
}
