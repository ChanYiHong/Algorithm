#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int> > > board;
    vector<vector<vector<int> > > check;
    

    board.resize(N, vector<vector<int> >(M, vector<int>(H)));
    check.resize(N, vector<vector<int> >(M, vector<int>(H, 0)));

    bool isAllOne = true;

    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> board[i][j][k];
                if(isAllOne && board[i][j][k] == 0){
                    isAllOne = false;
                }
                if(board[i][j][k] == -1){
                    check[i][j][k] = -1;
                }
            }
        }
    }
    int cnt = 1;
    queue<vector<int> > q;

    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j< M; j++){
                if(board[i][j][k] == 1 && check[i][j][k] == 0){
                    check[i][j][k] = cnt;
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);

                    q.push(temp);
                }
            }
        }
    }

    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int z = q.front()[2];

        q.pop();

        for(int i = 0; i < 6; i++){
            int nx = x;
            int ny = y;
            int nz = z;
            if(i < 4){
                nx += dx[i];
                ny += dy[i];
            }
            if(i == 4){
                nz++;
            }
            if(i == 5){
                nz--;
            }
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H){
                
                if(check[nx][ny][nz] == 0){
                    check[nx][ny][nz] = check[x][y][z] + 1;
                    vector<int> temp;
                    temp.push_back(nx);
                    temp.push_back(ny);
                    temp.push_back(nz);
                    
                    q.push(temp);
                }
            }
        }
    }
    int ans = 0;
    bool isThereZero = false;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(check[i][j][k] == 0){
                    ans = -1;
                    isThereZero = true;
                    break;
                }
                ans = max(ans, check[i][j][k]);
            }
            if(isThereZero) break;
        }
        if(isThereZero) break;
    }

    if(isAllOne) cout << 0;
    else if(ans == -1) cout << ans;
    else cout << ans - 1;

    return 0;
}