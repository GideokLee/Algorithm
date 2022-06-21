//#include <bits/stdc++.h>
//
//using namespace std;
//
///*
//* 백준 - 성냥개비
//* https://www.acmicpc.net/problem/3687
//* 
//*/
//int dn[1000] = { 0 };
//int dif = 0;
//int result = 9000;
////vector<int> visit(21);
//
//void search(int cnt , string name, string str, int cur, vector<int> visit) {
//	int t = 0;
//	visit[cur] = 1;
//	for (int i = 0; i < 21; i++) {
//		if (visit[i] == 1)
//			t++;
//	}
//	if (t == dif) {
//		if (cnt < result) {
//			result = cnt;
//		}
//		return;
//	}
//	int left = cur;
//	int leftCnt = 0;
//	int rightCnt = 0;
//	int right = cur;
//	while (true) {
//		if (left == 0) {
//			left = name.size() - 1;
//		}
//		else {
//			left--;
//		}
//		leftCnt++;
//		if (visit[left] == 0 && name[left] != str[left]) {
//			search(cnt + leftCnt, name, str, left, visit);
//			break;
//		}
//	}
//	while (true) {
//		if (right == name.size() - 1) {
//			right = 0;
//		}
//		else {
//			right++;
//		}
//		rightCnt++;
//		if (visit[right] == 0 && name[right] != str[right]) {
//			search(cnt + rightCnt, name, str, right, visit);
//			break;
//		}
//	}
//}
//
//int main() {
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios_base::sync_with_stdio(false);
//	int answer = 0;
//	string name = "BBAABAAC";
//	int curser = 0;
//	string str;
//	int check = name.size();
//	
//	for (int i = 0; i < check; i++) {
//		str.push_back('A');
//		if (name[i] != 'A') dif++;
//	}
//
//	if (name[0] == 'A') dif++;
//
//	vector<int> visit(21);
//	if (dif != check)
//		search(0, name, str, 0, visit);
//	else
//		result = check-1;
//
//	for (int i = 0; i < check; i++) {
//		if (str[i] != name[i]) {
//			int left = str[i] - 'A' + 1 + 'Z' - name[i];
//			int right = name[i] - str[i];
//			int tmp = 0;
//			if (left < right) {
//				tmp = left;
//			}
//			else {
//				tmp = right;
//			}
//			str[i] = name[i];
//			answer += tmp;
//		}
//	}
//	answer += result;
//	cout << answer << endl;
//	return 0;
//}