#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    bool minus = false;
    int start = 0;
    int cnt = 0;
    bool front = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-'){
            minus = true;
            continue;
        }
        if(front){
            start = i;
            front = false;
        }
        if(s[i] == ' '){
            string temp = s.substr(start, cnt);
            int num = stoi(temp);
            if(minus){
                num *= -1;
                minus = false;
            }
            v.push_back(num);
            cnt = 0;
            front = true;
        }
        cnt++;
    }
    string temp = s.substr(start, cnt);
    int num = stoi(temp);
    if(minus){
        num *= -1;
        minus = false;
    }
    v.push_back(num);
    
    
    int max_num = *max_element(v.begin(), v.end());
    int min_num = *min_element(v.begin(), v.end());
    
    answer += to_string(min_num);
    answer += " ";
    answer += to_string(max_num);
    
    return answer;
}