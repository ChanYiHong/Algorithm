#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > l;
bool check[1001];
void dfs(int x)
{
    check[x] = true;
    for(int i = 0; i < l[x].size(); i++){
        int v = l[x][i];
        if(!check[v]){
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    l.resize(n+1);
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        l[start].push_back(end);
        l[end].push_back(start);
    }
    for(int i = 1; i <= n; i++){
        sort(l[i].begin(), l[i].end());
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(!check[i]){
            dfs(i);
            answer++;
        }
    }
    cout << answer;
    return 0;
}