#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[501][501];
int D[501][501];
int N, M;

int dp(int x, int y, vector<vector<bool> >& m)
{
    if(D[x][y]!= -1) return D[x][y];
    if(x == N-1 && y == M-1) {
        return 1;
    }

    m[x][y] = true;
    D[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx < N && ny>=0 && ny < M){
            if(arr[x][y] > arr[nx][ny] && !m[nx][ny]){
                m[nx][ny] = true;
                D[x][y] += dp(nx, ny, m);
                m[nx][ny] = false;
            }
        }
    }
    return D[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j]; 
        }
    }
    memset(D, -1, sizeof(D));
    vector<vector<bool> > map;
    map.resize(N, vector<bool>(M));
    int res = dp(0, 0, map);
    cout << res;
    return 0;
}