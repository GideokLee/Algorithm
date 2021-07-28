#include <bits/stdc++.h>

using namespace std;

/*
	쇠막대기 10799번
	https://www.acmicpc.net/problem/10799
	stack
*/

struct stick
{
	int start;
	int end;
};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input;
	vector<int> stack;
	vector<stick> sticks;
	vector<stick> razer;
	int result = 0;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			stack.push_back(i);
		}
		else {
			stick temp;
			temp.start = stack.back();
			temp.end = i;
			if (temp.start == i - 1) {
				razer.push_back(temp);
			}
			else {
				sticks.push_back(temp);
			}
			stack.pop_back();
		}
	}
	int count = 0;
	for (int i = 0; i < sticks.size(); i++) {
		count = 0;
		for (int j = 0; j < razer.size(); j++) {
			if (razer[j].start > sticks[i].start && razer[j].end < sticks[i].end) {
				count++;
			}
		}
		result = result + count + 1;
	};
	cout << result << endl;

	return 0;
}