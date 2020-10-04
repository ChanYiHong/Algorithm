#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visit;

void BFS(int start){
    
    queue<int> q;
    q.push(start);
    visit[start] = 0;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i];
            
            if(visit[nx] == -1){
                visit[nx] = visit[x] + 1;
                q.push(nx);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.resize(n+1, vector<int>());
    visit.resize(n+1, -1);
    
    for(int i = 0; i < edge.size(); i++){
        int x1 = edge[i][0];
        int x2 = edge[i][1];
        
        graph[x1].push_back(x2);
        graph[x2].push_back(x1);
    }
    
    BFS(1);
    
    int max_value = *max_element(visit.begin(), visit.end());
    
    vector<int>::iterator iter;
    
    for(iter = visit.begin(); iter != visit.end(); iter++){
        if(*iter == max_value){
            answer++;
        }
    }
    
    return answer;
}