#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // pair first : 소요되는 시간, second : queue에 들어간 시간 (요청에서 종료까지 측정 가능)  
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int index = 0;
    int time = 0;
    
    while(!pq.empty() || index < jobs.size()){
        
        // 현재 시간 보다 안쪽이면 일단 다 넣음
        if(index < jobs.size() && jobs[index][0] <= time){
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
            continue;
        }
        
        if(!pq.empty()){
            answer += (time - pq.top().second) + pq.top().first;
            time += pq.top().first;
            pq.pop();
        }
        else{
            time = jobs[index][0];
        }
        
    }
    
    answer /= jobs.size();
    
    return answer;
}