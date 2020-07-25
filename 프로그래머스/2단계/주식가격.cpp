#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    // for(int i = 0; i < prices.size(); i++){
    //     int time = 0;
    //     int standard = prices[i];
    //     for(int j = i+1; j < prices.size(); j++){
    //         time++;
    //         if(prices[j] < standard) break;
    //     }
    //     answer.push_back(time);
    // }
    
    // 정답 보니까 실제 값이 아니라 index로 스택 활용했음 ㄷㄷ
    
    stack<int> s;
    
    for(int i = 0; i < prices.size(); i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }
    
    return answer;
}