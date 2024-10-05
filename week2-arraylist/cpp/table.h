/*
* 编写时间：2024/9/5
* 程序版本：V1.0
* 开发者：xx
*
* 程序功能：线性表的基本操作
* 输入数据：用户键盘输入
* 输出结果：屏幕显示线性表的基本操作结果
*/
#pragma once // 防止头文件重复包含
using namespace std; 

// 定义 MAX ElemType 与 SqList
#define MAX 100
typedef char ElemType;
typedef struct {
	ElemType Data[MAX];
	int length;
} SqList;

// 各函数的声明，具体实现见 "table.cpp"
void InitList(SqList*& L);

void DestroyList(SqList*& L);

void InsertByOrder(SqList* L);

bool AddElemByOrder(SqList* L, ElemType e, int i);

bool DeleteElemByOrder(SqList* L, ElemType& e, int i);

bool DeleteElemByObj(SqList* L, ElemType e, int& i);

void ShowList(SqList* L);

int GetListLength(SqList* L);

bool IsEmpty(SqList* L);

bool GetElemByOrder(SqList* L, ElemType& e, int i);

int GetFirstOrderByElem(SqList* L, ElemType e);

bool GetMaxElem(SqList* L,ElemType& max, int& i);

void CheckInput(ElemType& e, string str);

void CheckInput(int& i, string str);

void CheckList(SqList*& L);