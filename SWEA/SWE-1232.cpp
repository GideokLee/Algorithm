#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include <tuple>

using namespace std;


map<int, pair<int, int>> tree;
string alpha[1001];
vector<int> stack;
int result;
void inorder(int node) {//후위순회
    if (tree[node].first != -1) { //왼쪽 자식이 있다면
        inorder(tree[node].first);
    }
    if (tree[node].second != -1) { //오른쪽 자식이 있다면
        inorder(tree[node].second);
    }
    //cout << alpha[node];
    int num1, num2;
    if (alpha[node] == "*") {
        num2 = stack.back();
        stack.pop_back();
        num1 = stack.back();
        stack.pop_back();
        stack.push_back(num1 * num2);
    }
    else if (alpha[node] == "+") {
        num2 = stack.back();
        stack.pop_back();
        num1 = stack.back();
        stack.pop_back();
        stack.push_back(num1 + num2);
    }
    else if (alpha[node] == "-") {
        num2 = stack.back();
        stack.pop_back();
        num1 = stack.back();
        stack.pop_back();
        stack.push_back(num1 - num2);
    }
    else if (alpha[node] == "/") {
        num2 = stack.back();
        stack.pop_back();
        num1 = stack.back();
        stack.pop_back();
        stack.push_back(num1 / num2);
    }
    else {
        stack.push_back(stoi(alpha[node]));
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        string input;
        string trim;
        vector<string> tmp;
        getline(cin, input);
        tree.clear();
        stack.clear();
        for (int i = 0; i < N; i++) {
            tmp.clear();
            getline(cin, input);
            istringstream ss(input);
            while (ss >> trim) {
                tmp.push_back(trim);
            }
            alpha[stoi(tmp[0])] = tmp[1];
            if (tmp.size() == 2) {
                tree[stoi(tmp[0])] = make_pair(-1, -1);
            }
            else if (tmp.size() == 3) {
                tree[stoi(tmp[0])] = make_pair(stoi(tmp[2]), -1);
            }
            else {
                tree[stoi(tmp[0])] = make_pair(stoi(tmp[2]), stoi(tmp[3]));
            }
        }
        cout << "#" << test_case << " ";
        inorder(1);
        cout << stack.back();
        cout << endl;
    }
    return 0;
}