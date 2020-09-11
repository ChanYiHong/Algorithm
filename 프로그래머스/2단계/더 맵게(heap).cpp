#include <string>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // Min Heap 생성
    make_heap(scoville.begin(), scoville.end(), greater<int>());
    
    while(scoville[0] < K && scoville.size() >= 2){
        
        // Min Heap 의 Root Node 값을 pop. vector의 맨 뒤로 가게 된다.
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        // 맨 뒤 값을 임시 저장 후 pop.
        int n1 = scoville.back();
        scoville.pop_back();
        
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        int n2 = scoville.back();
        scoville.pop_back();
        
        int res = n1 + (n2 * 2);
        scoville.push_back(res);
        push_heap(scoville.begin(), scoville.end(), greater<int>());
        
        answer++;
    }
    
    
    if(scoville[0] < K) answer = -1;
    
    return answer;
}

// priority_queue 이용 가능
// priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end())

// pq.top(); -> root node
// pq.pop(); -> root node 삭제
// pq.push(); -> heap에 추가