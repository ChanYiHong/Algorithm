#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool descending(int a, int b){
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // priorities 를 따로 저장 후 내림차순으로 정렬 (desSorted)
    vector<int> desSorted = priorities;
    sort(desSorted.begin(), desSorted.end(), descending);
    
    // 정답이 될 순서
    int order = 1;
    
    int index = 0;
    queue<pair<int, int>> q;
    
    // queue에 priorities값과 최초 위치 값을 pair로 저장
    for(auto p : priorities){
        q.push({p, index});
        index++;
    }
    
    // desSorted의 index
    int dsIndex = 0;
    
    while(!q.empty()){
        // 만약 우선순위가 젤 높다면 (desSorted가 내림차순으로 정렬되어있어서 같다면 젤 높은 것)
        if(q.front().first == desSorted[dsIndex]){
            // 그와중에 우리가 찾는 최초 위치라면 정답
            if(q.front().second == location){
                answer = order;
                break;
            }
            // 아니면 그냥 queue에서는 pop, order와 desSorted다음인자로
            else{
                q.pop();
                order++;
                dsIndex++;
            }
        }
        // 우선순위가 젤 높지 않으면 pop시켜서 젤 뒤로
        else{
            pair<int, int> temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    return answer;
}