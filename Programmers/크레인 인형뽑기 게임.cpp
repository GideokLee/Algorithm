#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    vector<int> stack;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < size; j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (!stack.empty() && stack.back() == board[j][moves[i] - 1]) {
                    stack.pop_back();
                    answer += 2;
                }
                else {
                    stack.push_back(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }


    return answer;
}