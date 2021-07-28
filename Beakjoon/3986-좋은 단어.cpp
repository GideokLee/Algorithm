#include <bits/stdc++.h>

using namespace std;

/*
	좋은 단어 3986번
	https://www.acmicpc.net/problem/3986
	stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string input;
		string result = "";

		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			if (result.size() == 0) {
				result.push_back(input[j]);
			}
			else {
				if (result.back() == input[j]) {
					result.pop_back();
				}
				else {
					result.push_back(input[j]);
				}
			}
		}

		if (result.size() == 0) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}