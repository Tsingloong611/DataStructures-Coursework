#include"linkedqueue.h"
#include"circularqueue.h"

int main() {
	int option = 0;
	bool loop = true;
	while (loop) {
		EH::CheckInput(option, "========请输入要执行的操作========\
			\n1. 链队列\
			\n2. 循环队列\
			\n============输入-1退出============");
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
			std::cout << "未知指令" << std::endl;
			break;
		}
	}
	return 0;
}