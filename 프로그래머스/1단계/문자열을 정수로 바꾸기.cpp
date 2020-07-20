#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s[0] == '-' || s[0] == '+') {
        int index = 1;
        for(int i = s.length()-2; i >= 0; i--){
            int num = s[index] - '0';
            answer += num * pow(10, i);
            index++;
        }
        if(s[0] == '-') answer *= (-1);
    }
    else {
        int index = 0;
        for(int i = s.length()-1; i >= 0; i--){
            int num = s[index] - '0';
            answer += num * pow(10, i);
            index++;
        }
    }
    
    return answer;
}