#include"linkedqueue.h"
#include"circularqueue.h"

int main() {
	int option = 0;
	bool loop = true;
	while (loop) {
		EH::CheckInput(option, "========������Ҫִ�еĲ���========\
			\n1. ������\
			\n2. ѭ������\
			\n============����-1�˳�============");
		switch (option)
		{
		case 1: {
			LQ::Menu();
			break;
		}
		case 2: {
			CQ::Menu();
			break;
		}
		case -1: {
			loop = false;
			break;
		}
		default:
			std::cout << "δָ֪��" << std::endl;
			break;
		}
	}
	return 0;
}