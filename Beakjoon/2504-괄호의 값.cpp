#include <bits/stdc++.h>

using namespace std;

/*
	괄호의 값 2504번
	https://www.acmicpc.net/problem/2504
	stack
*/
struct value {
	int num;
	char oper;
};


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	string input;
	string stack = "";
	cin >> input;
	int result = 0;
	int size = input.size();
	int s_size;
	int temp = 0;
	vector<int> val;
	val.push_back(0);
	for (int i = 0; i < size; i++) {
		s_size = stack.size();
		if (input[i] == '[' || input[i] == '(') {
			stack.push_back(input[i]);
			if (s_size > 0 && (input[i-1] == '[' || input[i-1] == '(')) {
				val.push_back(0);
			}
		}
		else if (s_size > 0 && stack.back() == '[' && input[i] == ']') {
			if (input[i - 1] == '[') {
				val.back() += 3;
			}
			else {
				int temp = val.back();
				val.pop_back();
				val.back() += temp * 3;
			}
			if (s_size == 1) {
				result+=val.back();
				val.clear();
				val.push_back(0);
			}
			stack.pop_back();
		}
		else if (s_size > 0 && stack.back() == '(' && input[i] == ')') {
			if (input[i - 1] == '(') {
				val.back() += 2;
			}
			else {
				int temp = val.back();
				val.pop_back();
				val.back() += temp * 2;
			}
			if (s_size == 1) {
				result += val.back();
				val.clear();
				val.push_back(0);
			}
			stack.pop_back();
		}
		else {
			result = -1;
			break;
		}
	}
	
	if (result == -1 || stack.size() > 0) {
		cout << 0 << endl;
	}
	else {
		cout << result << endl;
	}

	return 0;
}