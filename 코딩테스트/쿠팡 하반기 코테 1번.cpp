#include <string>
#include <vector>

using namespace std;
int NUM;

vector<int> number(int division){

    vector<int> ret;
    vector<int> each_number;
    int n = NUM;
    int remainder;

    while(n > 0){
        int remainder = n % division;
        each_number.push_back(remainder);
        n /= division;
    }

    int multi = 1;
    for(auto each : each_number){
        if(each == 0) continue;
        multi *= each;
    }

    ret.push_back(division);
    ret.push_back(multi);

    return ret;
}

vector<int> solution(int N) {
    vector<int> answer(2, 0);
    NUM = N;

    for(int i = 2; i <= 9; i++){
        vector<int> ret = number(i);
        if(ret[1] >= answer[1]){
            answer[0] = ret[0];
            answer[1] = ret[1];
        }
    }

    return answer;
}