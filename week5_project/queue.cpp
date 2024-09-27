#include"queue.h"

typedef struct DataNode {
	ElemType data;
	struct DataNode* next;
}DNode;

typedef struct LinkQueueNode {
	DNode* front;
	DNode* rear;
}LQNode;

void InitQueue(LQNode*& Q) {
	Q = (LQNode*)malloc(sizeof(LQNode));
	Q->front = Q->rear = NULL;
}

void DestroyQueue(LQNode*& Q) {
	DNode* p = Q->front;
	while (p != NULL) {
		Q->front = p->next;
		free(p);
		p = Q->front;
	}
	free(Q);
}

bool QueueEmpty(LQNode* Q) {
	return Q->front == NULL;
}

void enQueue(LQNode*& Q, ElemType e) {
	DataNode* p = (DNode*)malloc(sizeof(DNode));
	p->data = e;
	p->next = NULL;
	if (Q->front == NULL) {
		Q->front = Q->rear = p;
	}
	else {
		Q->rear->next = p;
		Q->rear = p;
	}
}

bool deQueue(LQNode*& Q, ElemType& e) {
	if (Q->front == NULL) {
		return false;
	}
	DataNode* p = Q->front;
	e = p->data;
	Q->front = p->next;
	if (Q->front == NULL) {
		Q->rear = NULL;
	}
	free(p);
	return true;
}

bool GetHead(LQNode* Q, ElemType& e) {
	if (Q->front == NULL) {
		return false;
	}
	e = Q->front->data;
	return true;
}