#include <bits/stdc++.h>

using namespace std;

/*
	신규 아이디 추천
	https://school.programmers.co.kr/learn/courses/30/lessons/72410
*/

string solution(string new_id) {
	string answer = "";
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
			new_id[i] += 32;
		}
	}

	string temp;

	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'a' && new_id[i] <= 'z') {
		}
		else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
		}
		else if (new_id[i] >= '0' && new_id[i] <= '9') {
		}
		else {
			continue;
		}
		if (!temp.empty() && temp.back() == '.' && new_id[i] == '.') {
			continue;
		}
		temp.push_back(new_id[i]);
	}

	if (temp.front() == '.' && temp.back() == '.') {
		new_id = temp.substr(1, temp.size()-2);
	}
	else if (temp.front() == '.' ) {
		new_id = temp.substr(1, temp.size());
	}
	else if (temp.back() == '.') {
		new_id = temp.substr(0, temp.size() - 1);
	}
	else {
		new_id = temp;
	}

	if (new_id.empty()) {
		new_id = "a";
	}

	if (new_id.size() >= 16) {
		temp = new_id.substr(0, 15);
		while (temp.back() == '.')
		{
			temp.pop_back();
		}
		new_id = temp;
	}

	if (new_id.size() <= 2) {
		for (int i = new_id.size(); i < 3; i++) {
			new_id.push_back(new_id.back());
		}
	}

	answer = new_id;

	return answer;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string new_id = "...!@BaT#*..y.abcdefghijklm";
	cout << solution(new_id) << endl;

	return 0;
}

