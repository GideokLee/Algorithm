#include <bits/stdc++.h>

using namespace std;

/*
	크로스워드 1706번
	https://www.acmicpc.net/problem/1706
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int C, R;
	string input[20];
	string result = "1";
	string temp;

	cin >> C >> R;

	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}
	int flag = 0;

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (input[i][j] != '#') {
				flag++;
			}
			else {
				if (flag > 1) {
					temp = input[i].substr(j - flag, flag);
					if (result.size() == 1) {
						result = temp;
					}
					else {
						if (result > temp) {
							result = temp;
						}
					}
				}
				flag = 0;
			}
		}
		if (flag > 1) {
			temp = input[i].substr(R - flag, flag);
			if (result.size() == 1) {
				result = temp;
			}
			else {
				if (result > temp) {
					result = temp;
				}
			}
		}
		flag = 0;
	}
	flag = 0;
	for (int i = 0; i < R; i++) {
		temp.clear();
		for (int j = 0; j < C; j++) {
			if (input[j][i] != '#') {
				temp.push_back(input[j][i]);
				flag++;
			}
			else {
				if (flag > 1) {
					if (result.size() == 1) {
						result = temp;
					}
					else {
						if (result > temp) {
							result = temp;
						}
					}
				}
				temp.clear();
				flag = 0;
			}
		}
		if (flag > 1) {
			if (result.size() == 1) {
				result = temp;
			}
			else {
				if (result > temp) {
					result = temp;
				}
			}
		}
		flag = 0;
	}

	cout << result << endl;
	return 0;
}