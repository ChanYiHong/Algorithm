#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    for(char k : s){
        if(!(k >= '0'&& k <= '9')) {answer = false; break;}
    }
    if(!(s.length() == 4 || s.length() == 6)) answer = false;
    return answer;
}