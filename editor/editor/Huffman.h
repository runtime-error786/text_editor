#ifndef Huffman_h
#define Huffman_h
#include"LinkedList.h"
#include<string>
#include<fstream>

class encode {
	List l;
	string text;
	string code;
	L_NODE* tree;
public:
	encode(string m = "");
	void encodeText(string filename = "editior.txt");
	string decode(string filename = "compressedFile.txt");

private:
	void LoadTextFromFile(string filename = "editior.txt");
	void saveToFile(string filename = "compressedFile.txt", int* arr = NULL, int n = 0);
	void GenerateCode();
	void MakeCode(L_NODE* root, int arr[], int top, char search);
	int isLeaf(L_NODE* root);

};




#endif // !Huffman_h
