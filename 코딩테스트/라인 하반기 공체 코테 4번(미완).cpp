#include <string>
#include <vector>

using namespace std;

vector<vector<int>> M;
int cnt = 0;

bool checkIfOutOfRange(int x, int y){
    return x >= 0 && x < M.size() && y >= 0 && y < M.size();
}

void dfs(int x, int y){
    
    if(x == M.size()-1 && y == M.size()-1){
        return;
    }
    
    // Right Side (오른쪽 벽 확인)
    if(checkIfOutOfRange(x, y+1)){
        // 벽 있으면 밑으로
        if(M[x][y+1] == 1){
            // 밑에가 안막혀있으면 밑
            if(checkIfOutOfRange(x+1, y)){
                if(M[x+1][y] == 0){
                    cnt++;
                    dfs(x+1, y);
                    return;
                }
            }
            // 밑에도 막혀있으면 위로
            else{
                cnt++;
                dfs(x-1, y);
            }
        }
        // 아니면 오른쪽으로
        else{
            cnt++;
            dfs(x, y+1);
            return;
        }
    }
    
    // 오른쪽이 막힘 (영역 밖)
    if(!checkIfOutOfRange(x, y+1)){
        // 왼손이니 위부터 확인
        if(checkIfOutOfRange(x-1, y)){
            if(M[x-1][y] == 0){
                cnt++;
                dfs(x-1, y);
            }
        }
        // 밑에 확인
        if(checkIfOutOfRange(x+1, y)){
            // 막혔으면 왼쪽
            if(M[x+1][y] == 1){
                cnt++;
                dfs(x, y-1);
                return;
            }
            // 안 막혔으면 밑으로
            else{
                cnt++;
                dfs(x+1, y);
            }
        }
    }

}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    M = maze;
    dfs(0, 0);
    
    answer = cnt;
    
    return answer;
}
