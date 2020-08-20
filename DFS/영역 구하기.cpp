#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > board;
vector<vector<bool> > check;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int xm;
int ym;

int dfs(int x, int y){
    
    int ret = 1;

    for(int c = 0; c < 4; c++){
        int nx = x + dx[c];
        int ny = y + dy[c];

        if(nx >= 0 && nx < xm && ny >= 0 && ny < ym){
            if(!check[nx][ny] && board[nx][ny] == 0){
                check[nx][ny] = true;
                ret += dfs(nx, ny);
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int M, N, K;
    cin >> M >> N >> K;
    xm = M;
    ym = N;

    board.resize(M + 1, vector<int>(N + 1, 0));
    check.resize(M + 1, vector<bool>(N + 1, false));

    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;


        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                board[j][k] = 1;
            }
        }
    }

    vector<int> region;
    int num = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!check[i][j] && board[i][j] == 0){
                check[i][j] = true;
                int ret = dfs(i, j);
                region.push_back(ret);
                num++;
            }
        }
    }

    sort(region.begin(), region.end());

    cout << num << '\n';
    for(int n = 0; n < region.size(); n++){
        cout << region[n] << " ";
    }

    return 0;
}