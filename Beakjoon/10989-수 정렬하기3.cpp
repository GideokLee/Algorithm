#include <bits/stdc++.h>

using namespace std;

/*
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	int temp, min = 0;;
	cin >> N;
	int input[100001] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> temp;
		input[temp]++;
		if (min > temp) {
			min = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		if (input[min] > 0) {
			cout << min << "\n";
			input[min]--;
		}
		else {
			for (int i = min + 1; i < 10001; i++) {
				if (input[i] > 0) {
					min = i;
					break;
				}
			}
			cout << min << "\n";
			input[min]--;
		}
	}

	return 0;
}

