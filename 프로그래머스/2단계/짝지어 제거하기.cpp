/**
이건 완전탐색으로 while 문 쓰니까 시간 초과가 난다.
stack 자료형을 쓴다면 새로운 원소를 넣을 때 가장 최근에 넣은 것이 스택 맨 위에 있으므로
그것과 비교해서 같다면 pop을 시켜버린다면 "abba" 같은 문자열도 한꺼번에 소거가능
**/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    for(char k : s){
        if(stk.empty() || stk.top() != k){
            stk.push(k);
        }
        else{
            stk.pop();
        }
    }
    return stk.size() == 0 ? 1 : 0;
}