#include <bits/stdc++.h>

using namespace std;

/*
	안정적인 문자열 4889번
	https://www.acmicpc.net/problem/4889
	Stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int count = 1;
	while (true) {
		string input;
		cin >> input;
		if (input[0] == '-') break;
		string stack = "";
		int size = input.size();
		for (int i = 0; i < size; i++) {
			if (input[i] == '{') {
				stack.push_back(input[i]);
			}
			else {
				if (stack.size() == 0) {
					stack.push_back(input[i]);
				}
				else {
					if (stack.back() == '{') {
						stack.pop_back();
					}
					else {
						stack.push_back(input[i]);
					}
				}
			}
		}
		size = stack.size();
		int result = 0;
		for (int i = 0; i < size; i+=2) {
			if (stack[i] != stack[i + 1]) {
				result = result + 2;
			}
			else {
				result++;
			}
		}
		cout << count++ << ". " << result << endl;
	}
	return 0;
}