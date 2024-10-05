/*
* ��дʱ�䣺2024-9-20
* ����汾��v1.0
* �����ߣ�xx
* 
* �����ܣ�ʵ����ջ�ĳ�ʼ�����ж��Ƿ�Ϊ�ա�ͨ��������ջ��ͨ��Ԫ����ջ����ջ��չʾջ������ջ����������
* ���룺�û��������ѡ��
* ����������û�����ѡ�������Ӧ���
*/
#include"LinkStNode.h"

int main() {
	LinkStNode* q = NULL;
	ElemType e = '\0';
	std::vector<ElemType> arr = { '\0' };

	int option = 0;
	while (true)
	{
		std::cout << "========��ѡ�����========\n\t1. ��ʼ��ջ\n\t2. �ж�ջ�Ƿ�Ϊ��\n\t3. ͨ��������ջ\n\t4. ͨ��Ԫ����ջ\n\t5. ��ջ\n\t6. չʾջ\n\t7. ����ջ\n\t8. ��������\n=====���� -1 �˳�����=====" << std::endl;;
		std::cin >> option;
		switch (option)
		{
		case 1: {
			InitStack(q);
			std::cout << "ջ�ѳ�ʼ����" << std::endl;
			break;
		}
		case 2: {
			if (!StackEmpty(q)) {
				std::cout << "ջ��Ϊ�ա�" << std::endl;
			}
			else {
				std::cout << "ջΪ�ա�" << std::endl;
			};
			break;
		}
		case 3: {
			  int count = 0;
			  std::cout << "����������Ԫ�ظ�����";
			  std::cin >> count;
			  arr.clear();
			  for (int i = 0; i < count; i++) {
				  std::cout << "�������" << i + 1 << "��Ԫ�أ�";
				  std::cin >> e;
				  arr.push_back(e);
			  }
			  PushByArr(q, arr);
			  break;
		}
		case 4: {
			std::cout << "������Ҫ��ջ��Ԫ�أ�";
			std::cin >> e;
			PushByEle(q, e);
			break;
		}
		case 5: {
			ElemType e = '\0';
			if (Pop(q, e)) {
				std::cout << "ջ��Ԫ�أ� " << e << " �ѳ�ջ" << std::endl;
			}
			else {
				std::cout << "ջΪ�գ��޷���ջ��" << std::endl;
			}
			break;
		}
		case 6: {
			std::cout << "ջչʾ��";
			DispStack(q);
			break;
		}
		case 7: {
			DestroyStack(q);
			std::cout << "ջ�����١�" << std::endl;
			break;
		}
		case 8: {
			SortUpOrder(q);
			std::cout << "ջ����������" << std::endl;
			break;
		}
		case -1:{
			std::cout << "�������˳���" << std::endl;
			return 0;
		}
		default: {
			std::cout << "ָ�����" << std::endl;
			break;
		}
		}
	}
	return 0;
}