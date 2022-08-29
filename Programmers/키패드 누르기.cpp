#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Num{
    int i;
    int j;
    int num;
    Num(int I, int J, int Num) : i(I), j(J), num(Num) {}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int length = numbers.size();
    vector<Num> pad;
    int cnt = 1;
    pad.push_back(Num(3,1,0));
    
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 3; j ++){
            if(i == 3 && j == 1) continue;
            Num temp(i,j,cnt++); 
            pad.push_back(temp);
        }
    }
    
    Num L(3,0,10);
    Num R(3,2,12);
    bool direct = true; // left == true
    for(int i = 0; i < length; i++){
        switch(numbers[i]){
            case 1:
            case 4:
            case 7:
                direct = true;
                break;
            case 3:
            case 6:
            case 9:
                direct = false;
                break;
            default:
                int dl = abs(L.i - pad[numbers[i]].i) + abs(L.j - pad[numbers[i]].j);
                int dr = abs(R.i - pad[numbers[i]].i) + abs(R.j - pad[numbers[i]].j);
                if(dl > dr){
                    direct = false;
                }else if(dl < dr){
                    direct = true;
                }else{
                    if(hand == "left"){
                        direct = true;
                    }else{
                        direct = false;
                    }
                }
                break;
        }
        if(direct){
            answer+="L";
            L = pad[numbers[i]];
        }else{
            answer+="R";
            R = pad[numbers[i]];
        }
    }
    
    return answer;
}