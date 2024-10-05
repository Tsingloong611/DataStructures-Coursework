/*
* ��дʱ�䣺2024/9/5
* ����汾��V1.0
* �����ߣ�xx
* 
* �����ܣ����Ա�Ļ�������
* �������ݣ��û���������
* ����������Ļ��ʾ���Ա�Ļ����������
*/

#include<iostream>
using namespace std;

// ���� MAX ElemType �� SqList
#define MAX 100
typedef char ElemType;
typedef struct {
	ElemType Data[MAX];
	int length;
}SqList;

/// <summary>
/// ��ʼ�����Ա�1. �����ڴ� 2. �޸ĳ���Ϊ 0��
/// </summary>
/// <param name="L"> ���ô��ݣ����Ա�ָ������� </param>
void InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

/// <summary>
/// �ݻ����Ա�1. �ͷ��ڴ� 2. ָ���ÿգ�
/// </summary>
/// <param name="L"> ���ô��ݣ� ���Ա�ָ������� </param>
void DestroyList(SqList*& L) {
	free(L);
	L = NULL;
}

/// <summary>
/// �����Ա��β������ {'a','b','c','d','e'}
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
void InsertByOrder(SqList* L) {
	char arr[] = { 'a','b','c','d','e' };
	for (int i = 0;i < 5;i++) {
		L->Data[L->length++] = arr[i];
	}
}

/// <summary>
/// ͨ�����������Ա��в���Ԫ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="e"> ֵ���ݣ�Ҫ�����Ԫ�� </param>
/// <param name="i"> ֵ���ݣ�Ҫ��������� </param>
/// <returns> ����ֵ��true - ����ɹ�; false - ����ʧ�� </returns>
bool AddElemByOrder(SqList* L, ElemType e, int i) {
	int j = L->length;
	if (i<1 || i > L->length + 2) {
		return false;
	}
	while (j >= i) {
		L->Data[j] = L->Data[j - 1];
		j--;
	}
	L->Data[i - 1] = e;
	L->length++;
	return true;
}

/// <summary>
/// ͨ������ɾ�����Ա��е�Ԫ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="e"> ���ô��ݣ�Ԫ������, ���ڷ��ر�ɾ����Ԫ�� </param>
/// <param name="i"> ֵ���ݣ�Ҫɾ�������� </param>
/// <returns> ����ֵ, true - ɾ���ɹ��� false - ɾ��ʧ�� </returns>
bool DeleteElemByOrder(SqList* L, ElemType& e, int i) {
	int j = i;
	if (i < 1 || i> L->length) {
		return false;
	}
	e = L->Data[i - 1];
	while (j < L->length) {
		L->Data[j - 1] = L->Data[j];
		j++;
	}
	L->length--;
	return true;
}

/// <summary>
/// ͨ��Ԫ��ֵɾ�����Ա��е�Ԫ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="e"> ֵ���ݣ�Ҫɾ����Ԫ�� </param>
/// <param name="i"> ���ô��ݣ����ڷ��ر�ɾ��Ԫ�ص����� </param>
/// <returns> ����ֵ��true - ɾ���ɹ��� false - ɾ��ʧ�� </returns>
bool DeleteElemByObj(SqList* L, ElemType e, int& i) {
	int j = 0;
	while (j < L->length) {
		if (e == L->Data[j]) {
			i = j + 1;
			return DeleteElemByOrder(L, e, j + 1);
		}
		j++;
	}
	return true;
}

/// <summary>
/// ��ʾ���Ա��е�Ԫ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
void ShowList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->Data[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// ��ȡ���Ա�ĳ���
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <returns> ����ֵ���������Ա�ĳ��� </returns>
int GetListLength(SqList* L) {
	return L->length;
}

/// <summary>
/// ������Ա��Ƿ�Ϊ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <returns> ����ֵ��true - ���Ա�Ϊ�գ� false - ���Ա�ǿ� </returns>
bool IsEmpty(SqList* L) {
	if (L->length == 0) {
		return true;
	}
	return false;
}

/// <summary>
/// ͨ��������ȡ���Ա��е�Ԫ��
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="e"> ���ô��ݣ����ڷ��ػ�ȡ����Ԫ��ֵ </param>
/// <param name="i"> ֵ���ݣ�Ԫ�ص����� </param>
/// <returns> ����ֵ��true - ��ȡ�ɹ��� false - ��ȡʧ�� </returns>
bool GetElemByOrder(SqList* L, ElemType& e, int i) {
	if (i<1 || i> L->length) {
		return false;
	}
	e = L->Data[i - 1];
	return true;
}

/// <summary>
/// ͨ��Ԫ��ֵ��ȡ���Ա��е�һ��ƥ��Ԫ�ص�����
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="e"> ֵ���ݣ�Ҫƥ���Ԫ��ֵ </param>
/// <returns> ����ֵ�����ص�һ��ƥ��Ԫ�ص�����������ƥ���򷵻�0 </returns>
int GetFirstOrderByElem(SqList* L, ElemType e) {
	int n = 0;
	while (n < L->length) {
		if (L->Data[n] == e) {
			return n + 1;
		}
		n++;
	}
	return 0;
}

/// <summary>
/// ��ȡ���Ա��е����Ԫ�ؼ�������
/// </summary>
/// <param name="L"> ָ�봫�ݣ����Ա�ָ�� </param>
/// <param name="max"> ���ô��ݣ����ڷ������Ԫ�ص�ֵ </param>
/// <param name="i"> ���ô��ݣ����ڷ������Ԫ�ص����� </param>
/// <returns> ����ֵ��true - ��ȡ�ɹ��� false - ��ȡʧ�� </returns>
bool GetMaxElem(SqList* L, ElemType& max, int& i) {
	if (L->length == 0) {
		return false;
	}
	else {
		max = L->Data[0];
		i = 1;
		for (int j = 0; j < L->length;j++) {
			if (L->Data[j] > max) {
				max = L->Data[j];
				i = j + 1;
			}
		}
		return true;
	}
}

/// <summary>
/// ��� cin �����Ԫ���Ƿ���Ч (�����Ƿ�ƥ��)
/// </summary>
/// <param name="e"> ���ô��ݣ������ж� cin �����Ԫ���Ƿ�����ƥ�䲢���� </param>
/// <param name="str"> ֵ���ݣ���ʾ�ַ��� </param>
void CheckInput(ElemType& e, string str) {
	bool loop = true;
	while (loop) {
		cout << str << endl;
		string s;
		if (cin >> s) {
			if (s.length() == 1) {
				e = s[0];
				loop = false;
			}
			else {
				cout << "��������������" << endl;
				cin.clear(); // ����������Ĵ�����
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���Ի������еĴ����ַ�
			}
		}
	}
}

/// <summary>
/// �������������Ƿ���Ч
/// </summary>
/// <param name="i"> ���ô��ݣ���������� </param>
/// <param name="str"> ֵ���ݣ���ʾ�ַ��� </param>
void CheckInput(int& i, string str) {
	bool loop = true;
	while (loop) {
		cout << str << endl;
		if (cin >> i) {
			loop = false;
		}
		else {
			cout << "��������������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

/// <summary>
/// ������Ա��Ƿ���ڣ������������Զ���ʼ��
/// </summary>
/// <param name="L"> ���ô��ݣ����Ա�ָ������� </param>
void CheckList(SqList*& L) {
	if (L == NULL) {
		cout << "�б����ڻ��ѱ����٣����Զ���ʼ��" << endl;
		InitList(L);
	}
}         