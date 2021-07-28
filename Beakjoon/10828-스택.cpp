#include <bits/stdc++.h>

using namespace std;

/*
	스택 10828번
	https://www.acmicpc.net/problem/10828
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int stack[10000];
	int size = 0;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		

		if (input == "push") {
			cin >> stack[size++];
		}
		else if (input == "top") {
			if (size > 0) {
				cout << stack[size - 1] << endl;
			}
			else {
				cout << -1 << endl;
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
		else if (input == "pop") {
			if (size > 0) {
				cout << stack[--size] << endl;
			}
			else {
				cout << -1 << endl;
			}
			
		}

	}
	return 0;
}