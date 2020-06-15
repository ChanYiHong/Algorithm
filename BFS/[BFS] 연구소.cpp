#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, m;
int board[9][9];
int copyBoard[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maximum = 0;

// 재귀적으로 벽을 세움.. 3개 되면 BFS돌림.

void wall(int num)
{
    if(num == 3){
        int fBoard[9][9];
        for(int t = 0; t < n; t++){
            for(int s = 0; s < m; s++){
                fBoard[t][s] = copyBoard[t][s];
            }
        }
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(fBoard[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            int t = q.front().first;
            int s = q.front().second;
            q.pop();
            for(int c = 0; c < 4; c++){
                int nx = t + dx[c];
                int ny = s + dy[c];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(fBoard[nx][ny] == 0){
                        fBoard[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        int num = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(fBoard[i][j] == 0) num++;
            }
        }
        maximum = max(maximum, num);
        return;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(copyBoard[i][j] == 0){
                copyBoard[i][j] = 1;
                wall(num + 1);
                copyBoard[i][j] = 0;
            }   
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    // 벽 세우기..?
    // vector 복사해서 맵을 하나 더 만듬
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                for(int t = 0; t < n; t++){
                    for(int s = 0; s < m; s++){
                        copyBoard[t][s] = board[t][s];
                    }
                }
                copyBoard[i][j] = 1;
                wall(1);
                copyBoard[i][j] = 0;
            }   
        }
    }

    cout << maximum;
    return 0;
}
