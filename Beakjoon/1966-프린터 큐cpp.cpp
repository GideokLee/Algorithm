#include <bits/stdc++.h>

using namespace std;

/*
	프린터 큐 1966번
	https://www.acmicpc.net/problem/1966
	queue
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int T;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		int queue[1000];
		int size = 0;
		int N, M;
		cin >> N >> M;

		int front = 0;
		int max = 0;
		int back = N - 1;
		int stack[10] = { 0 };

		for (int k = 0; k < N; k++) {
			cin >> queue[k];
			if (queue[k] > max) {
				max = queue[k];
			}
			stack[queue[k]]++;
		}
		int count = 0;

		while (true) {
			if (queue[front] < max) {
				if (front == M) {
					M = back + 1;
				}
				queue[++back] = queue[front++];
			}
			else if (queue[front] >= max){
				count++;
				stack[queue[front]]--;
				if (stack[max] == 0) {
					for (int j = max; j > 0; j--) {
						if (stack[j] > 0) {
							max = j;
							break;
						}
					}
				}
				if (front == M) break;
				front++;
				size--;
			}
		}
		cout << count << endl;
	}
	return 0;
}