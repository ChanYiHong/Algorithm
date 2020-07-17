#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int length = commands.size();
    int index = 0;
    
    while(length--){
        vector<int> sub;
        int start = commands[index][0];
        int end = commands[index][1];
        
        for(int j = start; j <= end; j++){
            sub.push_back(array[j-1]);
        }
        sort(sub.begin(), sub.end());
        
        int location = commands[index][2];
        answer.push_back(sub[location - 1]);
        index++;
    }
    return answer;
}