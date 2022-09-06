#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> num;
    vector<char> option;

    char bonus[3] = {'S', 'D', 'T'};
    int temp = 0;
    
    for(int i =0; i < dartResult.size(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            temp = dartResult[i] - '0';
            if(dartResult[i + 1] == '0'){
                temp = 10;
                i++;
            }
            num.push_back(temp);
        }else{
            int size = num.size();
            if(dartResult[i] == '*'){
                for(int j = size - 1; j > size - 3; j--){
                    num[j] *= 2;
                    if(j == 0) break;
                }
            }else if(dartResult[i] == '#'){
                num[ size - 1 ] *= -1;
            }else{
                temp = num.back();
                for(int j = 0; j < 3; j++){
                    if(dartResult[i] == bonus[j]) break;
                    num[num.size() -1 ] *= temp;
                }
            }
        }
    }
    
    for(int i = 0; i < num.size(); i++){
        answer += num[i];
    }

    return answer;
}

int main(){
    string dartResult = "1D2S#10S";
    cout << solution(dartResult) << endl;
    return 0;
}