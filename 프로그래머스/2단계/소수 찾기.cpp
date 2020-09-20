#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<bool> check(10000000, true);
vector<int> nums;
map<int, int> m;
int N;
int cnt = 0;

void findPrimeNumber(int len, int currentNum, vector<bool> checkSelect){
    
    if(len == N){
        // 길이 다 끝났을 떄 확인하고 걍 리턴
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        // 이미 currentNum에 추가된 숫자일 경우는 패스!
        if(checkSelect[i]) continue;
        
        // 맨 앞이 0인경우 패스
        if(len == 0 && nums[i] == 0) continue;
        
        int temp = nums[i] * pow(10, len);
        
        currentNum += temp;
        
        if(check[currentNum] && m[currentNum] != 1) {
            m[currentNum]++;
            cnt++;
        }
        checkSelect[i] = true;
        findPrimeNumber(len+1, currentNum, checkSelect);
        checkSelect[i] = false;
        currentNum -= temp;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    
    check[0] = false;
    check[1] = false;
    for(int i = 2; i < 10000000; i++){
        if(check[i] == false) continue;
        for(int j = i + i; j < 10000000; j+=i){
            check[j] = false;
        }
    }
    
    for(int i = 0; i < numbers.length(); i++){
        nums.push_back(numbers[i] - '0');
    }
    
    N = nums.size();
    
    vector<bool> checkSelect(nums.size(), false);
    
    findPrimeNumber(0, 0, checkSelect);
    
    answer = cnt;
    
    return answer;
}