#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> compare;
    int cnt = 0;
    int zero = 0;
    int arr[46] = { 0 };
    
    for(int i = 0; i < 6; i ++){
        if(lottos[i] == 0){
            zero++;
        }else{
            compare.push_back(lottos[i]);
        }
        arr[win_nums[i]]++;
    }
    
    for(int i = 0; i < compare.size(); i++){
        if(arr[compare[i]]){
            cnt++;
        }
    }
    
    int min = 7 - (cnt + zero);
    if(cnt + zero < 2){
        min = 6;
    }
    
    int max = cnt;
    if(max < 2){
        max = 6;
    }else{
        max = 7 - max;
    }
    
    answer.push_back( min );
    answer.push_back( max );
    
    return answer;
}