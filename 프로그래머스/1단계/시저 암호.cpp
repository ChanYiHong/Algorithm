#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char bit : s){
        if(bit == ' ') {answer.push_back(bit); continue;}
        char start;
        if(bit >= 'a' && bit <= 'z'){
            start = 'a';
        }
        if(bit >= 'A'&& bit <= 'Z'){
            start = 'A';
        }
        bit = (bit + n - start)%26 + start;
        answer.push_back(bit);
    }
    return answer;
}