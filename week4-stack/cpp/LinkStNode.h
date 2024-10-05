#pragma once
#include<iostream>
#include<vector>

typedef char ElemType;
typedef struct linknode {
	ElemType data;
	linknode* next;
} LinkStNode;

void InitStack(LinkStNode*& S);
bool StackEmpty(LinkStNode* S);
void PushByArr(LinkStNode*& S, std::vector<ElemType> arr);
void PushByEle(LinkStNode*& S, ElemType e);
bool Pop(LinkStNode* S, ElemType& e);
bool DispStack(LinkStNode* S);
void DestroyStack(LinkStNode*& S);
void SortUpOrder(LinkStNode*& S);