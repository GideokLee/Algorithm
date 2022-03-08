#include <bits/stdc++.h>

using namespace std;

/*
*/
struct core {
	int i;
	int j;
	int conect = 0;
	int direction = -1;
};

int move_i[4] = { 1,-1, 0, 0 };
int move_j[4] = { 0, 0, -1, 1 };
int N;
int coreNum = 0;
int result = 999999;


void connect(vector<core> a, int arr[12][12], int n, int r, int c) {
	if (n == a.size()) {
		if (c > coreNum) {
			coreNum = c;
			result = r;
		}
		else if (c == coreNum && r < result) {
			result = r;
		}
		return;
	}
	if (c + a.size() - n < coreNum) {
		return;
	}
	
	bool check = false;
	for (int i = 0; i < 5; i++) {
		int temp[12][12] = { 0 };
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[j][k] = arr[j][k];
			}
		}
		if (i == 4) {
			if (check) {
				connect(a, temp, n + 1,r, c);
			}
			break;
		}
		int curr_i = a[n].i;
		int curr_j = a[n].j;
		bool togle = true;
		while (true) {
			curr_i += move_i[i];
			curr_j += move_j[i];
			if (curr_i < 0 || curr_i >= N) break;
			if (curr_j < 0 || curr_j >= N) break;
			if (temp[curr_i][curr_j] != 0) {
				togle = false;
				break;
			}
			temp[curr_i][curr_j] = 2;
			cnt++;
		}
		if (togle) connect(a, temp, n + 1,r + cnt, c + 1);
		else {
			check = true;
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int input[12][12] = { 0 };
		cin >> N;

		vector<core> cores;
		coreNum = 0;
		result = 99999999;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
				if (input[i][j] == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1) {
					core temp;
					temp.i = i;
					temp.j = j;
					cores.push_back(temp);
				}
			}
		}
		connect(cores, input, 0, 0, 0);
		cout << "#" << test_case << " " << result << endl;
		
	}
	return 0;
	
}
