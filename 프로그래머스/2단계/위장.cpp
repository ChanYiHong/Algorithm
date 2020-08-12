#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for(auto c_pair : clothes){
        m[c_pair[1]]++; 
    }
    
    map<string, int>::iterator iter;
    vector<int> kind;
    
    for(iter = m.begin(); iter != m.end(); iter++){
        cout << "[ " << iter->first << " , " << iter->second << " ]" << '\n';
        kind.push_back(iter->second);
    }
 
    for(int i = 0; i < kind.size(); i++){
        answer *= (kind[i] + 1);
    }
    answer--;
    
    return answer;
}


  
//1. (headgear의 수 + 1) 1을 더 해주는 이유는 headgear를 착용하지 않을 수도 있기 때문입니다.
//2. (eyewear의 수 + 1 ) 1을 더 해주는 이유는 eyewear를 착용하지 않을 수도 있기 때문입니다.
//3. 두 수는 각각 독립적이기 때문에 1번 2번의 수를 곱하고 - 1 (모두 안입는 경우는 존재하지 않으므로)