#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p_count = 0; int y_count = 0;
    for(char k : s){
        if(k == 'p' || k == 'P') p_count++;
        if(k == 'y' || k == 'Y') y_count++;
    }
    if(p_count != y_count) answer = false;

    return answer;
}