#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>


using namespace std;

vector<vector<char> > board;
vector<vector<int> > check;
map<char, int> m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C;

int dfs(int x, int y){

    int ret = 1;
    int maximum = 0;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C){
            char k = board[nx][ny];
            
            if(m[k] == 0 && !check[nx][ny]){
                m[k]++;
                check[nx][ny] = true;
                int t = dfs(nx, ny);
                maximum = max(maximum, t);
                check[nx][ny] = false;
                m[k]--;
            }
        }
    }
    ret += maximum;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    R = r; C = c;

    board.resize(R, vector<char>(C));
    check.resize(R, vector<int>(C, 0));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    
    m[board[0][0]]++;
    check[0][0] = true;
    int ret = dfs(0, 0);

    cout << ret;

    return 0;
}