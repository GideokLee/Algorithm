#include <bits/stdc++.h>

using namespace std;

/*
	신규 아이디 추천
	https://school.programmers.co.kr/learn/courses/30/lessons/72410
*/

int solution(string s) {
	int answer = 0;
	string temp;
	string number[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer = answer * 10 + (s[i] - '0');
		}
		else {
			temp.push_back(s[i]);
		}
		if (temp.size() > 0) {
			for (int j = 0; j < 10; j++) {
				if (number[j] == temp) {
					answer = answer * 10 + j;
					temp.erase();
					break;
				}
			}
		}
	}

	return answer;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string new_id = "23four5six7";
	cout << solution(new_id) << endl;

	return 0;
}

