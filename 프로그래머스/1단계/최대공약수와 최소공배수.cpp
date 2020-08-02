#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    // 최대 공약수
    answer.push_back(gcd(n, m));
    // 최소 공배수
    answer.push_back(n*m/answer[0]);
    return answer;
}