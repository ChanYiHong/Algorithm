#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    for(int i = n; i > 0; i/=10){
        answer += i%10;
    }
    
    return answer;
}