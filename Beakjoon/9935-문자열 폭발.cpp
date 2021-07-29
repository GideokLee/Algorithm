#include <bits/stdc++.h>

using namespace std;
/*
	문자열 폭발 9935번
	https://www.acmicpc.net/problem/9935
	stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input, compare, result = "";
	string temp = "";

	cin >> input >> compare;

	int size = input.size();
	int c_size = compare.size();
	int flag = 0;

	if (c_size == 1) {
		for (int i = 0; i < size; i++) {
			if (input[i] != compare[0]) {
				result.push_back(input[i]);
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (flag == 0) {
				if (input[i] == compare[0]) {
					flag++;
					temp.push_back(input[i]);
				}
				else {
					result.push_back(input[i]);
				}
			}
			else {
				if (input[i] == compare[flag]) {
					temp.push_back(input[i]);
					flag++;
					if (flag == c_size) {
						for (int j = 0; j < c_size; j++) {
							temp.pop_back();
						}
					}
					if (temp.size() > 0) {
						for (int j = 0; j < c_size; j++) {
							if (temp.back() == compare[j]) {
								flag = j + 1;
								break;
							}
						}
					}
					else {
						flag = 0;
					}
				}
				else if (input[i] == compare[0]) {
					temp.push_back(input[i]);
					flag = 1;
				}
				else {
					temp.push_back(input[i]);
					result = result + temp;
					temp.clear();
					flag = 0;
				}
			}
		}
	}
	result = result + temp;

	if (result.size() == 0) {
		cout << "FRULA" << endl;
	}
	else {
		cout << result << endl;
	}
	
	return 0;
}