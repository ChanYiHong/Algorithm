#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool descending(const pair<int, double>& a, const pair<int, double>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int, double> > m;
    
    vector<bool> check(stages.size(), false);
    
    for(int i = 1; i <= N; i++){
        // 분모
        int down = 0;
        // 분자
        int up = 0;
        for(int j = 0; j < stages.size(); j++){
            if(check[j]) continue;
            if(i == stages[j]) {
                up++;
                check[j] = true;
            }
            down++;
        }
        if(down == 0) m.push_back({i, 0});
        else m.push_back({i, (double)up/down});
    }
    
    sort(m.begin(), m.end(), descending);
    
    
    for(int i = 0; i < m.size(); i++){
        answer.push_back(m[i].first);
    }
    
    return answer;
}