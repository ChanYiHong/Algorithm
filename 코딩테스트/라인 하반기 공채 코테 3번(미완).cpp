#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 987654321

using namespace std;

pair<int, int> dp(int n, int cnt){
    
    if(n < 10) {
        pair<int, int> ret = {n, cnt};
        return ret;
    }
    
    int retCnt = INF;
    pair<int, int> ret;
    
    int division = 10;
    while(1){
        int quotient = n/division;
        int remainder = n%division;
        
        if(quotient == 0) break;
        
        if((division/10) > remainder){
            division *= 10;
            continue;
        }
        
        pair<int, int> curRet = dp(quotient + remainder, cnt+1);
        
        if(retCnt > curRet.second){
            ret = curRet;
            retCnt = ret.second;
        }
    }
    
    return ret;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    pair<int, int> ret = dp(n, 0);
    
    answer.push_back(ret.second);
    answer.push_back(ret.first);
    
    return answer;
}
