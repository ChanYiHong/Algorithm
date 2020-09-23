#include <string>
#include <vector>
#include <queue>
#define HORIZONTAL 0
#define VERTICAL 1

using namespace std;

vector<vector<int>> B;
bool check[2][101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int turnX[2][4] = {{0, 0, -1, -1}, {1, 1, 0, 0}};
int turnY[2][4] = {{0, 1, 0, 1}, {0, -1, 0, -1}};

int N;

typedef struct Robot{
    int row;
    int col;
    int dir;
    int time;
    Robot(int a, int b, int d, int t){
        row = a; col = b; dir = d; time = t;
    }
}Robot;

bool isInRange(int a, int b, int dir){
    if(a < 0 || a >= N || b < 0 || b >= N){
        return false;
    }
    
    if(B[a][b] == 1) return false;
    
    if(dir == HORIZONTAL){
        if(b + 1 >= N || B[a][b+1] == 1){
            return false;
        }
    }
    if(dir == VERTICAL){
        if(a + 1 >= N || B[a+1][b] == 1){
            return false;
        }
    }
    return true;
}

bool isTurnAroundAvailable(Robot cur, int next_row, int next_col){

    if(cur.dir == HORIZONTAL){
        if(cur.row == next_row){
            if(cur.row + 1 >= N){
                return false;
            }
            if(B[cur.row+1][cur.col] == 1 || B[cur.row+1][cur.col+1] == 1){
                return false;
            }
        }
        else{
            if(cur.row - 1 < 0){
                return false;
            }
            if(B[cur.row-1][cur.col] == 1 || B[cur.row-1][cur.col+1] == 1){
                return false;
            } 
        }
    }
    else{
        if(cur.col == next_col){
            if(cur.col + 1 >= N){
                return false;
            }
            if(B[cur.row][cur.col+1] == 1 || B[cur.row+1][cur.col+1] == 1){
                return false;
            }
        }
        else{
            if(cur.col < 0){
                return false;
            }
            if(B[cur.row][cur.col-1] == 1 || B[cur.row+1][cur.col-1] == 1){
                return false;
            }
        }
    }
    return true;
}

int bfs(){
    
    queue<Robot> q;
    q.push(Robot(0,0,HORIZONTAL,0));
    check[HORIZONTAL][0][0] = true;
    
    while(!q.empty()){
        Robot cur = q.front();
        q.pop();
        
        // 탈출 조건. 끝이면 time(정답) return
        if(cur.dir == HORIZONTAL){
            if(cur.row == N-1 && cur.col + 1 == N-1){
                return cur.time;
            }
        }
        if(cur.dir == VERTICAL){
            if(cur.row + 1 == N-1 && cur.col == N-1){
                return cur.time;
            }
        }
        
        // x, y 축 그냥 이동
        for(int i = 0; i < 4; i++){
            int nx = cur.row + dx[i];
            int ny = cur.col + dy[i];
            int d = cur.dir;
            int t = cur.time;
            
            if(isInRange(nx, ny, d)){
                if(!check[d][nx][ny]){
                    check[d][nx][ny] = true;
                    q.push(Robot(nx, ny, d, t+1));
                }
            }
        }
        
        // 회전..
        for(int i = 0; i < 4; i++){
            int d = cur.dir;
            int next_d = cur.dir^1;
            int nx = cur.row + turnX[d][i];
            int ny = cur.col + turnY[d][i];
            int t = cur.time;
            
            if(isTurnAroundAvailable(cur, nx, ny)){
                if(!check[next_d][nx][ny]){
                    check[next_d][nx][ny] = true;
                    q.push(Robot(nx, ny, next_d, t + 1));
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    B = board;
    N = board.size();
    
    answer = bfs();
    
    return answer;
}