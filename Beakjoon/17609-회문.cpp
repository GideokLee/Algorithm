#include <bits/stdc++.h>

using namespace std;

/*
	회문 17609번
	https://www.acmicpc.net/problem/17609
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	string input[30];

	for (int i = 0; i < T; i++) {
		cin >> input[i];
	}

	int s_index, f_index;
	int cases, size;
	for (int i = 0; i < T; i++) {
		size = input[i].size();
		cases = 0;
		for (int j = 0; j < size / 2 ; j++) {
			if (input[i][j] != input[i][size - j - 1]) {
				cases = 2;
				f_index = j;
				s_index = size - j - 1;
				break;
			}
		}
		
		if (cases != 0) {
			int t_index = f_index + ((s_index - f_index) / 2);
			for (int j = f_index; j <= t_index; j++) {
				if (input[i][j+1] == input[i][size - j -1]) {
					cases = 1;
				}
				else {
					cases = 2;
					break;
				}
			}
			if (cases == 2) {
				for (int j = f_index; j <= t_index; j++) {
					if (input[i][j] == input[i][size - j - 2]) {
						cases = 1;
					}
					else {
						cases = 2;
						break;
					}
				}
			}
		}
		cout << cases <<  endl;
	}

	return 0;
}