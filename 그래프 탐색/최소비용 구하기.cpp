#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > v(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> d(n+1, INF);

    for(int i = 0; i < m; i++){
        int start, end, weight;
        cin >> start >> end >> weight;

        v[start].push_back(make_pair(end, weight));
    }

    int start, end;
    cin >> start >> end;
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        int current = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if(d[current] < weight) continue;

        for(int i = 0; i < v[current].size(); i++){
            int dis = v[current][i].first;
            int dis_weight = v[current][i].second + weight;

            if(dis_weight < d[dis]){
                d[dis] = dis_weight;
                pq.push(make_pair(dis, dis_weight));
            }
        }
    }

    cout << d[end];    

    return 0;
}