#include <string>
#include <vector>
#include <cstring>

using namespace std;

int memorization[100001];

int dp(int n){
    
    int& ret = memorization[n];
    
    if(ret != -1){
        return ret;
    }
    
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    ret = (dp(n-1) + dp(n-2))%1234567;
    
    return ret;
}

int solution(int n) {
    int answer = 0;

    memset(memorization, -1, sizeof(memorization));
    
    answer = dp(n);
    
    return answer;
}