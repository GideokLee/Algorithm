#include <bits/stdc++.h>

using namespace std;

/*
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int input[1000] = { 0 };
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (input[i] > input[j]) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << input[i] << endl;
	}

	return 0;
}

