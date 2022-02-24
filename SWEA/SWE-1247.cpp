#include <bits/stdc++.h>

using namespace std;


struct node {
    int x;
    int y;
    int visit = 0;
};

int N;
int result = 9999;

void visitNode(node curr, int r, vector<node> input, int n) {
    bool togle = true;
    if (r >= result) return;
    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i].visit == 0) {
            input[i].visit = 1;
            int x = input[i].x - curr.x;
            int y = input[i].y - curr.y;
            if (x < 0) x *= -1;
            if (y < 0) y *= -1;
            togle = false;
            visitNode(input[i], r + x + y, input, n + 1);
            input[i].visit = 0;
        }
    }
    if (togle && n == N) {
        int x = input.back().x - curr.x;
        int y = input.back().y - curr.y;
        if (x < 0) x *= -1;
        if (y < 0) y *= -1;
        r = r + x + y;
        if (r < result) {
            result = r;
        }
        return;
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int test_case;

    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        cin >> N;
        node start;
        node end;
        cin >> start.x >> start.y;
        cin >> end.x >> end.y;
        vector<node> input;
        result = 999999;
        for (int i = 0; i < N; i++) {
            node temp;
            cin >> temp.x >> temp.y;
            temp.visit = 0;
            input.push_back(temp);
        }
        input.push_back(end);
        visitNode(start, 0, input, 0);
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}

