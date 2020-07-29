#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    vector<vector<bool>> check(m, vector<bool>(n, false));
    
    int size_of_area = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] == 0) {check[i][j] = true; continue;}
            if(!check[i][j]){
                int current = picture[i][j];
                check[i][j] = true;
                number_of_area++;
                queue<pair<int, int>> q;
                q.push({i, j});
                size_of_area++;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int c = 0; c < 4; c++){
                        int nx = x + dx[c];
                        int ny = y + dy[c];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                            if(!check[nx][ny] && picture[nx][ny] == current){
                                q.push({nx, ny});
                                size_of_area++;
                                check[nx][ny] = true;
                            }
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, size_of_area);
                size_of_area = 0;
            } 
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}




