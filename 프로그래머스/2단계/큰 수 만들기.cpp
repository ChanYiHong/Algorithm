#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length();
    int req = len - k;
    int start = 0;
    int index = 0;
    int current_answer_length = 0;
    
    while(k > 0){
        int maxnum = -1;
        int end = len - (req - current_answer_length - 1);
        for(int j = start; j < end; j++){
            int num = number[j] - '0';
            if(maxnum < num){
                index = j;
                maxnum = num;
            }
        }    
        answer += number[index];
        k = k - (index - start);
        start = index + 1;
        index = start;
        current_answer_length++;
        if(current_answer_length == req) break;
    }
    
    if(req != current_answer_length){
        for(int i = start; i < number.length(); i++){
            answer += number[i];
        }
    }
    
    return answer;
}