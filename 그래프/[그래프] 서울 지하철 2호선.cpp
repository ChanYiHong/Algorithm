#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n;
vector<vector<int> > v;
int check[3001];
int dist[3001];
int dfs_circle(int x, int p)
{
    if(check[x] == 1) return x;
    check[x] = 1;
    for(int i = 0; i < v[x].size(); i++){
        int temp = v[x][i];
        if(temp == p) continue;
        int res = dfs_circle(temp, x);
        if(res == -2) return -2;
        if(res >= 0){
            check[x] = 2;
            if(x == res) return -2;
            else return res;
        }             
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    v.resize(n+1, vector<int>());
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    // 순환선인지 아닌지 파악하기
    dfs_circle(1,-1);
    // 순환점과의 거리 출력
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(check[i] == 2){
            dist[i] = 0;
            q.push(i);
        }
        else{
            dist[i] = -1;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(dist[y] == -1){
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }

    for(int i = 1; i <=n; i++){
        cout << dist[i] << ' ';
    }

    return 0;
}