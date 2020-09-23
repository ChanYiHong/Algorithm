int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

using namespace std;

long long solution(int w,int h) {
    
    long long W = w;
    long long H = h;
    
    long long cutted = W + H - gcd(w,h);
    long long answer = W * H - cutted;
    
    return answer;
}