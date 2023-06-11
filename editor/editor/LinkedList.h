#ifndef LinkedList_h
#define LinkedList_h
#include<iostream>
using namespace std;

class L_NODE {
public:
	char ch = NULL;	// data
	double count = 0;
	L_NODE* next = NULL;	// pointer to next Node
	L_NODE* left = NULL;
	L_NODE* right = NULL;
};

class List {
	L_NODE* head;
	int c = 0;
public:
	List(void) { head = NULL; } // constructor
	L_NODE* getHead() {
		return head;
	}
	bool IsEmpty();
	bool Insert(char, double, int);
	void DisplayList(void);
	void sorting();

	L_NODE* buildTree();

	void InsertTree(L_NODE* T);

};



#endif // !LinkedList_h
