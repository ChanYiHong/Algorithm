#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > data;
vector<vector<int> > D;

int dp(int row, int column){
    
    int& ret = D[row][column];
    if(row == 0){
        ret = data[row][column];
        return ret;
    }
    
    if(ret != -1){
        return ret;
    }
    
    ret = 0;
    
    for(int i = 0; i < data[row].size(); i++){
        if(i == column) continue;
        ret = max(ret, dp(row-1, i));
    }
    
    ret += data[row][column];
    
    return ret;
    
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    data = land;
    int size = land.size();
    D.resize(land.size(), vector<int>(land[0].size(), -1));
    
    for(int i = 0; i < land[0].size(); i++){
        int ret = dp(size-1, i);
        answer = max(answer, ret);
    }
    return answer;
}


