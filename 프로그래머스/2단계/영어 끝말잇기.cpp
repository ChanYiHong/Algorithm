#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    map<string, int> m;
    
    int index = 1;
    char last = words[0][words[0].length() - 1];
    m[words[0]]++;
    
    for(int i = 1; i < words.size(); i++){
        if(last != words[i][0] || m[words[i]] != 0){
            answer.push_back((index % n) + 1);
            answer.push_back((index / n) + 1);
            return answer;
        }
        index++;
        m[words[i]]++;
        last = words[i][words[i].length() - 1];
    }
    
    answer = vector<int>(2,0);
    
    return answer;
}