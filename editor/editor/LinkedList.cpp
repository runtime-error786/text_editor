#include"LinkedList.h"

bool List::IsEmpty() {
	if (head == NULL) {
		return true;
	}
	else
		return (head->next == NULL);
}

L_NODE* List::buildTree() {
	while (!IsEmpty()) {
		sorting();
		double sum = 0;
		L_NODE* tree = new L_NODE;
		sum = head->count;
		sum += head->next->count;
		tree->left = head;
		tree->right = head->next;
		tree->count = sum;
		head = head->next->next;
		tree->left->next = NULL;
		tree->right->next = NULL;
		InsertTree(tree);
	}
	return head;
}

void List::InsertTree(L_NODE* T) {
	if (T != NULL) {
		T->next = head;
		head = T;
	}

}

bool List::Insert(char ch, double count, int index) {
	if (index <= 0) return false;

	int currIndex = 2;
	L_NODE* current = head;
	while (current && index > currIndex) {
		current = current->next;
		currIndex++;
	}
	if (index > 1 && current == NULL) return false;

	L_NODE* newNode = new L_NODE;
	newNode->ch = ch;
	newNode->count = count;
	newNode->left = NULL;
	newNode->right = NULL;
	if (index == 1) {
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = current->next;
		current->next = newNode;
	}
	c++;
	return true;
}

void List::sorting()
{
	L_NODE* temp = head;

	L_NODE* newnode;
	char tmch;
	double tmc;
	L_NODE* tmLeft;
	L_NODE* tmright;
	while (temp != NULL) {
		newnode = temp->next;

		while (newnode != NULL) {

			if (temp->count >= newnode->count) {
				tmch = newnode->ch;
				tmc = newnode->count;
				tmLeft = newnode->left;
				tmright = newnode->right;

				newnode->ch = temp->ch;
				newnode->count = temp->count;
				newnode->left = temp->left;
				newnode->right = temp->right;

				temp->ch = tmch;
				temp->count = tmc;
				temp->left = tmLeft;
				temp->right = tmright;


			}
			newnode = newnode->next;
		}
		temp = temp->next;
	}
}

void List::DisplayList()
{
	int num = 0;
	L_NODE* current = head;
	while (current != NULL && num < c) {
		cout << current->ch << ": " << current->count << endl;
		current = current->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}