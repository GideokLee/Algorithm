
#include<iostream>
#include <queue>

using namespace std;

struct node {
    int x;
    int y;
};

int main(int argc, char** argv)
{
    int test_case;
    int T;

    T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        queue<node> que;
        string input;
        int inputs[16][16] = { 0 };
        node start;
        node end;
        int move_x[4] = { 1, -1 , 0 , 0 };
        int move_y[4] = { 0, 0, -1, 1 };
        int result = 0;
        cin >> result;
        result = 0;
        for (int i = 0; i < 16; i++) {
            cin >> input;
            for (int j = 0; j < 16; j++) {
                inputs[i][j] = input[j] - '0';
                if (inputs[i][j] == 2) {
                    start.x = i;
                    start.y = j;
                    que.push(start);
                }
                else if (inputs[i][j] == 3) {
                    end.x = i;
                    end.y = j;
                }
            }
        }
        while (true) {

            node curr;
            curr.x = que.front().x;
            curr.y = que.front().y;
            que.pop();
            inputs[curr.x][curr.y] = 1;

            for (int i = 0; i < 4; i++) {
                if (curr.x + move_x[i] < 0 || curr.x + move_x[i] >= 16) {
                }
                else if (curr.y + move_y[i] < 0 || curr.y + move_y[i] >= 16) {
                }
                else if (inputs[curr.x + move_x[i]][curr.y + move_y[i]] == 0) {
                    node push;
                    push.x = curr.x + move_x[i];
                    push.y = curr.y + move_y[i];
                    que.push(push);
                }
                else if (inputs[curr.x + move_x[i]][curr.y + move_y[i]] == 3) {
                    result = 1;
                    break;
                }
            }
            if (result == 1 || que.empty()) break;
        }
        cout << "#" << test_case << " " << result << endl;
    }

    return 0;
}