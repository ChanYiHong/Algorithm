#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > board;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;

vector<vector<int> > make_one_and_zero(int n){
    
    vector<vector<int> > ret = board;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(ret[i][j] <= n){
                ret[i][j] = 0;
            } else{
                ret[i][j] = 1;
            }
        }
    }

    return ret;
}

void dfs(vector<vector<int> >& rain, int x, int y){

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
            if(rain[nx][ny] == 1){
                rain[nx][ny] = 0;
                dfs(rain, nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m = 0;

    int n;
    cin >> n;
    N = n;
    // 메인 판
    board.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(m < board[i][j]) m = board[i][j];
        }
    }

    int answer = 0;
    // 비 수위를 1부터 max까지 돌면서 확인
    for(int i = 1; i <= m; i++){
        // 메인 판을 각 수위와 비교하여 0, 1로 표현
        vector<vector<int> > ret = make_one_and_zero(i);

        int sum = 0;
        for(int t = 0; t < n; t++){
            for(int s = 0; s < n; s++){
                if(ret[t][s] == 1){
                    ret[t][s] = 0;
                    dfs(ret, t, s);
                    sum++;
                }
            }
        }
        answer = max(answer, sum);

        ret.clear();
    }

    cout << answer;

    return 0;
}