#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//#define INF 987654321

using namespace std;

vector<vector<int> > board;
vector<vector<vector<bool> > > check;
bool isFinish = false;
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//int ans = INF;

// int dfs(int x, int y, bool wall)
// {
//     if(x == N-1 && y == M-1){
//         isFinish = true;
//         return 1;
//     }

//     int ret = INF;

//     for(int i = 0; i < 4; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if(nx>=0 && nx<N && ny>=0 && ny<M){
//             if(!check[nx][ny] && !wall && board[nx][ny] == 1){
//                 check[nx][ny] = true;
//                 int temp = dfs(nx, ny, true);
//                 ret = min(ret, temp);
//                 check[nx][ny] = false;
//             }
//             if(!check[nx][ny] && board[nx][ny] == 0){
//                 check[nx][ny] = true;
//                 int temp = dfs(nx, ny, false);
//                 ret = min(ret, temp);
//                 check[nx][ny] = false;
//             }
//         }
//     }

//     if(ret == INF) return 0;
//     return ret + 1;
// }

// void dfs(int x, int y, bool wall, int cnt){

//     if(x == N-1 && y == M-1){
//         ans = min(ans, cnt);
//         return;
//     }

//     for(int i = 0; i < 4; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if(nx>=0 && nx<N && ny>=0 && ny<M){
//             if(!check[nx][ny] && !wall && board[nx][ny] == 1){
//                 check[nx][ny] = true;
//                 wall = true;
//                 dfs(nx, ny, wall, cnt+1);
//                 check[nx][ny] = false;
//                 wall = false;
//             }
//             if(!check[nx][ny] && board[nx][ny] == 0){
//                 check[nx][ny] = true;
//                 dfs(nx, ny, wall, cnt+1);
//                 check[nx][ny] = false;
//             }
//         }
//     }
// }

void bfs()
{
    queue<vector<int> > q;
    check[0][0][0] = 1;
    // c++ 11 이 아니라 ㅡㅡ;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0); // wall;
    temp.push_back(1); // cnt;
    q.push(temp);

    while(!q.empty()){

        int x = q.front()[0];
        int y = q.front()[1];
        int wall = q.front()[2];
        int cnt = q.front()[3];
        q.pop();

        if(x == N-1 && y == M-1){
            cout << cnt;
            exit(0);
        } 

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];


            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                // 다시 뒤로 안 돌아가게..
                // if(check[nx][ny][0] != 0 || check[nx][ny][1] != 0){
                //     continue;
                // }

                if(wall == 0 && board[nx][ny] == 1){
                    vector<int> temp;
                    temp.push_back(nx);
                    temp.push_back(ny);
                    temp.push_back(wall+1);
                    temp.push_back(cnt+1);
                    check[nx][ny][wall] = true;
                    q.push(temp);
                }
                if(check[nx][ny][wall] == 0 && board[nx][ny] == 0){
                    vector<int> temp;
                    temp.push_back(nx);
                    temp.push_back(ny);
                    temp.push_back(wall);
                    temp.push_back(cnt+1);
                    check[nx][ny][wall] = true;
                    q.push(temp);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    N = n; M = m;

    board.resize(n, vector<int>(m));
    check.resize(n, vector<vector<bool> >(m, vector<bool>(2, 0)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    bfs();

    // check[0][0] = true;
    // // int ret = dfs(0, 0, false);
    // dfs(0, 0, false, 1);
    
    cout << -1;
    // // else cout << ret;

    // if(ans == INF) cout << -1;
    // else cout << ans;

    return 0;
}