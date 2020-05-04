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
    int m, n, k;
    cin >> m >> n >> k;
    int arr[101][101];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;


        for(int j = y1 ; j < y2; j++){
            for(int l = x1; l < x2; l++){
                arr[j][l] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    vector<int> v;
    bool check[101][101];
    int ter = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0 && !check[i][j]){
                int cnt = 1;
                queue<pair<int, int> > q;
                q.push(make_pair(i,j));
                check[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int c = 0; c < 4; c++){
                        int nx = x + dx[c];
                        int ny = y + dy[c];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                            if(arr[nx][ny] == 0 && !check[nx][ny]){
                                q.push(make_pair(nx,ny));
                                check[nx][ny] = true;
                                cnt++;
                            }
                        }
                    }
                }
                v.push_back(cnt);
                ter++;    
            }
        }
    }

    cout << ter << '\n';
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }

    return 0;
}