#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<char> > board;
map<char, int> m;
vector<vector<bool> > check;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C;

int dfs(char alpha, int x, int y){

    cout << alpha << " " << x << " " << y << '\n';

    m[alpha]++;

    cout << m[alpha] << '\n';

    int ret = 1;
    int maximum = 0;

    for(int c = 0; c < 4; c++){
        cout << "포문시작이요" << '\n';
        int nx = x + dx[c];
        int ny = y + dy[c];
        char k = board[nx][ny];
        cout << k << '\n';
        cout << m[k] << '\n';

        if(nx >= 0 && nx < R && ny >= 0 && ny < C){
            
            if(m[k] == 0 && !check[nx][ny]){
                check[nx][ny] = true;
                maximum = max(maximum, dfs(k, nx, ny));
                check[nx][ny] = false;
            }
        }
    }
    ret += maximum;

    cout << ret << '\n';

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    R = r; C = c;

    board.resize(R, vector<char>(C));
    check.resize(R, vector<bool>(C));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    check[0][0] = true;
    int ret = dfs(board[0][0], 0, 0);

    cout << ret;

    return 0;
}