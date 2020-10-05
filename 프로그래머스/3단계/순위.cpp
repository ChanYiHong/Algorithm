#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> victory(n+1, vector<bool>(n+1, false));
    
    // 승 패 결과가 저장될 victory에 값을 채워 넣자
    for(int i = 0; i < results.size(); i++){
        int win = results[i][0];
        int lose = results[i][1];
        
        victory[win][lose] = true;
    }
    
    // 플로이드 와샬 사용해서 모든 노드에서 승패 측정
    
    // 중간 노드
    for(int k = 1; k <= n; k++){
        // 시작
        for(int i = 1; i <= n; i++){
            // 도착
            for(int j = 1; j <= n; j++){
                if(victory[i][k] && victory[k][j]){
                    victory[i][j] = true;
                }
            }
        }
    }
    
    // 결과가 모두 있으면 + 1
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(victory[i][j] || victory[j][i]) cnt++;
        }
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}