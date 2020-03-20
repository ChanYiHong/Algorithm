#include <iostream>

using namespace std;

int D[1001];
int dp(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(D[n] > 0) return D[n];
    D[n] = (dp(n-1) + dp(n-2) + dp(n-2))%10007;
    return D[n];
}
//D[n] = D[n-1] + D[n-2] + D[n-2];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    D[1] = 1;
    D[2] = 3;
    for(int i = 3; i <= n; i++){
        D[i] = (D[i-1] + D[i-2] + D[i-2])%10007;
    }
    cout << D[n];
    return 0;
}