/*
* 编写时间：2024/9/5
* 程序版本：V1.0
* 开发者：xx
* 
* 程序功能：线性表的基本操作
* 输入数据：用户键盘输入
* 输出结果：屏幕显示线性表的基本操作结果
*/

#include<iostream>
using namespace std;

// 定义 MAX ElemType 与 SqList
#define MAX 100
typedef char ElemType;
typedef struct {
	ElemType Data[MAX];
	int length;
}SqList;

/// <summary>
/// 初始化线性表（1. 分配内存 2. 修改长度为 0）
/// </summary>
/// <param name="L"> 引用传递，线性表指针的引用 </param>
void InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

/// <summary>
/// 摧毁线性表（1. 释放内存 2. 指针置空）
/// </summary>
/// <param name="L"> 引用传递， 线性表指针的引用 </param>
void DestroyList(SqList*& L) {
	free(L);
	L = NULL;
}

/// <summary>
/// 在线性表结尾处插入 {'a','b','c','d','e'}
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
void InsertByOrder(SqList* L) {
	char arr[] = { 'a','b','c','d','e' };
	for (int i = 0;i < 5;i++) {
		L->Data[L->length++] = arr[i];
	}
}

/// <summary>
/// 通过索引在线性表中插入元素
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="e"> 值传递，要插入的元素 </param>
/// <param name="i"> 值传递，要插入的索引 </param>
/// <returns> 布尔值，true - 插入成功; false - 插入失败 </returns>
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
/// 通过索引删除线性表中的元素
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="e"> 引用传递，元素引用, 用于返回被删除的元素 </param>
/// <param name="i"> 值传递，要删除的索引 </param>
/// <returns> 布尔值, true - 删除成功； false - 删除失败 </returns>
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
/// 通过元素值删除线性表中的元素
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="e"> 值传递，要删除的元素 </param>
/// <param name="i"> 引用传递，用于返回被删除元素的索引 </param>
/// <returns> 布尔值，true - 删除成功； false - 删除失败 </returns>
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
/// 显示线性表中的元素
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
void ShowList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->Data[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// 获取线性表的长度
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <returns> 整型值，返回线性表的长度 </returns>
int GetListLength(SqList* L) {
	return L->length;
}

/// <summary>
/// 检查线性表是否为空
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <returns> 布尔值，true - 线性表为空； false - 线性表非空 </returns>
bool IsEmpty(SqList* L) {
	if (L->length == 0) {
		return true;
	}
	return false;
}

/// <summary>
/// 通过索引获取线性表中的元素
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="e"> 引用传递，用于返回获取到的元素值 </param>
/// <param name="i"> 值传递，元素的索引 </param>
/// <returns> 布尔值，true - 获取成功； false - 获取失败 </returns>
bool GetElemByOrder(SqList* L, ElemType& e, int i) {
	if (i<1 || i> L->length) {
		return false;
	}
	e = L->Data[i - 1];
	return true;
}

/// <summary>
/// 通过元素值获取线性表中第一个匹配元素的索引
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="e"> 值传递，要匹配的元素值 </param>
/// <returns> 整型值，返回第一个匹配元素的索引，若无匹配则返回0 </returns>
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
/// 获取线性表中的最大元素及其索引
/// </summary>
/// <param name="L"> 指针传递，线性表指针 </param>
/// <param name="max"> 引用传递，用于返回最大元素的值 </param>
/// <param name="i"> 引用传递，用于返回最大元素的索引 </param>
/// <returns> 布尔值，true - 获取成功； false - 获取失败 </returns>
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
/// 检查 cin 输入的元素是否有效 (类型是否匹配)
/// </summary>
/// <param name="e"> 引用传递，用于判断 cin 输入的元素是否类型匹配并返回 </param>
/// <param name="str"> 值传递，提示字符串 </param>
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
				cout << "输入有误，请重试" << endl;
				cin.clear(); // 清除输入流的错误标记
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略缓冲区中的错误字符
			}
		}
	}
}

/// <summary>
/// 检查输入的索引是否有效
/// </summary>
/// <param name="i"> 引用传递，输入的索引 </param>
/// <param name="str"> 值传递，提示字符串 </param>
void CheckInput(int& i, string str) {
	bool loop = true;
	while (loop) {
		cout << str << endl;
		if (cin >> i) {
			loop = false;
		}
		else {
			cout << "输入有误，请重试" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

/// <summary>
/// 检查线性表是否存在，若不存在则自动初始化
/// </summary>
/// <param name="L"> 引用传递，线性表指针的引用 </param>
void CheckList(SqList*& L) {
	if (L == NULL) {
		cout << "列表不存在或已被销毁，以自动初始化" << endl;
		InitList(L);
	}
}         