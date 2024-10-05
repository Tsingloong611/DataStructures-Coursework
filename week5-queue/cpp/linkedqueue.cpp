#include"linkedqueue.h"
namespace LQ {
	void InitQueue(PtrLQNode& Q) {
		Q = (PtrLQNode)malloc(sizeof(LinkQueueNode));
		Q->front = Q->rear = NULL;
		std::cout << "链队初始化完成" << std::endl;
	}

	void DestroyQueue(PtrLQNode& Q) {
		if (Q != NULL) {
			free(Q);
			Q = NULL;
			std::cout << "链队已销毁" << std::endl;
			return;
		}
		std::cout << "链队不存在" << std::endl;
	}

	bool IsEmpty(PtrLQNode& Q) {
		return Q->rear == NULL;
	}

	void EnQueueByArr(PtrLQNode& Q, std::vector<ElemType>& arr) {
		if (IsEmpty(Q)) {
			PtrDataNode data = (PtrDataNode)malloc(sizeof(DataNode));
			data->data = arr[0];
			data->next = NULL;
			Q->front = Q->rear = data;
			std::cout << "元素 " << data->data << " 入队成功" << std::endl;
			for (int i = 1; i < arr.size();i++) {
				PtrDataNode s = (PtrDataNode)malloc(sizeof(DataNode));
				s->data = arr[i];
				s->next = NULL;
				Q->rear->next = s;
				Q->rear = s;
				std::cout << "元素 " << s->data << " 入队成功" << std::endl;
			}
			arr.clear();
		}
		else {
			for (int i = 0; i < arr.size();i++) {
				PtrDataNode s = (PtrDataNode)malloc(sizeof(DataNode));
				s->data = arr[i];
				s->next = NULL;
				Q->rear->next = s;
				Q->rear = s;
				std::cout << "元素 " << s->data << " 入队成功" << std::endl;
			}
			arr.clear();
		}
	}

	void EnQueueByEle(PtrLQNode& Q, ElemType e) {
		PtrDataNode s = (PtrDataNode)malloc(sizeof(DataNode));
		s->data = e;
		s->next = NULL;
		if (IsEmpty(Q)) {
			Q->front = Q->rear = s;
		}
		else {
			Q->rear->next = s;
			Q->rear = s;
		}
		std::cout << "元素 " << s->data << " 入队成功" << std::endl;
	}
	bool DeQueue(PtrLQNode& Q) {
		if (IsEmpty(Q)) {
			std::cout << "队列为空" << std::endl;
			return false;
		}
		PtrDataNode s = Q->front;
		std::cout << "元素 " << s->data << " 出队成功" << std::endl;
		if (Q->front == Q->rear) {
			Q->front = Q->rear = NULL;
			free(s);
			return true;
		}
		Q->front = s->next;
		free(s);
		return true;
	}

	void ShowDeSeq(PtrLQNode& Q) {
		if (IsEmpty(Q)) {
			std::cout << "队列为空" << std::endl;
			return;
		}
		PtrDataNode s = Q->front;
		std::cout << "链队出队序列展示：";
		while (s != NULL) {
			std::cout << s->data << " ";
			s = s->next;
		}
		std::cout << std::endl;
	}

	void Menu() {
		bool loop = true;
		int option = 0;

		PtrLQNode Q = NULL;
		while (loop) {
			EH::CheckInput(option, "========请输入要执行的操作========\
			\n1. 初始化链队\
			\n2. 销毁链队\
			\n3. 判断链队是否非空\
			\n4. 一次进队元素\
			\n5. 出队一个元素，输出该元素\
			\n6. 依次进队元素\
			\n7. 输出出队序列\
			\n============输入-1退出============");
			switch (option)
			{
			case 1: {
				InitQueue(Q);
				break;
			}
			case 2: {
				DestroyQueue(Q);
				break;
			}
			case 3: {
				CheckExist(Q);
				if (IsEmpty(Q)) {
					std::cout << "链队为空" << std::endl;
				}
				else {
					std::cout << "链队不为空" << std::endl;
				}
				break;
			}
			case 4: {
				CheckExist(Q);
				int num = 0;
				std::vector<ElemType> arr;
				EH::CheckInput(num, "请输入要增加的元素的数量");
				arr.clear();
				for (int i = 0; i < num;i++) {
					ElemType e;
					std::string str ="请输入第 " +std::to_string(i + 1)+ " 个元素";
					EH::CheckInput(e, str.c_str());
					arr.push_back(e);
				}
				EnQueueByArr(Q, arr);
				break;
			}
			case 5: {
				CheckExist(Q);
				DeQueue(Q);
				break;
			}
			case 6: {
				CheckExist(Q);
				ElemType e = '\0';
				EH::CheckInput(e, "请输入要增加的元素");
				EnQueueByEle(Q, e);
				break;
			}
			case 7: {
				CheckExist(Q);
				ShowDeSeq(Q);
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

	void CheckExist(PtrLQNode& Q){
		if(Q == NULL){
			std::cout << "链队不存在，已自动初始化" << std::endl;
			InitQueue(Q);
		}
	}
}
