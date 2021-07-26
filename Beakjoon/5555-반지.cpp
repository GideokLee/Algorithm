#include <bits/stdc++.h>

using namespace std;

/*
	반지 5555번
	https://www.acmicpc.net/problem/5555
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int size, flag, N, f_index, result = 0;
	int s_index;
	string search, input;
	cin >> search >> N;
	size = search.size();
	for (int i = 0; i < N; i++) {
		cin >> input;
		flag = 0;

		for (int j = 0; j < input.size(); j++) {
			if (search[0] == input[j]) {
				f_index = j;
				for (int k = 0; k < size; k++) {
					if (k != 0 && f_index == j) {
						break;
					}
					if (search[k] == input[f_index++]) {
						flag++;
					}
					else {
						break;
					}
					if (f_index == input.size()) {
						f_index = 0;
					}
				}
			}
			if (flag == size) {
				result++;
				break;
			}
			flag = 0;
		}
	}
	cout << result;
	return 0;
}