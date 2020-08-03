#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int phone[4][3] = {
    {1,2,3}, 
    {4,5,6}, 
    {7,8,9}, 
    {-1,0,-2}
};

pair<int, int> findPosition(int current){
    int x,y;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(current == phone[i][j]){
                x = i;
                y = j;
            }
        }
    }
    return {x,y};
}

int dfs(int x, int y, int num, int depth, vector<vector<bool>>& check){
    
    if(phone[x][y] == num) return depth;
    
    int ret = 100;
    check[x][y] = true;
    for(int c = 0; c < 4; c++){
        int nx = x + dx[c];
        int ny = y + dy[c];
        if(nx >= 0 && nx < 4 && ny >= 0 && ny < 3){
            if(!check[nx][ny]){
                check[nx][ny] = true;
                ret = min(ret, dfs(nx, ny, num, depth+1, check));
                check[nx][ny] = false;
            }
        }
    }
    return ret;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_current = -1;
    int right_current = -1;
    
    for(int num : numbers){
        if(num % 3 == 1){
            answer+="L";
            left_current = num;
        }
        else if(num % 3 == 0 && num != 0){
            answer+="R";
            right_current = num;
        }
        else if(num % 3 == 2 || num == 0){
            
            vector<vector<bool>> check(4, vector<bool>(3));
            pair<int, int> left = findPosition(left_current);
            int left_moving = dfs(left.first, left.second, num, 0, check);
            
            vector<vector<bool>> check2(4, vector<bool>(3));
            pair<int, int> right = findPosition(right_current);
            int right_moving = dfs(right.first, right.second, num, 0,check2);
            
            if(left_moving > right_moving){
                answer+="R";
                right_current = num;
            }
            else if(left_moving < right_moving){
                answer+="L";
                left_current = num;
            }
            else{
                if(hand.compare("left") == 0){
                    answer+="L";
                    left_current = num;
                }
                else{
                    answer+="R";
                    right_current = num;
                }
            }
        }
    }
    
    return answer;
}