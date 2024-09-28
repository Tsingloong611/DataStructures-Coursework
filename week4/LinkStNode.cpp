#include"LinkStNode.h"
void InitStack(LinkStNode*& S) {
	S = (LinkStNode*)malloc(sizeof(LinkStNode));
	S->next = NULL;
}

bool StackEmpty(LinkStNode* S) {
	return S->next == NULL;
}

void PushByArr(LinkStNode*& S, std::vector<ElemType> arr) {
	LinkStNode* p = NULL;
	for (int i = 0;i < arr.size(); i++) {
		p = (LinkStNode*)malloc(sizeof(LinkStNode));
		p->data = arr[i];
		p->next = S->next;
		S -> next = p;
		std::cout << "[栈 " << S << "] " << "元素 " << arr[i] << " 已入栈" << S << std::endl;
	}
}

void PushByEle(LinkStNode*& S, ElemType e) {
	LinkStNode* p = NULL;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = S->next;
	S->next = p;
	std::cout << "[栈 " << S << "] " << "元素 " << e << " 已入栈" << std::endl;
}

bool Pop(LinkStNode* S, ElemType& e) {
	if (!StackEmpty(S)) {
		LinkStNode* p = S->next;
		e = p->data;
		S->next = p->next;
		free(p);
		std::cout << "[栈 " << S << "] " << "栈顶元素： " << e << " 已出栈" << std::endl;
		return true;
	}
	return false;
}

bool DispStack(LinkStNode* S) {
	if (!StackEmpty(S)) {
		std::cout << "[栈 " << S << "] " << "元素展示： ";
		while(S->next != NULL) {
			S = S->next;
			std::cout << S->data << " ";
		}
		std::cout << std::endl;
		return true;
	}
	return false;
}

void DestroyStack(LinkStNode*& S) {
	if(!StackEmpty(S)) {
		LinkStNode* pre = S;
		if (S == NULL) {
			return;
		}
		LinkStNode* p = S->next;
		if(p == NULL) {
			free(pre);
			return;
		}
		while(p != NULL) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
}

void SortUpOrder(LinkStNode*& S) {
	LinkStNode* temp = NULL;
	InitStack(temp);

	static int run_times = 0;
	static int length = 0;


	LinkStNode* p = S->next;
	char min = S->next->data;
	int index = 0;
	int temp_num = 0;

	if (run_times == 0) {
		while (p != NULL) {
			length++;
			p = p->next;
		}
		p = S->next;
	}

	for(int i = 0;i < length - run_times;i++){
		if(p->data < min) {
			min = p->data;
			index = temp_num;
		}
		p = p->next;
		temp_num++;
	}

	for (int i = 0; i < index; i++) {
		char ele;
		Pop(S, ele);
		PushByEle(temp, ele);
	}

	Pop(S, min);

	for (int j = 0; j < length - index - 1 - run_times; j++) {
		char ele;
		Pop(S, ele);
		PushByEle(temp, ele);
	}

	PushByEle(S, min);

	while (temp->next != NULL) {
		char ele;
		Pop(temp, ele);
		PushByEle(S, ele);
	}

	run_times++;

	DestroyStack(temp);

	if (run_times == length) {
		run_times = 0;
		length = 0;
		return;
	}
	else {
		SortUpOrder(S);
	}
}