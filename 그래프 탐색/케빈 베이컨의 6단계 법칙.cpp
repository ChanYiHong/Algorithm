#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

vector<vector<int> > v;
vector<int> check;
int N;
queue<int> q;

void bfs(int start)
{
    q.push(start);
    check[start] = 0; 

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i];
            if(check[nx] == -1){
                check[nx] = check[x] + 1;
                q.push(nx);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    N = n;

    v = vector<vector<int> >(n+1);

    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;

        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    int index;
    int minimum = INF;
    for(int i = 1; i <= n; i++){
        
        check.resize(n+1, -1);
        bfs(i);

        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            sum += check[j];
        }
        if(minimum > sum){
            minimum = sum;
            index = i;
        }
        check.clear();
    }

    cout << index;

    return 0;
}