#include"circularqueue.h"
namespace CQ {
	void InitCQ(PtrCQ& Q) {
		Q = (PtrCQ)malloc(sizeof(CircularQueue));
		Q->front = Q->rear = 0;
		std::cout << "[" << Q << "] 循环队列初始化完成" << std::endl;
	}

	void DestroyCQ(PtrCQ& Q) {
		if (Q != NULL) {
			free(Q);
			Q = NULL;
			std::cout << "[" << Q << "] 循环队列已销毁" << std::endl;
		}
		else {
			std::cout << "[" << Q << "] 循环队列不存在" << std::endl;
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
			std::cout << "[" << Q << "] 队列已满" << std::endl;
			return false;
		}
		Q->rear = (Q->rear + 1) % MAX_SIZE;
		Q->data[Q->rear] = e;
		std::cout << "[" << Q << "] 元素 " << e << " 已入循环队列" << std::endl;
		return true;
	}

	bool DeQueue(PtrCQ& Q, ElemType& e) {
		if (IsEmpty(Q)) {
			std::cout << "[" << Q << "] 队列已空" << std::endl;
			return false;
		}
		Q->front = (Q->front + 1) % MAX_SIZE;
		e = Q->data[Q->front];
		std::cout << "[" << Q << "] 元素 " << e << " 已出循环队列" << std::endl;
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
			std::cout << "[" << Q << "] 循环队列为空" << std::endl;
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
		std::cout << "[" << Q << "] 排序后结果: ";
		CQ::ShowCQ(Q);
		std::cout << std::endl;
		return true;
	}

	void Menu() {
		bool loop = true;
		int option = 0;

		PtrCQ Q = NULL;
		while (loop) {
			EH::CheckInput(option, "========请输入要执行的操作========\
			\n1. 初始化循环队列\
			\n2. 销毁循环队列\
			\n3. 判断循环队列是否非空\
			\n4. 判断循环队列是否已满\
			\n5. 依次进队元素\
			\n6. 出队一个元素，输出该元素\
			\n7. 输出出队序列\
			\n8. 升序排序\
			\n============输入-1退出============");
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
					std::cout << "循环队列为空" << std::endl;
				}
				else {
					std::cout << "循环队列不为空" << std::endl;
				}
				break;
			}
			case 4: {
				CheckExist(Q);
				if (IsFull(Q)) {
					std::cout << "循环队列已满" << std::endl;
				}
				else {
					std::cout << "循环队列未满" << std::endl;
				}
				break;
			}
			case 5: {
				CheckExist(Q);
				ElemType e = '\0';
				EH::CheckInput(e, "请输入要增加的元素");
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
				std::cout << "未知指令" << std::endl;
				break;
			}
			}
		}
	}

	void CheckExist(PtrCQ& Q){
		if(Q == NULL){
			std::cout << "循环队列不存在，已自动初始化" << std::endl;
			InitCQ(Q);
		}
	}
}