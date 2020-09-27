#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool descending(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), descending);
    
    int maximum = 0;
    int len = citations.size();
    for(int i = len; i > 0; i--){
        if(i <= citations[i-1]){
            maximum = i;
            break;
        }
    }
    answer = maximum;
    
    return answer;
}