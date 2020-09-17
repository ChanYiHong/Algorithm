#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int v, e, k;
    cin >> v >> e >> k;

    vector<vector<pair<int, int> > > vec;
    vec.resize(v+1, vector<pair<int, int> >());

    for(int i = 0; i < e; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        vec[start].push_back(make_pair(end, weight));
        //vec[end].push_back(make_pair(start, weight));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    vector<int> dist(v+1, INF);

    dist[k] = 0;

    pq.push(make_pair(0, k));

    while(!pq.empty()){
        int cost = pq.top().first;
        int here = pq.top().second;

        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < vec[here].size(); i++){
            int there = vec[here][i].first;
            int nextDist = cost + vec[here][i].second;

            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }

    for(int i = 0; i < dist.size(); i++){
        if(dist[i] == INF){
            cout << "INF" << '\n';
        }
        else{
            cout << dist[i] << '\n';
        }
    }

    // for(int i = 1; i <= v; i++){
        
        // if(i == k) {
        //     cout << 0 << '\n'; 
        //     continue;
        // }

        // int goal = i;

        // queue<int> q;
        // vector<int> check(v+1, -1);
        // q.push(k);
        // check[k] = 0;

        // //bool escape = false;
        // while(!q.empty()){
        //     int start = q.front();
        //     q.pop();
        //     for(int c = 0; c < vec[start].size(); c++){
        //         int next = vec[start][c].first;
        //         int weight = vec[start][c].second;

        //         if(check[next] == -1){
        //             check[next] = check[start] + weight;
        //             // if(next == goal) {
        //             //     escape = true;
        //             //     break;
        //             // }
        //             q.push(next);
        //             continue;
        //         }
        //         if(check[next] > check[start] + weight){
        //             check[next] = check[start] + weight;
        //             //q.push(next);
        //             continue;
        //         }
        //     }
        //     // if(escape) break;
        // }

        // for(int i = 1; i <= v; i++){
        //     if(check[i] == -1) {
        //         cout << "INF" << '\n';
        //         continue;
        //     }
        //     cout << check[i] << '\n';
        // }

        // if(check[goal] == -1){
        //     cout << "INF" << '\n';
        // }
        // else{
        //     cout << check[goal] << '\n';
        // }
    // }

    return 0;
}