#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> checkA;
vector<bool> check;
int cnt = 0;
string str;

void joystick(int index){
    
    char current = str[index];
    check[index] = true;
    int cur = current;
    
    if(current - 'A' < 13){
        cnt += current - 'A';
    }
    else{
        cnt += 'Z' - current + 1;
    }
    
    int next = 1;
    bool right = false;
    bool left = false;
    while(1){
        if(index + next < str.length()){
            if(!check[index + next] && !checkA[index + next]){
                check[index + next] = true;
                right = true;
                break;
            }
        }
        if(index - next >= 0){
            if(!check[index - next] && !checkA[index - next]){
                check[index - next] = true;
                left = true;
                break;
            }
        }
        if(index - next < 0){
            if(str.length() + (index - next) >= 0){
                if(!check[str.length() + (index - next)] && !checkA[str.length() + (index - next)]){
                    check[str.length() + (index - next)] = true;
                    left = true;
                    break;
                }
            }
        }
        if(next == str.length()) break;
        next++;
    }
    
    if(right){
        cnt += next;
        joystick(index + next);
    }
    else if(left){
        cnt += next;
        if(index - next >= 0){
            joystick(index - next);
        }
        else{
            joystick(str.length() + (index - next));
        }
    }
    else{
        return;
    }
    
}

int solution(string name) {
    int answer = 0;
    
    str = name;
    check.resize(name.length(), false);
    checkA.resize(name.length(), false);
    
    int index = 0;
    for(char n : name){
        if(n == 'A'){
            check[index] = true;
        }
        index++;
    }
    
    joystick(0);
    
    answer = cnt;
    
    return answer;
}