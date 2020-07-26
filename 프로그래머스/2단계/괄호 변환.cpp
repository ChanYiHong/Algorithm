#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isPerfect(string& str){
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') {
            count++;
        }
        if(str[i] == ')') {
            count--;
        }
        if(count < 0){
            return false;
        }
    }
    return true;
}

string fourStep(string& u, string& v){
    string ret = "(";
    ret += v;
    ret += ")";
    
    // U 의 앞뒤 제거
    u = u.substr(1);
    u = u.substr(0, u.length() - 1);
    
    // u의 나머지 다 거꾸로
    for(int i = 0; i < u.length(); i++){
        if(u[i] == '(') u[i] = ')';
        else if(u[i] == ')') u[i] = '(';
    }
    
    ret += u;
    
    cout << "step 4 : " << ret << '\n';
    return ret;
}

string makeAnswer(string& str){
    
    if(str.length() == 0) {cout << "빈칸입니다" << '\n'; return "";}
    
    int count = 0;
    bool isBalanced = true;
    int open = 0;
    int close = 0;
    
    string u ="";
    string v ="";
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') {
            open++;
            count++;
        }
        if(str[i] == ')') {
            close++;
            count--;
        }
        // u가 균형잡힌 괄호 라는 뜻.
        if(count == 0){
            u = str.substr(0, i+1);
            v = str.substr(i+1);
            cout << "u : " << u << '\n';
            cout << "v : " << v << '\n';
            string three = "";
            string four = "";
            
            // 3단계, u가 "올바른 괄호 문자열이면 3-1 수행"
            if(isPerfect(u)){
                cout << "if (u가 올바른 문자열)" << '\n';
                three = makeAnswer(v);
                cout << "3step : " << three << '\n';
            }
            // 4단계, 이어붙인 u가 올바른 괄호 문자열이 아니라면
            else{
                cout << "else (u가 올바르지 않음)" << '\n';
                three = makeAnswer(v);
                four = fourStep(u, three);
                cout << "4step : " << four << '\n';
                return four;
            }
            u += three;
            cout << "u (결과): " << u << '\n';
            break;
        }
    }
    return u;
}

string solution(string p) {
    string answer = "";    
    answer = makeAnswer(p);
    
    return answer;
}