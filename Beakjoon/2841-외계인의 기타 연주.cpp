#include <bits/stdc++.h>

using namespace std;

/*
	2841번 외계인의 기타 연주
	https://www.acmicpc.net/problem/2841
	stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, P;
	
	int result = 0;
	cin >> N >> P;
	vector<int> stack[6];
	
	for (int i = 0; i < N; i++) {
		int line, pret;
		cin >> line >> pret;
		line--;
		if (stack[line].size() == 0) {
			stack[line].push_back(pret);
			result++;
		}
		else if (stack[line].back() < pret) {
			stack[line].push_back(pret);
			result++;
		}
		else if (stack[line].back() > pret) {
			while (true) {
				if (stack[line].back() > pret) {
					result++;
					stack[line].pop_back();
					if (stack[line].size() == 0) {
						stack[line].push_back(pret);
						result++;
						break;
					}
				}
				else {
					if (stack[line].back() != pret) {
						stack[line].push_back(pret);
						result++;
					}
					break;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}