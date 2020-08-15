#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    //vector<bool> check(people.size(), false);
    
    int front = 0;
    int rear = people.size()-1;
    
    while(front <= rear){
        if(people[front] + people[rear] > limit){
            answer++;
            rear--;
            continue;
        }
        answer++;
        rear--;
        front++;
    }
    
    
//     while(1){
        
//         bool allCheck = true;
//         int front = 0;
//         int rear = people.size() - 1;
//         bool isTwo = false;
        
//         while(front != rear){
//             if(check[rear]){
//                 rear--;
//                 continue;
//             }
//             if(check[front]){
//                 front++;
//                 continue;
//             }
            
//             if(people[front] + people[rear] <= limit){
                
//                 answer ++;
//                 isTwo = true;
//                 allCheck = false;
//                 check[front] = true;
//                 check[rear] = true;
//                 break;
//             }
//             rear--;
//         }
        
//         if(!isTwo && !check[front]){
            
//             check[front] = true;
//             allCheck = false;
//             answer++;
            
//         }
        
//         if(allCheck) break;
//     }
    
    return answer;
}