#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<char> > board;
int h, w;
int dx[24] = {0,1,1,0,0,-1,-1,0,0,-1,-1,-1,0,1,1,1,0,-1,-1,-1,0,1,1,1};
int dy[24] = {1,0,0,-1,-1,0,0,1,1,1,0,1,1,1,0,1,-1,-1,0,-1,-1,-1,0,-1};

bool rangeCheck(int x, int y){
    if(x >= 0 && x < h && y >= 0 && y < w){
        return true;
    }
    return false;
}

int fillBoard()
{
    int first_x = -1, first_y = -1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j] == '.'){
                first_x = i;
                first_y = j;
                break;
            }
        }
    }
    if(first_x == -1 && first_y == -1) return 1;

    int ret = 0;
    for(int k = 0; k < 24; k+=2){
        int x1, y1, x2, y2;
        x1 = first_x+dx[k];
        y1 = first_y+dy[k];
        x2 = first_x+dx[k+1];
        y2 = first_y+dy[k+1];
        if(rangeCheck(x1, y1) && rangeCheck(x2, y2)){
            if(board[x1][y1] == '.' && board[x2][y2] == '.'){
                board[x1][y1] = '#';
                board[x2][y2] = '#';
                board[first_x][first_y] = '#';
                ret += fillBoard();
                board[x1][y1] = '.';
                board[x2][y2] = '.';
                board[first_x][first_y] = '.';
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> h >> w;
        board.resize(h, vector<char>());
        int white_count = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char input;
                cin >> input;
                board[i].push_back(input);
                if(input == '.') white_count++;
            }
        }
        if(white_count % 3 != 0){
            cout << 0 << '\n';
        }
        else{
            int ans = fillBoard();
            cout << ans << '\n';
        }
        board.clear();
    }

    return 0;
}