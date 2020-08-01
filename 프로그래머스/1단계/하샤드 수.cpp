#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int sum = 0;
    for(int i = x; i > 0; i/=10){
        sum+=i%10;
    }
    return x % sum == 0 ? true : false;
}