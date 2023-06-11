#include"Huffman.h"


encode::encode(string m) {
	text = m;
	code = "";
	tree = NULL;
	fstream file;
	file.open("compressedFile.txt", ios::out | ios::trunc);
	file << "";
	file.close();
}

string encode::decode(string filename) {
	L_NODE* temp = tree;
	fstream f;
	string str = "";
	f.open(filename, ios::in);
	char ch;
	while (!f.eof()) {
		f >> ch;;
		if (ch == '1') {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
		if (temp->left == NULL && temp->right == NULL) {
			//cout << temp->ch;
			str += temp->ch;
			temp = tree;
		}
	}

	return str;
}
void encode::LoadTextFromFile(string filename) {
	fstream f;
	f.open(filename, ios::in);
	char ch;
	while (!f.eof()) {
		f.get(ch);
		text += ch;
	}
	f.close();
}
void encode::saveToFile(string filename, int* arr, int n) {
	ofstream f;
	static int count = 0;
	f.open("compressedFile.txt",ios::app);
	for (int i = 0; i < n; ++i) {
		f << arr[i];
	}
	f.close();
}
void encode::encodeText(string filename) {

	LoadTextFromFile(filename);

	int freq[256] = { 0 };
	int b;
	for (int i = 0; text[i] != '\0'; i++) {
		b = text[i];
		freq[b]++;
	}
	for (int i = 0; i < 256; i++) {
		if (freq[i] != 0) {
			l.Insert(char(i), freq[i], 1);
		}
	}
	tree = l.buildTree();
	GenerateCode();
}

void encode::GenerateCode() {
	int* arr = new int[10000000];
	int top = 0;
	int i = 0;
	while (text[i] != 0) {
		MakeCode(tree, arr, top, text[i]);
		i++;
	}
}

void encode::MakeCode(L_NODE* root, int arr[], int top, char search) {

	// Assign 0 to left edge and recur
	if (root->left) {

		arr[top] = 0;
		MakeCode(root->left, arr, top + 1, search);
	}

	// Assign 1 to right edge and recur
	if (root->right) {

		arr[top] = 1;
		MakeCode(root->right, arr, top + 1, search);
	}

	//if (isLeaf(root) == true) {
	if (root->ch == search) {
		saveToFile("compressedFile.txt", arr, top);
	}
}

int encode::isLeaf(L_NODE* root) {
	return !(root->left) && !(root->right);
}
