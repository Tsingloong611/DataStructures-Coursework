#pragma once
#include <iostream>
#include <vector>
namespace SList {
	typedef char ElemType;
	typedef struct SNode {
		ElemType data;
		struct SNode* next;
	} SLinkNode;

	void InitList(SLinkNode*& L);
	void InsertList(SLinkNode* L, int n, std::vector<ElemType> elem_arr);
	void DispList(SLinkNode* L);
	void CheckInput(std::vector<char>& elem_arr);
	bool CheckExist(ElemType e, std::vector<ElemType> arr);
	SLinkNode* Intersection(SLinkNode* A, SLinkNode* B);
	void DestroySLinkList(SLinkNode*& L);
	void menu();
}

namespace DList{
	typedef char ElemType;
	typedef struct DNode {
		ElemType data;
		struct DNode* prior;
		struct DNode* next;
	} DLinkNode;

	void InitList(DLinkNode*& L);
	void InsertList(DLinkNode* L, int n, std::vector<ElemType> elem_arr);
	void DispList(DLinkNode* L);
	int ListLength(DLinkNode* L);
	bool ListEmpty(DLinkNode* L);
	bool GetElem(DLinkNode* L, ElemType& e, int n);
	bool GetLocation(DLinkNode* L, std::vector<int>& int_arr, ElemType e);
	bool InsertElemByIndex(DLinkNode* L, ElemType e, int n);
	bool DelElemByIndex(DLinkNode* L, ElemType& e, int n);
	void DestoryList(DLinkNode*& L);
	void CheckList(DLinkNode*& L);
	void CheckInput(int& n, const char* str, bool is_skip = false, int default_num = 0);
	void CheckInput(ElemType& e, const char* str, bool is_skip = false, int default_char = '\0');
	void CheckInput(std::vector<ElemType>& elem_arr, const char* str, int n, bool is_skip = false, std::vector<ElemType> default_elem_arr = { '\0' });
	void menu();
}

namespace Common {
	bool CheckSkip(bool& enable_skip, int mode = 0);
}