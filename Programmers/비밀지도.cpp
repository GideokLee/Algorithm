#include <bits/stdc++.h>

using namespace std;

/*
* 비밀 지도
* https://www.acmicpc.net/problem/3687
* 
*/

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int temp1;
    for(int i =0; i < n; i ++){
        temp1 = arr1[i] | arr2[i];
        string r;
        while (temp1 > 0)
        {    
            if(temp1 % 2){
                r.push_back('#');
            }else {
                r.push_back(' ');
            }
            temp1 /= 2;
        }
        int size = n - r.length();

        for(int j = 0; j < size; j++){
            r.push_back(' ');
        }

        answer.push_back(r);
        reverse(answer[i].begin(), answer[i].end());
    }

    return answer;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
    vector<int> arr1;
    vector<int> arr2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        arr1.push_back(input);
    }
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        arr2.push_back(input);
    }
    vector<string> answer;
    answer = solution(n, arr1, arr2);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

	return 0;
}