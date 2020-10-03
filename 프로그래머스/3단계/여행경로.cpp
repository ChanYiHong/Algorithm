#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> T;

bool DFS(string start, vector<string>& answer, vector<bool>& check, vector<string>& temp, int cnt){
    
    temp.push_back(start);
    
    if(cnt == T.size()){
        answer = temp;
        return true;
    }
    
    for(int i = 0; i < T.size(); i++){
        if(start == T[i][0] && !check[i]){
            check[i] = true;
            bool success = DFS(T[i][1], answer, check, temp, cnt+1);
            
            if(success){
                return true;
            }
            
            check[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    
    T = tickets;
    sort(T.begin(), T.end());
    vector<bool> check(tickets.size(), false);
    DFS("ICN", answer, check, temp, 0);
    
    return answer;
}