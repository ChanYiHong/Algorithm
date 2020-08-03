#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> s;
    
    while(n > 0){
        int temp = n % 3;
        s.push(temp);
        
        if(temp == 0){
            n /= 3;
            n--;
        } else{
            n /= 3;
        }
    }
    
    while(!s.empty()){
        int top = s.top();
        if(top == 1) answer+="1";
        if(top == 2) answer+="2";
        if(top == 0) answer+="4";
        s.pop();
    }
    
    return answer;
}