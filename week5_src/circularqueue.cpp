#include"circularqueue.h"
namespace CQ {
	void InitCQ(PtrCQ& Q) {
		Q = (PtrCQ)malloc(sizeof(CircularQueue));
		Q->front = Q->rear = 0;
		std::cout << "[" << Q << "] ѭ�����г�ʼ�����" << std::endl;
	}

	void DestroyCQ(PtrCQ& Q) {
		if (Q != NULL) {
			free(Q);
			Q = NULL;
			std::cout << "[" << Q << "] ѭ������������" << std::endl;
		}
		else {
			std::cout << "[" << Q << "] ѭ�����в�����" << std::endl;
		}
	}

	bool IsEmpty(PtrCQ& Q) {
		return Q->front == Q->rear;
	}

	bool IsFull(PtrCQ& Q) {
		return (Q->rear + 1) % MAX_SIZE == Q->front;
	}

	bool EnQueueByEle(PtrCQ& Q, ElemType e) {
		if (IsFull(Q)) {
			std::cout << "[" << Q << "] ��������" << std::endl;
			return false;
		}
		Q->rear = (Q->rear + 1) % MAX_SIZE;
		Q->data[Q->rear] = e;
		std::cout << "[" << Q << "] Ԫ�� " << e << " ����ѭ������" << std::endl;
		return true;
	}

	bool DeQueue(PtrCQ& Q, ElemType& e) {
		if (IsEmpty(Q)) {
			std::cout << "[" << Q << "] �����ѿ�" << std::endl;
			return false;
		}
		Q->front = (Q->front + 1) % MAX_SIZE;
		e = Q->data[Q->front];
		std::cout << "[" << Q << "] Ԫ�� " << e << " �ѳ�ѭ������" << std::endl;
		return true;
	}

	void ShowCQ(PtrCQ& Q) {
		int start = Q->front + 1;
		int length = (Q->rear - Q->front + MAX_SIZE) % MAX_SIZE;
		for (int run_times = 0; run_times < length;run_times++) {
			std::cout << Q->data[(start + MAX_SIZE) % MAX_SIZE] << " ";
			start++;
		}
		std::cout << std::endl;
	}

	bool AscSort(PtrCQ& Q)
	{
		if (IsEmpty(Q)) {
			std::cout << "[" << Q << "] ѭ������Ϊ��" << std::endl;
			return false;
		}
		PtrCQ temp;
		InitCQ(temp);

		int length = (Q->rear - Q->front + MAX_SIZE) % MAX_SIZE;
		int run_times = 1;
		while (run_times < length) {
			ElemType min = Q->data[run_times];
			for (int i = run_times;i < length + 1;i++) {
				if (Q->data[i] < min) {
					min = Q->data[i];
				}
			}
			while (Q->data[Q->front + 1] != min) {
				ElemType e;
				DeQueue(Q, e);
				EnQueueByEle(temp, e);
			}
			DeQueue(Q, min);
			while (!IsEmpty(Q)) {
				ElemType e;
				DeQueue(Q, e);
				EnQueueByEle(temp, e);
			}
			EnQueueByEle(Q, min);
			while (!IsEmpty(temp)) {
				ElemType e;
				DeQueue(temp, e);
				EnQueueByEle(Q, e);
			}
			run_times++;
		}
		std::cout << "[" << Q << "] �������: ";
		CQ::ShowCQ(Q);
		std::cout << std::endl;
		return true;
	}

	void Menu() {
		bool loop = true;
		int option = 0;

		PtrCQ Q = NULL;
		while (loop) {
			EH::CheckInput(option, "========������Ҫִ�еĲ���========\
			\n1. ��ʼ��ѭ������\
			\n2. ����ѭ������\
			\n3. �ж�ѭ�������Ƿ�ǿ�\
			\n4. �ж�ѭ�������Ƿ�����\
			\n5. ���ν���Ԫ��\
			\n6. ����һ��Ԫ�أ������Ԫ��\
			\n7. �����������\
			\n8. ��������\
			\n============����-1�˳�============");
			switch (option)
			{
			case 1: {
				InitCQ(Q);
				break;
			}
			case 2: {
				DestroyCQ(Q);
				break;
			}
			case 3: {
				CheckExist(Q);
				if (IsEmpty(Q)) {
					std::cout << "ѭ������Ϊ��" << std::endl;
				}
				else {
					std::cout << "ѭ�����в�Ϊ��" << std::endl;
				}
				break;
			}
			case 4: {
				CheckExist(Q);
				if (IsFull(Q)) {
					std::cout << "ѭ����������" << std::endl;
				}
				else {
					std::cout << "ѭ������δ��" << std::endl;
				}
				break;
			}
			case 5: {
				CheckExist(Q);
				ElemType e = '\0';
				EH::CheckInput(e, "������Ҫ���ӵ�Ԫ��");
				EnQueueByEle(Q, e);
				break;
			}
			case 6: {
				CheckExist(Q);
				ElemType e = '\0';
				DeQueue(Q, e);
				break;
			}
			case 7: {
				CheckExist(Q);
				ShowCQ(Q);
				break;
			}
			case 8: {
				CheckExist(Q);
				AscSort(Q);
				break;
			}
			case -1: {
				loop = false;
				break;
			}
			default: {
				std::cout << "δָ֪��" << std::endl;
				break;
			}
			}
		}
	}

	void CheckExist(PtrCQ& Q){
		if(Q == NULL){
			std::cout << "ѭ�����в����ڣ����Զ���ʼ��" << std::endl;
			InitCQ(Q);
		}
	}
}