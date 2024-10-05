/*
* ��дʱ�䣺2024/9/5
* ����汾��V1.0
* �����ߣ�xx
*
* �����ܣ����Ա�Ļ�������
* �������ݣ��û���������
* ����������Ļ��ʾ���Ա�Ļ����������
*/
#include<iostream> // ����ͷ�ļ�
#include"table.h" // ����ͷ�ļ�
using namespace std; // ʹ�ñ�׼�����ռ�

int main() {
	SqList* L = NULL; // ��ʼ�����Ա�ָ��
	bool loop = true; // ѭ����־

	while (loop)
	{
		int option = 0; // ѡ�����
		CheckInput(option, "==============�������Ӧ������ִ�в���==============\n\t1.��ʼ��˳���L\n\t2.�ݻ�˳���L\n\t3.���β���Ԫ�� a,b,c,d,e\n\t4.��ָ����������Ԫ��\n\t5.ɾ��ָ������Ԫ��\n\t6.ɾ��ָ������Ԫ��\n\t7.���˳���L\n\t8.���˳���L�ĳ���\n\t9.�ж�˳���L�Ƿ�Ϊ��\n\t10.���˳���L�ĵ� i ��Ԫ��\n\t11.���˳���L��ָ��Ԫ�ص��׸�����\n\t12.��ȡ˳�����Ԫ�أ���˹���룩���ֵ\n===================����-1�˳�����===================");
		system("cls"); // ����
		switch (option)
		{
		case 1:{
			InitList(L);
			cout << "��ʼ�����" << endl;
			break;
		}
		case 2: {
			DestroyList(L);
			cout << "�ݻ����" << endl;
			break;
		}
		case 3: {
			CheckList(L);
			InsertByOrder(L);
			cout << "�������" << endl;
			break;
		}
		case 4: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "������Ҫ�����λ�ã�");
			CheckInput(e, "������Ҫ�����Ԫ�أ�");

			if (AddElemByOrder(L, e, i))
			{
				cout << "����ɹ�" << endl;
			}
			else {
				cout << "����ʧ��" << endl;
			}
			break;
		}
		case 5: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "������Ҫɾ��Ԫ�ص�������");

			if (DeleteElemByOrder(L, e, i)) {
				cout << "λ�� " << i << "����Ԫ�� " << e << " �ѱ�ɾ��" << endl;
			}
			else {
				cout << "ɾ��ʧ��" << endl;
			}
			break;
		}
		case 6: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(e, "������Ҫɾ��Ԫ�ض���");

			if (DeleteElemByObj(L, e, i)) {
				cout << "λ�� " << i << "����Ԫ�� " << e << " �ѱ�ɾ��" << endl;
			}
			else {
				cout << "ɾ��ʧ��" << endl;
			}
			break;
		}
		case 7: {
			CheckList(L);
			cout << "���Ա��������: " << endl;
			ShowList(L);
			break;
		}
		case 8: {
			CheckList(L);
			cout << "˳���ĳ����ǣ�" << GetListLength(L) << endl;
			break;
		}
		case 9: {
			CheckList(L);
			if (IsEmpty(L)) {
				cout << "���Ա��ǿ�" << endl;
			}
			else {
				cout << "���Ա��ǿյ�" << endl;
			}
			break;
		}
		case 10: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "������������");

			if (GetElemByOrder(L, e, i)) {
				cout << "���Ա��" << i << "��Ԫ���ǣ�" << e << endl;
			}
			else {
				cout << "������������ֵ�Ƿ���ȷ" << endl;
			}
			break;
		}
		case 11: {
			ElemType e;
			CheckList(L);
			CheckInput(e, "������Ԫ�أ�");

			int result = GetFirstOrderByElem(L, e);

			if (result != 0) {
				cout << "Ԫ�� " << e << " �״γ��ֵ�����ֵ�ǣ�" << result << endl;
			}
			else {
				cout << "���޴�Ԫ��" << endl;
			}
			break;
		}
		case 12: {
			ElemType max;
			int i = 0;
			CheckList(L);
			if (GetMaxElem(L, max, i)) {
				cout << "��˳��������ֵΪ��" << max << " ��λ�ڵ� " << i << " λ" << endl;
			}
			else {
				cout << "�޷���ȡ" << endl;
			}
			break;
		}

		case -1: {
			loop = false; // �˳�ѭ��
			DestroyList(L); // �ͷ��ڴ�
			break;
		}
		default:
			cout << "������������ԣ�" << endl;
			break;
		}
	}
	return 0;
}