/* 实验3 （1,2整合版）
* 版本号： 0.1
* 开发者： 陈铠
* 日期： 2024.9.15
* 说明： 本程序实现了循环链表和单链表求交集的功能
* 
* 基本功能：
* 1. 循环链表
* 2. 单链表求交集
* 
* 改进：
* 1. 优化了代码结构，将循环链表和单链表的操作分别放在了两个命名空间中，将一些重复的代码提取出来，放在了Common命名空间中
* 2. 优化了程序鲁棒性，增加了一些异常处理机制
* 3. 优化了兼容性，同时兼容手动赋值与使用默认值操作
*/
#include"LinkList.h"

int main() {
	while(true){
		std::cout << "============ 请输入对应值以进行操作 ============\n\t1.循环链表\n\t2.单链表求交集" << std::endl;
		int option = 0;
		DList::CheckInput(option, "=============== 输入 -1 退出程序 ===============");
		if (option == 1) {
			DList::menu();
		}
		else if (option == 2) {
			SList::menu();
		}
		else if (option == -1) {
			std::cout << "Exit Successfully" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid input, please input again" << std::endl;
		}
	}
	return 0;
}