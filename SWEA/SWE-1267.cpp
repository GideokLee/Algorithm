#include<iostream>
#include<vector>

using namespace std;

void bfs(int s, vector<vector<int>>& array, int state[]) {
    if (state[s] != 0) {
        return;
    }
    state[s] = -1;
    cout << s << " ";
    for (int i = 0; i < array[s].size(); i++) {
        state[array[s][i]]--;
        bfs(array[s][i], array, state);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> array;
        int state[1001] = { 0 };

        for (int i = 0; i <= V; i++) {
            vector<int> temp;
            array.push_back(temp);
        }
        int input1, input2;

        for (int i = 0; i < E; i++) {
            cin >> input1;
            cin >> input2;
            array[input1].push_back(input2);
            state[input2]++;
        }

        vector<int> stack;
        cout << "#" << test_case << " ";
        for (int i = 1; i <= V; i++) {
            if (state[i] == 0) {
                bfs(i, array, state);
            }
        }
        cout << endl;

    }
    return 0;
}