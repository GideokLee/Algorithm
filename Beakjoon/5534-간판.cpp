#include <bits/stdc++.h>

using namespace std;

/*
	간판 5534번
	https://www.acmicpc.net/problem/5534
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, scale, size, flag, result= 0;
	string search, input;

	cin >> N >> search;

	while (N--) {
		cin >> input;
		size = input.size();
		scale = 1;
		flag = 1;

		while (search.size() + scale * ( search.size() -1 ) <= 100) {
			for (int i = 0; i < size; i++) {
				if (search[0] == input[i]) {
					flag = 1;
					for (int j = 1; j < search.size(); j++) {
						if (i + j * scale >= size) {
							break;
						}
						if (search[j] == input[i + ( j * scale )]) {
							flag++;
						}
						else {
							break;
						}
					}
				}
				if (flag == search.size()) {
					result++;
					break;
				}
			}
			if (flag == search.size()) break;
			scale++;
		}
	}

	cout << result;
	return 0;
}