/* ʵ��3 ��1,2���ϰ棩
* �汾�ţ� 0.1
* �����ߣ� ����
* ���ڣ� 2024.9.15
* ˵���� ������ʵ����ѭ������͵������󽻼��Ĺ���
* 
* �������ܣ�
* 1. ѭ������
* 2. �������󽻼�
* 
* �Ľ���
* 1. �Ż��˴���ṹ����ѭ������͵�����Ĳ����ֱ���������������ռ��У���һЩ�ظ��Ĵ�����ȡ������������Common�����ռ���
* 2. �Ż��˳���³���ԣ�������һЩ�쳣�������
* 3. �Ż��˼����ԣ�ͬʱ�����ֶ���ֵ��ʹ��Ĭ��ֵ����
*/
#include"LinkList.h"

int main() {
	while(true){
		std::cout << "============ �������Ӧֵ�Խ��в��� ============\n\t1.ѭ������\n\t2.�������󽻼�" << std::endl;
		int option = 0;
		DList::CheckInput(option, "=============== ���� -1 �˳����� ===============");
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