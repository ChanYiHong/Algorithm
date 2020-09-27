#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    int cur = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        cur = lcm(cur, arr[i]);
    }
    
    answer = cur;
    
    return answer;
}