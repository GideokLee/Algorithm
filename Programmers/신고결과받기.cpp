#include <bits/stdc++.h>

using namespace std;

/*
	신고 결과 받기
	https://school.programmers.co.kr/learn/courses/30/lessons/92334
*/

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	int id_size = id_list.size();
	int r_size = report.size();

	vector<set<string>> r_set;
	vector<set<string>> r_set2;
	map<string, int> index;
	for (int i = 0; i < id_size; i++) {
		answer.push_back(0);
		set<string> temp;
		r_set.push_back(temp);

		set<string> temp2;
		r_set2.push_back(temp2);

		index.insert({ id_list[i], i });
	}

	//sort(report.begin(), report.end());

	for (int i = 0; i < r_size; i++) {
		int spot = report[i].find(" ");
		string key = report[i].substr(0, spot);
		string val = report[i].substr(spot + 1, report[i].length());
		int curr = index[key];
		r_set[curr].insert(val);
		curr = index[val];
		r_set2[curr].insert(key);
	}

	for (int i = 0; i < id_size; i++) {
		for (auto iter = r_set[i].begin(); iter != r_set[i].end(); ++iter) {
			int curr = index[*iter];
			if (r_set2[curr].size() >= k) {
				answer[i]++;
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	return answer;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<string> id_list;
	vector<string> report;
	int k = 3;
	vector<int> answer;
	for (int i = 0; i < 2; i++) {
		string temp;
		cin >> temp;
		id_list.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		string temp, temp2;
		cin >> temp >> temp2;
		report.push_back(temp+ " " + temp2);
	}

	answer = solution(id_list, report, k);


	
	return 0;
}

