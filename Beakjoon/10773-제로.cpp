#include <bits/stdc++.h>

using namespace std;

/*
	제로 10773번
	https://www.acmicpc.net/problem/10773
	stack
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;
	int* input = new int[K];
	int size = 0;
	int temp;


	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) {
			size--;
		}
		else {
			input[size++] = temp;
		}
	}
	int result = 0;
	for (int i = 0; i < size; i++) {
		result = result + input[i];
	}
	cout << result << endl;

	return 0;
}