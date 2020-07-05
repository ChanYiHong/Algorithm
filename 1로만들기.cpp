#include <iostream>

using namespace std;
int D[1000000];
// Top - Down
int dp(int n)
{
    // 탈출 조건
    if(n == 1) return 0;
    // 메모이제이션
    if(D[n] > 0) return D[n];
    // 거꾸로 가면서 최소값을 찾음
    // D[n] : N을 1로 만드는 최소 연산 횟수
    // D[n] = min(D[N/3], D[N/2], D[N-1]) + 1
    D[n] = dp(n-1) + 1;
    if(n % 2 == 0){
        int temp = dp(n/2) + 1;
        if(D[n] > temp) D[n] = temp;
    }
    if(n % 3 == 0){
        int temp = dp(n/3) + 1;
        if(D[n] > temp) D[n] = temp;
    }
    return D[n];
}
// Bottom - Up
int dp2(int n)
{
    for(int i = 2; i < n; i++){
        D[i] = D[i-1] + 1;
        if(i % 2 == 0 && D[i] > D[i/2] + 1){
            D[i] = D[i/2] + 1;
        }
        if(i % 3 == 0 && D[i] > D[i/3] + 1){
            D[i] = D[i/3] + 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int num;
    cin >> num;
    // D[1] = 0;  // Bottom Up 에 필요.
    cout << dp(num);
    return 0;
}