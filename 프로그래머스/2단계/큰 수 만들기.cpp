#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length() - k;
    int start = 0;
    int index = 0;
    
    for(int i = len; i > 0; i--){
        int maxnum = 0;
        for(int j = start; j < number.length() - i + 1; j++){
            int num = number[j] - '0';
            
            if(maxnum < num){
                index = j;
                maxnum = num;
            }
        }    
        answer += number[index];
        start = index + 1;
        if(start >= number.length() - i + 1) break;
    }
    
    for(int i = start; i < number.length(); i++){
        answer += number[i];
    }
    
    return answer;
}