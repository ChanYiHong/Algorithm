#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n, m, k;
        cin >> n >> m >> k;
        int arr[51][51];
        memset(arr, 0, sizeof(arr));
        for(int s = 0; s < k; s++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        bool check[51][51];
        int answer = 0;
        memset(check, false, sizeof(check));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1 && !check[i][j]){
                    queue<pair<int, int> > q;
                    q.push(make_pair(i,j));
                    check[i][j] = true;
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for(int z = 0; z < 4; z++){
                            int nx = a + dx[z];
                            int ny = b + dy[z];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                                if(arr[i][j] == 1 && !check[nx][ny]){
                                    check[nx][ny] = true;
                                    q.push(make_pair(nx,ny));
                                }
                            }
                        }
                    }
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}