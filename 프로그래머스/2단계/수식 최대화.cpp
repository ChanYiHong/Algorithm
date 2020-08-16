#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
vector<char> operand;
vector<int> number;

char sequence[6][3] = {
    {'*', '+', '-'},
    {'*', '-', '+'},
    {'+', '*', '-'},
    {'+', '-', '*'},
    {'-', '*', '+'},
    {'-', '+', '*'} 
};

long long calculate(int a, int b, char c){
    //cout << a << " " << c << " " << b << '\n';
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    
    return -1;
}

long long makeAnswer(int seq){
    
    char op[3] = {sequence[seq][0], sequence[seq][1], sequence[seq][2]};
    
    vector<int> num = number;
    vector<char> oper = operand;
    vector<bool> check(num.size(), false);
    
    bool isFirst = true;
    long long ret = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < oper.size(); j++){
            if(oper[j] == op[i]){
                
                if(isFirst){
                    cout << num[j] << oper[j] << num[j+1] << '\n';
                    ret = calculate(num[j], num[j+1], op[i]);
                    check[j] = true;
                    check[j+1] = true;
                    isFirst = false;
                }
                else{
                    if(check[j]){
                        cout << ret << oper[j] << num[j+1] << '\n';
                        ret += calculate(ret, num[j+1], op[i]);
                        check[j+1] = true;
                    }else if(check[j+1]){
                        cout << num[j] << oper[j] << ret << '\n';
                        ret += calculate(num[j], ret, op[i]);
                        check[j] = true; 
                    }else if(!check[j] && !check[j+1]){
                        cout << num[j] << oper[j] << ret << '\n';
                        ret += calculate(num[j], ret, op[i]);
                        check[j] = true; 
                    }
                }
            }
        }
    }
    
    return ret;
}

long long solution(string expression) {
    long long answer = 0;
    int last = 0;
    for(int i = 0; i < expression.length(); i++){
        char cur = expression[i];
        if(cur == '+' || cur == '-' || cur == '*'){
            string num = expression.substr(last, i - last);
            int n = stoi(num);
            number.push_back(n);
            //piece.push_back(expression.substr(last, i - last));
            operand.push_back(expression.substr(i, 1)[0]);
            last = i+1;
        }
        if(!expression[i+1]){
            string num = expression.substr(last, (i+1) - last);
            int n = stoi(num);
            number.push_back(n);
            //piece.push_back(expression.substr(last, (i+1) - last));
        }
    }
    
//     for(int num : number){
//         cout << num <<'\n';
//     }
    
//     for(char str : operand){
//         cout << str <<'\n';
//     }
    
    vector<long long> ret;
    for(int i = 0; i < 6; i++){
        long long ans = makeAnswer(i);
        if(ans < 0) ans = abs(ans);
        cout << ans << '\n';
        ret.push_back(ans);
    }
    
    answer = *max_element(ret.begin(), ret.end());
    
    return answer;
}