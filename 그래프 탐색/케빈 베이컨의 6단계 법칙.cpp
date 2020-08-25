#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<int> > v;
vector<bool> check;
int N;
int minimum = INF;

void dfs(int x, int dst, int cnt){

    if(x == dst){
        minimum = min(minimum, cnt);
        return;
    }

    for(int i = 0; i < v[x].size(); i++){
        int next = v[x][i];

        if(!check[next]){
            check[next] = true;
            dfs(next, dst, cnt+1);
            check[next] = false;
        }
    }
}

int kevin(int x)
{
    int ret = 0;

    for(int i = 1; i <= N; i++){
        if(i == x) continue;
        check.resize(N+1, false);
        dfs(x, i, 0);
        ret += minimum;
        minimum = INF;
        check.clear();
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    N = n;

    v.resize(n+1, vector<int>());

    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;

        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    int index;
    int cnt = INF;
    for(int i = 1; i <= m; i++){
        int ret = kevin(i);
        if(cnt > ret){
            index = i;
            cnt = ret;
        }
    }

    cout << index;

    return 0;
}