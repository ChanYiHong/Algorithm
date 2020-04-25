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
    int arr[n][m];
    for(int i = 0; i < k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = x1 ; j < x2; j++){
            for(int l = y1; l < y2; l++){
                arr[j][l] = 1;
            }
        }

        bool check[n][m];
        int ter = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 0 && !check[i][j]){
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
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                                
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}