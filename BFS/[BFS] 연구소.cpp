#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int n, m;
int board[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int calculateSum(vector<vector<int> >& check)
{
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == 0) num++;
        }
    }
    return num;
}

int BFS(int x, int y, vector<vector<int> >& check)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int t = q.front().first;
        int s = q.front().second;
        q.pop();
        for(int c = 0; c < 4; c++){
            int nx = t + dx[c];
            int ny = t + dy[c];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                if(check[nx][ny] == 0){
                    check[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return calculateSum(check);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;

    vector<vector<int> > check;
    check.resize(n, vector<int>(m));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            check[i][j] = board[i][j];
        }
    }

    // 벽 세우기..?
    for(int )

    return 0;
}
