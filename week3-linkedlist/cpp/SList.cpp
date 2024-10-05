#include"LinkList.h"

namespace SList {
	void InitList(SLinkNode*& L) {
		L = (SLinkNode*)malloc(sizeof(SLinkNode));
		L->next = NULL;
	}

	void InsertList(SLinkNode* L, int n, std::vector<ElemType> elem_arr) {
		SLinkNode* p = L;
		SLinkNode* s = NULL;
		int i = 0;
		while (p->next != NULL) {
			p = p->next;
		}
		while (i < n) {
			s = (SLinkNode*)malloc(sizeof(SLinkNode));
			s->data = elem_arr[i];
			p->next = s;
			s->next = NULL;
			p = s;
			i++;
		}
	}

	void DispList(SLinkNode* L) {
		SLinkNode* p = L;
		while (p->next != NULL) {
			p = p->next;
			std::cout << p->data << " ";
		}
		std::cout << std::endl;
	}

	void CheckInput(std::vector<char>& elem_arr, const char* end_flag) {
		bool loop = true;
		ElemType e;
		const int size = 50;
		char input[size];
		elem_arr.clear();
		while (loop) {
			if (std::cin >> input && strlen(input) == 1) {
				e = input[0];
				elem_arr.push_back(e);
				std::cout << "Input (" << typeid(e).name() << ") " << e << " successfully, we already put it in our elem_arr." << std::endl;
			}
			else if (std::string(input) == end_flag) {
				return;
			}
			else {
				std::cout << "错误的输入，请重新输入" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		return;
	}

	bool CheckExist(SList::ElemType e, std::vector<SList::ElemType> arr) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == e) {
				return true;
			}
		}
		return false;
	}

	SList::SLinkNode* Intersection(SList::SLinkNode* A, SList::SLinkNode* B) {
		SList::SLinkNode* C = NULL;
		std::vector<SList::ElemType> arr;
		if (A->next == NULL || B->next == NULL) {
			return C;
		}
		for (SList::SLinkNode* p = A->next; p != NULL; p = p->next) {
			for (SList::SLinkNode* q = B->next; q != NULL; q = q->next) {
				if (p->data == q->data && !CheckExist(p->data, arr)) {
					arr.push_back(p->data);
				}
			}
		}
		C = (SList::SLinkNode*)malloc(sizeof(SList::SLinkNode));
		C->next = NULL;
		InsertList(C, arr.size(), arr);
		return C;
	}

	void DestroySLinkList(SList::SLinkNode*& L) {
		if (L == NULL) {
			std::cout << "List doesn't exist" << std::endl;
			return;
		}
		SList::SLinkNode* p = L;
		while (p->next != NULL) {
			SList::SLinkNode* q = p->next;
			free(p);
			p = q;
		}
		free(p);
		L = NULL;
		std::cout << "List has already been destoried." << std::endl;
	}

	void menu() {
		SList::SLinkNode* A = NULL;
		SList::SLinkNode* B = NULL;
		SList::SLinkNode* C = NULL;
		std::vector<SList::ElemType> elem_arr;
		bool enable_skip = true;
		const char* end_flag = "end";
		InitList(A);
		InitList(B);
		if (Common::CheckSkip(enable_skip)) {
			return;
		}
		std::cout << "为A增加元素，输入 " << end_flag << " 结束" << std::endl;
		SList::CheckInput(elem_arr, end_flag);
		InsertList(A, elem_arr.size(), elem_arr);
		std::cout << "为B增加元素，输入 " << end_flag << " 结束" << std::endl;
		SList::CheckInput(elem_arr, end_flag);
		InsertList(B, elem_arr.size(), elem_arr);
		std::cout << "A: ";
		DispList(A);
		std::cout << "B: ";
		DispList(B);
		C = Intersection(A, B);
		std::cout << "C: ";
		DispList(C);
		SList::DestroySLinkList(A);
		SList::DestroySLinkList(B);
		SList::DestroySLinkList(C);
		return;
	}
}
