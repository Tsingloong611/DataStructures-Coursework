/*
* 编写时间：2024-9-20
* 程序版本：v1.0
* 开发者：xx
* 
* 程序功能：实现链栈的初始化、判断是否为空、通过数组入栈、通过元素入栈、出栈、展示栈、销毁栈、升序排序
* 输入：用户输入操作选项
* 输出：根据用户操作选项输出相应结果
*/
#include"LinkStNode.h"

int main() {
	LinkStNode* q = NULL;
	ElemType e = '\0';
	std::vector<ElemType> arr = { '\0' };

	int option = 0;
	while (true)
	{
		std::cout << "========请选择操作========\n\t1. 初始化栈\n\t2. 判断栈是否为空\n\t3. 通过数组入栈\n\t4. 通过元素入栈\n\t5. 出栈\n\t6. 展示栈\n\t7. 销毁栈\n\t8. 升序排序\n=====输入 -1 退出程序=====" << std::endl;;
		std::cin >> option;
		switch (option)
		{
		case 1: {
			InitStack(q);
			std::cout << "栈已初始化。" << std::endl;
			break;
		}
		case 2: {
			if (!StackEmpty(q)) {
				std::cout << "栈不为空。" << std::endl;
			}
			else {
				std::cout << "栈为空。" << std::endl;
			};
			break;
		}
		case 3: {
			  int count = 0;
			  std::cout << "请输入数组元素个数：";
			  std::cin >> count;
			  arr.clear();
			  for (int i = 0; i < count; i++) {
				  std::cout << "请输入第" << i + 1 << "个元素：";
				  std::cin >> e;
				  arr.push_back(e);
			  }
			  PushByArr(q, arr);
			  break;
		}
		case 4: {
			std::cout << "请输入要入栈的元素：";
			std::cin >> e;
			PushByEle(q, e);
			break;
		}
		case 5: {
			ElemType e = '\0';
			if (Pop(q, e)) {
				std::cout << "栈顶元素： " << e << " 已出栈" << std::endl;
			}
			else {
				std::cout << "栈为空，无法出栈。" << std::endl;
			}
			break;
		}
		case 6: {
			std::cout << "栈展示：";
			DispStack(q);
			break;
		}
		case 7: {
			DestroyStack(q);
			std::cout << "栈已销毁。" << std::endl;
			break;
		}
		case 8: {
			SortUpOrder(q);
			std::cout << "栈已升序排序。" << std::endl;
			break;
		}
		case -1:{
			std::cout << "程序已退出。" << std::endl;
			return 0;
		}
		default: {
			std::cout << "指令错误。" << std::endl;
			break;
		}
		}
	}
	return 0;
}