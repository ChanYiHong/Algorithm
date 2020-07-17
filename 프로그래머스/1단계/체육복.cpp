#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int count_cloth(vector<int>& cloth){
    int cnt = 0;
    for(int i = 0; i < cloth.size(); i++){
        if(cloth[i] == 1) cnt++;
    }
    return cnt;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 최종 결과 상태. 최초에 1로 초기화
    vector<int> result(n, 1);
    
    // 도난당하면 0
    for(int i = 0; i < lost.size(); i++){
        int location = lost[i]-1;
        result[location] = 0;
    }
    
    // 여분 있는 애들 위치 저장하려고
    vector<int> cloth(n, 0);
    
    // 여분 있으면 1로
    for(int i = 0; i < reserve.size(); i++){
        int location = reserve[i]-1;
        //여분이 있지만 도난 당했으면 여분이 없는 것. 자기 자신은 다시 1로
        if(result[location] == 0){
            result[location] = 1;
            continue;
        }
        cloth[location] = 1;
    }
    
    // lost에서 젤 낮은 애 기준으로
    sort(lost.begin(), lost.end());
    
    for(int i = 0; i < lost.size(); i++){
        int lost_location = lost[i]-1;
        
        // 무조건 먼저 왼쪽 애가 여분 있으면 여분 받아오고
        if(lost_location - 1 >= 0){
            if(cloth[lost_location - 1] == 1){
                cloth[lost_location - 1] = 0;
                result[lost_location] = 1;
                // 받았으면 오른쪽 확인 x
                 continue;
            }
        }
        // 왼쪽에가 없으면 오른쪽 애
        if(lost_location + 1 < n){
            if(cloth[lost_location + 1] == 1){
                cloth[lost_location + 1] = 0;
                result[lost_location] = 1;
            }
        }
    }
    answer = count_cloth(result);
        
    return answer;
}