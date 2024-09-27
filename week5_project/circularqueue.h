#include<iostream>
#include"exceptionhanding.h"

namespace CQ {
#define MAX_SIZE 50

	typedef char ElemType;

	typedef struct CircularQueue {
		ElemType data[MAX_SIZE];
		int front, rear;
	} *PtrCQ;

	void InitCQ(PtrCQ& Q);
	void DestroyCQ(PtrCQ& Q);
	bool IsEmpty(PtrCQ& Q);
	bool IsFull(PtrCQ& Q);
	bool EnQueueByEle(PtrCQ& Q, ElemType e);
	bool DeQueue(PtrCQ& Q, ElemType& e);
	void ShowCQ(PtrCQ& Q);
	bool AscSort(PtrCQ& Q);
	void Menu();
	void CheckExist(PtrCQ& Q);
}