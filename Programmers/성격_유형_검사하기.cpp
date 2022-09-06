#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map<string,int> score;

    string setting[8] = {"R", "T", "C" , "F", "J", "M", "A", "N"};
    for(int i =0; i < 8; i ++){
        score.insert({setting[i], 0});
    }


    for(int i =0; i < n; i++){
        string r;
        int temp;
        if(choices[i] == 0 ) continue;

        if(choices[i] > 4){
            r = survey[i].front();
            temp = 4 - choices[i];
        }else {
            r = survey[i].back();
            temp = choices[i] - 4;
        }
        score[r] += temp;
    }

    string result[4] = {"RT", "CF", "JM", "AN"};
    
    for(int i =0; i < 4; i++){

        if(score[result[i].substr(0,1)] >= score[result[i].substr(1,1)]){
            answer.push_back(result[i].front());
        }else{
            answer.push_back(result[i].back());
        } 
    }
    return answer;
}


int main() {

    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices = {5, 3, 2, 7, 5};
    string result = solution(survey, choices);

    cout << result << endl;
    return 0;
}