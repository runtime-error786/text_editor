#ifndef TrieTree_h
#define TrieTree_h
#include<iostream>
using namespace std;
struct node {
	node* alphabets[26];
	char key;
	bool Isword;
	string msg;
	node(char k = NULL);

};


class TrieTree {
	node* root;
	string suggestion[11];
	int count;
public:
	TrieTree();

	node* GetRoot() {
		return root;
	}
	void LoadData(string str);
	string *suggest(string str);
	bool isleaf(node* r);

private:
	void print(node* head = NULL);

	

};



#endif // !TrieTree_h
