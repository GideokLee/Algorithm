#include <bits/stdc++.h>

using namespace std;

/*
	키로거 5397번
	https://www.acmicpc.net/problem/5397
	Linked List
*/

struct Node {
	char data;
	Node* pre;
	Node* next;
};

struct NodeList {
	Node* root;
	Node* curr;
};

void insertNode(NodeList &list, char data) {
	Node* newNode = new Node();
	newNode->data = data;

	if (list.curr->next == nullptr) {
		list.curr->next = newNode;
		newNode->pre = list.curr;
		list.curr = newNode;
		return;
	}
	Node *temp = list.curr->next;
	temp->pre = newNode;
	list.curr->next = newNode;
	newNode->pre = list.curr;
	newNode->next = temp;
	list.curr = newNode;
}
void printNode(NodeList& list) {
	Node *temp;
	temp = list.root;
	while (true) {
		if (temp->next == nullptr) {
			cout << endl;
			break;
		}
		temp = temp->next;
		cout << temp->data;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int L;
	cin >> L;

	for (int i = 0; i < L; i++) {
		string input;
		NodeList list;
		Node* root = new Node();
		list.root = root;
		list.curr = root;

		cin >> input;
		int size = input.size();

		for (int i = 0; i < size; i++) {
			if (input[i] == '<') {
				if (list.curr->pre != nullptr) {
					list.curr = list.curr->pre;
				}
			}
			else if (input[i] == '>') {
				if (list.curr->next != nullptr) {
					list.curr = list.curr->next;
				}
			}
			else if (input[i] == '-') {
				if (list.curr->pre != nullptr) {
					if (list.curr->next == nullptr) {
						list.curr = list.curr->pre;
						list.curr->next = nullptr;
					}
					else {
						list.curr->pre->next = list.curr->next;
						list.curr->next->pre = list.curr->pre;
						list.curr = list.curr->pre;
					}
				}
			}
			else {
				insertNode(list, input[i]);
			}
		}
		printNode(list);
	}
	return 0;
}