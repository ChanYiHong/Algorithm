#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> v(n);
    int index = 1;
    for(int i = 0; i < n; i++){
        v[i].resize(index);
        index++;
    }
    
    // 저장되는 숫자. 1부터 2,3,4 .. 로 증가
    int cnt = 1;
    // 왼쪽부터 시작 5개, 오른쪽 4개, 대각선왼쪽 3개, 왼쪽 2개...이런식
    int line = n;
    
    // 방향. 3 나머지 연산
    int direction = 0;
    
    // 시작좌표들
    int cur_x = 0;
    int cur_y = 0;
    
    while(line > 0){
        
        int num = line;
        
        // 왼쪽 수직 하강
        if(direction % 3 == 0){
            while(num > 0){
                v[cur_x][cur_y] = cnt;
                cnt++;
                num--;
                cur_x++;
            }
            // 미리 오른쪽으로 한칸 이동해둠
            cur_x--;
            cur_y++;
        }
        
        // 오른쪽 화살표
        if(direction % 3 == 1){
            while(num > 0){
                v[cur_x][cur_y] = cnt;
                cnt++;
                num--;
                cur_y++;
            }
            //미리 위로 한칸 이동
            cur_y = cur_y - 2;
            cur_x--;
        }
        
        if(direction % 3 == 2){
            while(num > 0){
                v[cur_x][cur_y] = cnt;
                cnt++;
                num--;
                cur_x--;
                cur_y--;
            }
            // 미리 다시 안쪽 삼각형 시작점으로
            cur_x = cur_x + 2;
            cur_y++;
        }
        
        line--;
        direction++;
    }
    
    for(int i =0; i < v.size();i++){
        for(int j = 0; j < v[i].size(); j++){
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}

