#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int arr[100][100];
int check[100][100];
void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = 1;
    //cost[x][y] = 1;
    while(1){
        int t = q.front().first;
        int s = q.front().second;
        q.pop();
        if(t == n - 1 && s == m - 1){
            return;
        }
        for(int i = 0; i < 4; i++){
            int xn = t + dx[i];
            int yn = s + dy[i];
            if(xn >= 0 && xn < n && yn >= 0 && yn < m){
                if(arr[xn][yn] == 1 && !check[xn][yn]){
                    q.push(make_pair(xn,yn));
                    check[xn][yn] = check[t][s]+1;
                    //cost[xn][yn] = cost[t][s] + 1;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    bfs(0, 0);
    
    cout << check[n-1][m-1];

    return 0;
}