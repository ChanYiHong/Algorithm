#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {    
    int answer = 0;
    queue<pair<int, int>> q;
    int currentWeight = 0;
    int time = 1;
    int index = 1;
    
    q.push({truck_weights[0], time});
    currentWeight += q.front().first;
    
    while(!q.empty()){
        
        time++;
        
        if(time - q.front().second == bridge_length){
            currentWeight -= q.front().first;
            q.pop();
        }
        
        if(index == truck_weights.size()) break;
        
        if(currentWeight + truck_weights[index] < weight){
            q.push({truck_weights[index], time});
            currentWeight += q.front().first;
            index++;
        }
        
    }
    
    answer = time;
    return answer;
}