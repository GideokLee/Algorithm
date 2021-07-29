#include <bits/stdc++.h>

using namespace std;

/*
	큐 10845번
	https://www.acmicpc.net/problem/10845
	que
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string input;
	int* que = new int[200000];
	int front = 0;
	int back = 0;
	int size = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			if (size != 0) back++;
			cin >> que[back];
			size++;
		}
		else if (input == "pop") {
			if (size == 0) {
				cout << -1 << endl;
			}
			else {
				if (size == 1) {
					cout << que[front] << endl;
				}
				else {
					cout << que[front++] << endl;
				}
				size--;
			}
		}
		else if (input == "size") {
			cout << size << endl;
		}
		else if (input == "empty") {
			if (size > 0) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (input == "front") {
			if (size > 0) {
				cout << que[front] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (input == "back") {
			if (size > 0) {
				cout << que[back] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}