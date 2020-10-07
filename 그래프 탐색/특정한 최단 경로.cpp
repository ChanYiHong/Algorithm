#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;
vector<vector<pair<int, int> > > graph;
int N;

int Dijkstra(int start, int target){

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> d(N+1, INF);
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(weight > d[current]) continue;

        for(int i = 0; i < graph[current].size(); i++){
            int next_weight = graph[current][i].second + weight;
            int next = graph[current][i].first;

            if(next_weight < d[next]){
                d[next] = next_weight;
                pq.push(make_pair(next_weight, next));
            }
        }
    }
    return d[target];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    N = n;
    graph.resize(n+1, vector<pair<int, int> >());
    for(int i = 0; i < e; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
        graph[end].push_back(make_pair(start, weight));
    }

    int num1, num2;
    cin >> num1 >> num2;
    bool res = true;

    int ret1 = Dijkstra(1, num1);
    if(ret1 == INF) res = false;
    
    int ret2 = Dijkstra(num1, num2);
    if(ret2 == INF) res = false;

    int ret3 = Dijkstra(num2, n);
    if(ret3 == INF) res = false;


    int answer1;
    if(res){
        answer1 = ret1 + ret2 + ret3;
    } else{
        answer1 = -1;
    }

    res = true;
    int ret4 = Dijkstra(1, num2);
    if(ret4 == INF) res = false;
    
    int ret5 = Dijkstra(num2, num1);
    if(ret5 == INF) res = false;

    int ret6 = Dijkstra(num1, n);
    if(ret6 == INF) res = false;

    int answer2;
    if(res){
        answer2 = ret4 + ret5 + ret6;
    } else{
        answer2 = -1;
    }

    cout << min(answer1, answer2);

    return 0;
}