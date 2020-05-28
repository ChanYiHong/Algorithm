#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[501][501];
int D[501][501];
int n, m;

int dfs(int row, int col){
    if(D[row][col] != -1) return D[row][col];
    if(row < 0 && row >= n && col < 0 && col >= m) return 0;
    if(row == 0 && col == 0) return 1;
    D[row][col] = 0;
    for(int k = 0; k < 4; k++){
        int x = row + dx[k];
        int y = col + dy[k];
        
        if(arr[x][y] > arr[row][col]){
            D[row][col] += dfs(x, y);
        }
    }
    return D[row][col];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j]; 
        }
    }
    memset(D, -1, sizeof(D));
    cout << dfs(n-1, m-1);
    
    return 0;
}