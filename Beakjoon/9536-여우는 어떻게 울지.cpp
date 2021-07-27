#include <bits/stdc++.h>

using namespace std;

/*
	여우는 어떻게 울지? 9536번
	https://www.acmicpc.net/problem/9536
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input;
	int T, n = 0;

	cin >> T;
	getline(cin, input);
	while (T--) {
		string sounds[100];
		string temp;
		n = 0;
		getline(cin, input);
		int pos = 0;
		for (int i = 0; i < 100; i++) {
			getline(cin,sounds[i]);
			if (sounds[i].back() == '?') {
				break;
			}
			if (sounds[i].find("goes") != string::npos) {
				sounds[i].erase(0, sounds[i].find("goes") +5);
			}
			n++;
		}
		int f_index = 0, s_index;
		bool check = true;
		for (int i = 0; i < 100; i++) {
			check = true;
			s_index = input.find(' ', f_index);
			for (int i = 0; i < n; i++) {
				if (input.substr(f_index, s_index - f_index) == sounds[i]) {
					check = false;
					break;
				}
			}
			if (check) {
				cout << input.substr(f_index, s_index - f_index) << " ";
			}
			f_index = s_index + 1 ;
			if (s_index == -1) break;
		}
		cout << endl;
	}



	return 0;
}