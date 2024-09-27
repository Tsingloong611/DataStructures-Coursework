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
					std::cout << "����������������ַ�, ��Ҫ " << typeid(T).name() << " ,����������" << std::endl;
				}
				else {
					system("cls");
					std::cout << "����ɹ�: " << typeid(T).name() << " " << input << std::endl;
					return;
				}
			}
			else {
				std::cin.clear();
				std::string msg;
				std::getline(std::cin, msg);
				std::cout << "��������� " << msg << " ��Ҫ " << typeid(T).name() << " ����������" << std::endl;
			}
		}
	}
}
