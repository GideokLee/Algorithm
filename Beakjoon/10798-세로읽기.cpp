#include <bits/stdc++.h>

using namespace std;

/*
 세로읽기 10798
 https://www.acmicpc.net/problem/10798

*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input[5];
	string result;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	bool togle = false;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < input[j].size()) {
				togle = true;
				result.push_back(input[j][i]);
			}
		}
		if (!togle) {
			break;
		}
		togle = false;
	}
	cout << result;
	return 0;
}