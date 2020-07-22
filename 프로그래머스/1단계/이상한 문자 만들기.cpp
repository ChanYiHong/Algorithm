#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for(char c : s){
        if(c == ' ') {answer.push_back(c); index = 0; continue;}
        if(index % 2 == 0) {
            if(c >= 'a' && c <= 'z') c -= 32; 
            answer.push_back(c);
        }
        else {
            if(c >= 'A' && c <= 'Z') c += 32; 
            answer.push_back(c);
        }
        
        index++;
    }
    return answer;
}