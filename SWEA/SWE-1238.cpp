#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int start;
        cin >> N >> start;
        int input[101][101] = { 0 };
        int result = 0;
        int temp, temp2;
        int visit[101] = { 0 };
        queue<int> que;
        que.push(start);

        for (int i = 0; i < N / 2; i++) {
            cin >> temp;
            cin >> temp2;
            input[temp][temp2] = 1;
        }
        int curr;

        while (true) {
            int size = que.size();
            temp = 0;
            for (int i = 0; i < size; i++) {
                curr = que.front();
                que.pop();
                visit[curr] = 1;
                if (curr > temp) temp = curr;
                for (int j = 1; j < 101; j++) {
                    if (input[curr][j] == 1 && visit[j] == 0) {
                        que.push(j);
                        visit[j] = 1;
                    }
                }
            }
            if (temp > 0) result = temp;
            if (que.empty()) {
                break;
            }
        }
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}