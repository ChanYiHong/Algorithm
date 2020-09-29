#include <iostream>

using namespace std;

int next_round(int x){
    if(x % 2 == 0){
        return x/2;
    }
    else{
        return x/2 + 1;
    }
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(a != b){
        a = next_round(a);
        b = next_round(b);
        
        answer++;
    }

    return answer;
}