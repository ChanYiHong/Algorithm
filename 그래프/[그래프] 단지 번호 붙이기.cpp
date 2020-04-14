#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n;
int arr[26][26];
int check[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(int x, int y, int cnt)
{
    int num = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = cnt;
    while(!q.empty()){
        int t = q.front().first;
        int s = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = t + dx[i];
            int ny = s + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
                if(arr[nx][ny] == 1 && check[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = cnt;
                    num++;
                }
            }
        }
    }
    return num;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    vector<int> each;
    int answer = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                int number = bfs(i, j, ++cnt);
                each.push_back(number);
                answer++;
            }
        }
    }

    cout << answer << '\n';
    for(int i = 0; i < each.size(); i++){
        cout << each[i] << '\n';
    }

    return 0;
}