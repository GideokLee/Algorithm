#include <bits/stdc++.h>

using namespace std;

/*
	9012번 괄호
	https://www.acmicpc.net/problem/9012
	stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	
	for (int i = 0; i < T; i++) {
		string input;
		string result = "";

		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			if (result.size() == 0) {
				result.push_back(input[j]);
			}
			else {
				if (input[j] == '(') {
					result.push_back(input[j]);
				}
				else {
					if (result.back() == '(') {
						result.pop_back();
					}
					else {
						result.push_back(input[j]);
					}
				}
			}
		}
		if (result.size() == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}