#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> list;
    for(long long i = n; i > 0; i/=10){
        list.push_back(i%10);
    }
    sort(list.begin(), list.end());
    int dot = 1;
    for(int i = 0; i < list.size(); i++){
        answer += list[i] * dot;
        dot *= 10;
    }   
    
    return answer;
}