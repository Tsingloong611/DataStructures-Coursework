#include"LinkList.h"

namespace DList {
	// 初始化循环链表L
	void InitList(DLinkNode*& L) {
		L = (DLinkNode*)malloc(sizeof(DLinkNode));
		L->next = L;
		L->prior = L;
	}

	// 依次采用尾插法插入元素a, b, c, d, e
	void InsertList(DLinkNode* L, int n, std::vector<ElemType> elem_arr) {
		DLinkNode* s = NULL;
		DLinkNode* p = L;
		for (int i = 0; i < n; i++) {
			s = (DLinkNode*)malloc(sizeof(DLinkNode));
			s->data = elem_arr[i];
			s->next = p;
			s->prior = p->prior;
			p->prior->next = s;
			p->prior = s;
		}
	}

	// 输出循环链表L
	void DispList(DLinkNode* L) {
		DLinkNode* p = L;
		while (p->next != L) {
			p = p->next;
			std::cout << p->data << " ";
		}
		std::cout << std::endl;
	}

	// 输出循环链表L的长度
	int ListLength(DLinkNode* L) {
		DLinkNode* p = L;
		int i = 0;
		while (p->next != L) {
			p = p->next;
			i++;
		}
		return i;
	}


	// 判定循环链表L是否为空
	bool ListEmpty(DLinkNode* L) {
		return L->next == L;
	}

	// 输出循环链表L的第3个元素
	bool GetElem(DLinkNode* L, ElemType& e, int n) {
		if (ListLength(L) >= n) {
			DLinkNode* p = L;
			int i = 0;
			while (i < n) {
				p = p->next;
				i++;
			}
			e = p->data;
			return true;
		}
		return false;
	}

	// 输出元素a的位置
	bool GetLocation(DLinkNode* L, std::vector<int>& int_arr, ElemType e) {
		DLinkNode* p = L;
		int i = 0;
		int_arr.clear();
		while (p->next != L) {
			p = p->next;
			i++;
			if (p->data == e) {
				int_arr.push_back(i);
			}
		}
		return int_arr.size();
	}

	// 在第4个位置插入元素f
	bool InsertElemByIndex(DLinkNode* L, ElemType e, int n) {
		DLinkNode* p = L;
		DLinkNode* s = NULL;
		int i = 0;
		if (ListLength(L) >= n) {
			while (p->next != L && i < n - 1) {
				p = p->next;
				i++;
			}
			s = (DLinkNode*)malloc(sizeof(DLinkNode));
			s->data = e;
			s->prior = p;
			s->next = p->next;
			p->next->prior = s;
			p->next = s;
			return true;
		}
		return false;
	}

	// 删除第3个位置的元素并输出
	bool DelElemByIndex(DLinkNode* L, ElemType& e, int n) {
		DLinkNode* p = L;
		int i = 0;
		if (ListLength(L) >= n) {
			while (i < n - 1) {
				p = p->next;
				i++;
			}
			e = p->next->data;
			p->next = p->next->next;
			free(p->next->prior);
			p->next->prior = p;
			return true;
		}
		return false;
	}

	void DestoryList(DLinkNode*& L) {
		if (L == NULL) {
			std::cout << "List doesn't exist" << std::endl;
			return;
		}
		DLinkNode* pre = L;
		DLinkNode* p = L->next;
		while (p != L) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
		L = NULL;
		std::cout << "List has already been destoried." << std::endl;
	}

	void CheckList(DLinkNode*& L) {
		if (L == NULL) {
			InitList(L);
			std::cout << "Detected list not exists, init the list automatally" << std::endl;
		}
	}

	void CheckInput(int& n, const char* str, bool is_skip, int default_num) {
		std::cout << str << std::endl;
		while (true) {
			if (std::cin >> n) {
				if (is_skip && n == 0) {
					std::cout << "Skip successfully" << std::endl;
					n = default_num;
					return;
				}
				std::cout << "Input (" << typeid(n).name() << ") " << n << " successfully" << std::endl;
				return;
			}
			else {
				std::cout << "Invalid input, please input again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}

	void CheckInput(ElemType& e, const char* str, bool is_skip, int default_char) {
		std::cout << str << std::endl;
		const int size = 50;
		char input[size];
		while (true) {
			if (std::cin >> input && strlen(input) == 1) {
				e = input[0];
				std::cout << "Input (" << typeid(e).name() << ") " << e << " successfully" << std::endl;
				return;
			}
			else if (is_skip && std::string(input) == "skip") {
				std::cout << "Skip successfully" << std::endl;
				e = default_char;
				return;
			}
			else {
				std::cout << "Invalid input, please input again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}

	void CheckInput(std::vector<ElemType>& elem_arr, const char* str, int n, bool is_skip, std::vector<ElemType> default_elem_arr) {
		std::cout << str << std::endl;
		ElemType e;
		const int size = 50;
		char input[size];
		elem_arr.clear();
		while (n > 0) {
			if (std::cin >> input && strlen(input) == 1) {
				e = input[0];
				elem_arr.push_back(e);
				std::cout << "Input (" << typeid(e).name() << ") " << e << " successfully, we already put it in our elem_arr." << std::endl;
				n--;
			}
			else if (is_skip && std::string(input) == "skip" && n <= default_elem_arr.size()) {
				std::cout << "Skip successfully" << std::endl;
				elem_arr = default_elem_arr;
				return;
			}
			else if (is_skip && std::string(input) == "skip" && n > default_elem_arr.size()) {
				std::cout << n << " is too large to skip, please input element manually." << std::endl;
				is_skip = false;
				continue;
			}
			std::cout << "Invalid input, please input again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}



	void menu() {
		std::vector<ElemType> default_elem_arr = { 'a', 'b', 'c', 'd', 'e' };
		int default_insert_count = 5;
		int default_insert_index = 4;
		char default_output_elem = 'a';
		char default_insert_elem = 'f';
		int default_del_num = 3;

		bool loop = true;
		int option = 0;

		bool enable_skip = true;
		int skip_choose = 0;

		std::vector<int> int_arr;
		std::vector<ElemType> elem_arr;

		DLinkNode* L = NULL;
		ElemType e;
		int n = 0;

		if (Common::CheckSkip(enable_skip)) {
			return;
		}

		while (loop) {
			if (!Common::CheckSkip(enable_skip, 1)) {
				CheckInput(option, "============请输入对应值以进行操作============\n\t1.初始化循环链表L\n\t2.依次采用尾插法插入五个元素（默认为 a, b, c, d, e）\n\t3.输出循环链表L\n\t4.输出循环链表L的长度\n\t5.判定循环链表L是否为空\n\t6.输出循环链表L的第n个元素（默认为3）\n\t7.输出元素的位置（默认为a）\n\t8.在第n个位置（默认为4）插入元素（默认为 f）\n\t9.删除第n个位置（默认为3）的元素并输出\n\t10.销毁链表\n============= 请输入 - 1 以退出程序 =============");
				enable_skip = true;
			}
			system("cls");
			if (Common::CheckSkip(enable_skip)) {
				continue;
			}
			switch (option)
			{
			case 1: {
				InitList(L);
				std::cout << "List Initialized" << std::endl;
				break;
			}
			case 2: {
				CheckList(L);
				CheckInput(n, "Please input the number of elements you want to insert (default 5, input 0 to skip): ", true, default_insert_count);
				CheckInput(elem_arr, "Please input the elements you want to insert (default a, b, c, d, e, input skip to skip): ", (n != 0 ? n : 5), true, default_elem_arr);
				InsertList(L, n, elem_arr);
				break;
			}
			case 3: {
				CheckList(L);
				std::cout << "List is: " << std::endl;
				DispList(L);
				break;
			}
			case 4: {
				CheckList(L);
				std::cout << "The length of list is: " << ListLength(L) << std::endl;
				break;
			}
			case 5: {
				CheckList(L);
				if (ListEmpty(L)) {
					std::cout << "List is Empty" << std::endl;
				}
				else {
					std::cout << "List is not Empty" << std::endl;
				}
				break;
			}
			case 6: {
				CheckList(L);
				CheckInput(n, "Please input the index you want to find the element (default 3, input 0 to skip): ", true, default_del_num);
				if (GetElem(L, e, n)) {
					std::cout << "The element of index " << n << " is " << e << std::endl;
				}
				else {
					std::cout << "Index is out of length" << std::endl;
				}

				break;
			}
			case 7: {
				CheckList(L);
				CheckInput(e, "Please input the element you want to find the index (default a, input skip to skip): ", true, default_output_elem);
				if (GetLocation(L, int_arr, e)) {
					for (std::vector<int>::iterator eleptr = int_arr.begin(); eleptr < int_arr.end(); eleptr++) {
						std::cout << *eleptr << " ";
					}
					std::cout << "\nAbove is all the index" << std::endl;
				}
				else {
					std::cout << "No such element found." << std::endl;
				}
				break;
			}
			case 8: {
				CheckList(L);
				CheckInput(n, "Please input the index you want to insert (default 4, input 0 to skip): ", true, default_insert_index);
				CheckInput(e, "Please input the element you want to insert (default f, input skip to skip) : ", true, default_insert_elem);
				if (InsertElemByIndex(L, e, n))
				{
					std::cout << e << " was inserted successfully." << std::endl;
				}
				else {
					std::cout << "Index is out of length" << std::endl;
				}
				break;
			}
			case 9: {
				CheckList(L);
				CheckInput(n, "Please input the index you want to delete (default 3, input 0 to skip): ", true, default_del_num);
				if (DelElemByIndex(L, e, n)) {
					std::cout << e << " was deleted successfully." << std::endl;
				}
				else {
					std::cout << "Index is out of length" << std::endl;
				}
				break;
			}
			case 10: {
				DestoryList(L);
				break;
			}
			case -1: {
				loop = false;
				DestoryList(L);
				std::cout << "Exit Succencefully" << std::endl;
				break;
			}
			default: {
				std::cout << "Invalid input, please input again" << std::endl;
				break;
			}
			}
		}
	}
}