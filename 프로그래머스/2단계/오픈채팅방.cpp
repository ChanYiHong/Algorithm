#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> m;

string str[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> result;
    
    for(string s : record){
        int split = 0;
        vector<string> temp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                temp.push_back(s.substr(split, i - split));
                split = i + 1;
            }
            if(i == s.length() - 1){
                temp.push_back(s.substr(split, i - split + 1));
            }
        }
        
        if(temp[0].compare("Enter") == 0){
            // uid1234   Muzi
            m[temp[1]] = temp[2];
            // Muzi  님이 들어왔습니다.
            result.push_back({temp[1], str[0]});
        }
        if(temp[0].compare("Change") == 0){
            m[temp[1]] = temp[2];
        }
        if(temp[0].compare("Leave") == 0){
            // Muzi  님이 나갔습니다.
            result.push_back({temp[1], str[1]});
        }
    }
    
    for(int i = 0; i < result.size(); i++){
        answer.push_back(m[result[i].first] + result[i].second);
    }
    
    return answer;
}