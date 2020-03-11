#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str;
    int small;
    int big;
    int state;
    while(1){
        getline(cin, str);
        if(str == ".") break;
        state = 1;
        stack<char> s;

        for(int j = 0; j < str.length(); j++){
            if(str[j] == '('){
                s.push('(');
            }
            if(str[j] == '['){
                s.push('[');
            }
            if(str[j] == ')'){
                if(s.empty()) {
                    state = 0;
                    break;
                }
                else{
                    if(s.top() != '('){
                        state = 0;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
            }
            if(str[j] == ']'){
                if(s.empty()) {
                    state = 0;
                    break;
                }
                else{
                    if(s.top() != '['){
                        state = 0;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
            }
        }
        if(state == 0 || !s.empty()) cout << "no" << '\n';
        else if(state == 1) cout << "yes" << '\n';
    }

    return 0;
}