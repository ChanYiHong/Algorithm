#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    
    map<int, int> m;
    
    deque<int> deq;
    for(auto b : ball){
        deq.push_back(b);
    }
    
    int index = 0;
    while(!deq.empty()){
        int current = order[index];
        
        if(deq.front() == current){
            answer.push_back(current);
            deq.pop_front();
            index++;
            
            while(1){
                if(deq.empty()) break;
                if(m[deq.front()] == 1){
                    answer.push_back(deq.front());
                    deq.pop_front();
                    continue;
                }

                if(m[deq.back()] == 1){
                    answer.push_back(deq.back());
                    deq.pop_back();
                    continue;
                }
                break;
            }
            continue;
        }
        
        if(deq.back() == current){
            answer.push_back(current);
            deq.pop_back();
            index++;
            while(1){
                if(deq.empty()) break;
                if(m[deq.front()] == 1){
                    answer.push_back(deq.front());
                    deq.pop_front();
                    continue;
                }

                if(m[deq.back()] == 1){
                    answer.push_back(deq.back());
                    deq.pop_back();
                    continue;
                }
                break;
            }
            continue;
        }
        
        m[current] = 1;
        index++;
    }
    
    return answer;
}