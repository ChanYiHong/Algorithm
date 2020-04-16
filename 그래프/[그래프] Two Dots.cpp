#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
char arr[50][50];
bool check[50][50];
int dis[50][50];
int n, m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool dfs(int x, int y, int cnt, char color)
{
    if(check[x][y]) return cnt - dis[x][y] >= 4;
    check[x][y] = true;
    dis[x][y] = cnt;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(arr[nx][ny] == color){
                if(dfs(nx, ny, cnt+1, color)) return true;
            }
        }
    }
    return false;
}

void answer()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!check[i][j]){
                if(dfs(i, j, 0, arr[i][j])){
                    cout << "Yes";
                    return;
                }
            }
            //memset(check, false, sizeof(check));
            //memset(dis, 0, sizeof(dis));
        }
    }
    cout << "No";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    answer();
    return 0;
}