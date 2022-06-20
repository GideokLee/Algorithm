#include <bits/stdc++.h>

using namespace std;

/*

*/


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string R = "SSSSAAA";
	int size = R.size();
	int pre = 0;
	int curr = 0;
	int result = 0;

	for (int i = 0; i < R.size(); i++) {
		if (R[i] == 'A') {
			pre += 20;
			curr += 5;
		}
		else {
			pre += 30;
			curr += 40;
		}
		if (pre > curr) {
			pre = curr;
		}
	}

	if (pre < curr) {
		result = pre;
	}
	else {
		result = curr;
	}

	cout << result << endl;

	return 0;
}