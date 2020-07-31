#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    sort(nums.begin(), nums.end());
    
    vector<int> each_other;
    
    int last = nums[0];
    each_other.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(last == nums[i]) continue;
        each_other.push_back(nums[i]);
        last = nums[i];
    }
    answer = each_other.size();
    
    if(answer > nums.size() / 2) answer = nums.size() / 2;
    
    return answer;
}