#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int last = arr[0];
    answer.push_back(arr[0]);
    for(int number : arr){
        if(last == number) continue;
        else{
            answer.push_back(number);
            last = number;
        }
    }

    return answer;
}