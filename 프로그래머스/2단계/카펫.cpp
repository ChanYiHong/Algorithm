#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    int height = 3;
    while(1){
        if(total % height == 0){
            int width = total / height;
            if((height - 2) * (width - 2) == yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
        height++;
    }   
    return answer;
}