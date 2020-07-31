#include <string>
#include <vector>

using namespace std;

int TARGET;
int INDEX;

int dfs(int sum, int index, vector<int>& num){
    if(sum == TARGET && index == INDEX) return 1;
    if(index == INDEX) return 0;
    
    int ret = 0;
    
    ret += dfs(sum + num[index], index + 1, num);
    ret += dfs(sum - num[index], index + 1, num);
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    TARGET = target;
    INDEX = numbers.size();
    
    answer = dfs(0, 0, numbers);
    
    return answer;
}