#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double res = sqrt(n);
    int res2 = sqrt(n);
    if(res - res2 == 0) answer = pow(res + 1, 2);
    else answer = -1;
    
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}