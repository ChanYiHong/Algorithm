#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights);

int main()
{
    vector<int> height;
    height.push_back(6);
    height.push_back(9); 
    height.push_back(5);
    height.push_back(7);
    height.push_back(4);
    vector<int> answer = solution(height);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];
    }
    return 0;
}

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    // index, value
    vector<pair<int, int> > v;
    // v에 저장
    for(int i = 1; i <= heights.size(); i++){
        v.push_back(make_pair(i, heights[i-1]));
    }
    
    stack<pair<int, int> > s;
    
    s.push(v[0]);
    answer.push_back(0);
    
    for(int i = 1; i < v.size(); i++){
        // 스텍에 뭔가 있음. 스텍 탑보다 새로 들어오는게 작으면 바로 그 인덱스가 답
        // 그리고 스텍이 넣음...
        // index는 answer에 넣음
        while(!s.empty()){
            if(v[i].second < s.top().second){
                answer.push_back(s.top().first);
                s.push(v[i]);
            }
            // 만약 새로 들어오는게 top보다 크면 pop..
            else{
                s.pop();
            }
        }
        // 비었으면 다시 넣고 answer에 0
        if(s.empty()){
            s.push(v[i]);
            answer.push_back(0);
        }
    }
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
    
    return answer;
}


