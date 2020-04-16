#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, m;
int arr[1001][1001];
int check[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer(int x)
{
    if(x == 1){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == -1) continue;
                if(arr[i][j] == 0) return 1;
            }
        }
        return 0;
    }
    else{
        int max = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j] == -1) continue;
                if(max < check[i][j]) max = check[i][j];
                if(check[i][j] == 0) return -1;
            }
        }
        return max-1;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // 입력 
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1) check[i][j] = -1;
        }
    }
    
    queue<pair<int, int> > q;

    // 전체를 동시에 변화시키기 위해서 queue에 1인 곳을 다 넣음.
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                q.push(make_pair(i, j));
                check[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int t = q.front().first;
        int s = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = t + dx[i];
            int ny = s + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(arr[nx][ny] == 0 && !check[nx][ny]){
                    check[nx][ny] = check[t][s] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }


    if(answer(1) == 0) cout << 0;
    else cout << answer(2);

    return 0;
}