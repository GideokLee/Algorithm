#include <bits/stdc++.h>

using namespace std;

/*
	시리얼 번호 1431번
	https://www.acmicpc.net/problem/1431
	string compare
	sort
*/

bool compare(string a, string b) {
	int a_size = a.size();
	int b_size = b.size();
	int a_sum = 0, b_sum = 0;
	bool check = true;
	bool result = true;
	if (a_size == b_size ){
		for (int i = 0; i < a_size; i++) {
			if (a[i] >= 48 && a[i] < 58) {
				a_sum = a_sum + (a[i] - 48);
			}
			if (b[i] >= 48 && b[i] < 58) {
				b_sum = b_sum + (b[i] - 48);
			}
			if (a[i] != b[i] && check) {
				result = (int)a[i] < b[i];
				check = false;
			}
		}
		if (a_sum == b_sum) {
			return result;
		}
		else {
			return a_sum < b_sum;
		}
	}
	else {
		return a_size < b_size;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> serials;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		serials.push_back(input);
	}

	sort(serials.begin(), serials.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << serials[i] << endl;
	}

	return 0;
}