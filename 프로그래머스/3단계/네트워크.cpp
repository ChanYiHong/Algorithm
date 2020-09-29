#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> check;

void BFS(int index){
    
    check[index] = true;
    queue<int> q;
    q.push(index);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i];
            
            if(!check[nx]){
                check[nx] = true;
                q.push(nx);
            }
        }
    } 
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    graph.resize(n, vector<int>());
    check.resize(n, false);
    
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j || computers[i][j] == 0) continue;  
            graph[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!check[i]){
            answer++;
            BFS(i);
        }
    }
    
    return answer;
}