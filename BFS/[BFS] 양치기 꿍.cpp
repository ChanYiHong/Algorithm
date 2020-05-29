#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m;
char arr[251][251];
bool check[251][251];
int sheep = 0;
int wolf = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, char c)
{
    int s = 0, w = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    if(c == 'v') w++;
    if(c == 'k') s++;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!check[nx][ny]){
                    if(arr[nx][ny] == '.' || arr[nx][ny] == 'v' || arr[nx][ny] == 'k'){
                        check[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                        if(arr[nx][ny] == 'v'){
                            w++;
                        }
                        if(arr[nx][ny] == 'k'){
                            s++;
                        }
                    }
                }
            }
        }
    }
    if(s > w) sheep += s;
    else wolf += w; 
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
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.' || arr[i][j] == 'v' || arr[i][j] == 'k'){
                if(!check[i][j]){
                    bfs(i, j, arr[i][j]);
                }                
            }
        }
    }

    cout << sheep << ' ' << wolf;

    return 0;
}