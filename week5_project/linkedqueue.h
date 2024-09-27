#pragma once
#include<iostream>
#include<vector>
#include"exceptionhanding.h"

namespace LQ {
	typedef char ElemType;

	typedef struct DataNode {
		ElemType data;
		struct DataNode* next;
	} *PtrDataNode;

	typedef struct LinkQueueNode {
		PtrDataNode front;
		PtrDataNode rear;
	} *PtrLQNode;

	void InitQueue(PtrLQNode& Q);
	void DestroyQueue(PtrLQNode& Q);
	bool IsEmpty(PtrLQNode& Q);
	void EnQueueByArr(PtrLQNode& Q, std::vector<ElemType>& arr);
	void EnQueueByEle(PtrLQNode& Q, ElemType e);
	bool DeQueue(PtrLQNode& Q);
	void ShowDeSeq(PtrLQNode& Q);
	void Menu();
	void CheckExist(PtrLQNode& Q);
}