#include <bits/stdc++.h>

using namespace std;

/*
	½ÇÆÐÀ²
	https://school.programmers.co.kr/learn/courses/30/lessons/42889
*/
class Stage {
public:
    double f;
    int n;

    Stage(double f, int n) {
        this->f = f;
        this->n = n;
    }
};

bool compare(Stage a, Stage b) {
    if (a.f == b.f) {
        return a.n < b.n;
    }
    else {
        return a.f > b.f;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int curr = 0;
    int clear[502] = { 0 };
    int temp = stages.size();
    int size = stages.size();

    vector<Stage> t;

    for (int i = 0; i < stages.size(); i++) {
        clear[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        curr = clear[i];
        double f = 0.0;
        if (curr != 0 && temp != 0) {
            f = (double)curr / temp;
        }
        Stage stage = Stage(f, i);
        t.push_back(stage);
        temp -= curr;
    }
    sort(t.begin(), t.end(), compare);

    for (int i = 0; i < t.size(); i++) {
        answer.push_back(t[i].n);
    }

    return answer;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int N = 5;
    vector<int> stages;
    vector<int> answer;

    for (int i = 0; i < 8; i++) {
        int temp;
        cin >> temp;
        stages.push_back(temp);
    }

    answer = solution(N,stages);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " "; 
    }
    cout << endl;

	return 0;
}

