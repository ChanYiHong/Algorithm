#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool check1[1001];
bool check2[1001];
vector<vector<int> > l;
queue<int> q;

void dfs(int x)
{
    check1[x] = true;
    cout << x << ' ';
    for(int i = 0; i < l[x].size(); i++){
        int v = l[x][i];
        if(!check1[v]){
            dfs(v);
        }
    }
}

void bfs(int x)
{
    q.push(x);
    check2[x] = true;
    while(!q.empty()){
        cout << q.front() << ' ';
        int k = q.front();
        q.pop();
        for(int i = 0; i < l[k].size(); i++){
            int v = l[k][i];
            if(!check2[v]){
                check2[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, first;
    cin >> n >> m >> first;
    l.resize(n+1,vector<int>());
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        l[start].push_back(end);
        l[end].push_back(start);
    }
    for(int i = 1; i <= n; i++){
        sort(l[i].begin(), l[i].end());
    }
    dfs(first);
    cout << '\n';
    bfs(first);

    return 0;
}
