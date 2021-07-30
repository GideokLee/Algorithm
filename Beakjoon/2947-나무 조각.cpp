#include <bits/stdc++.h>

using namespace std;

/*
	나무조각 2947번
	https://www.acmicpc.net/problem/2947
	binary sort

*/

void printArray(int input[]) {

	for (int i = 0; i < 5; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);


	int input[5];
	int temp;
	int count = 0;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	while (true) {
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (input[i] > input[i + 1]) {
				temp = input[i];
				input[i] = input[i + 1];
				input[i+1] = temp;
				printArray(input);
				count++;
			}
		}
		if (count == 0) break;
	}
	

	return 0;
}