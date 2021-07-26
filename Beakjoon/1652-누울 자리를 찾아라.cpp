#include <bits/stdc++.h>

using namespace std;

/*
	누울 자리를 찾아라 1652번
	https://www.acmicpc.net/problem/1652
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N; // NxN
	string input[100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int countX = 0 , countY =0;
	int resultX = 0, resultY = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == '.') {
				countX++;
			}
			else if(input[i][j] == 'X'){
				if (countX > 1) {
					resultX++;
				}
				countX = 0;
			}
			if (input[j][i] == '.') {
				countY++;
			}
			else if(input[j][i] == 'X'){
				if (countY > 1) {
					resultY++;
				}
				countY = 0;
			}
		}
		if (countX > 1) {
			resultX++;
		}
		if (countY > 1) {
			resultY++;
		}
		countX = 0;
		countY = 0;
	}

	cout << resultX << " " << resultY;

	return 0;
}