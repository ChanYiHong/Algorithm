#include <iostream>
#define mod 15746
using namespace std;
int D[1000000];
int dp(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(D[n] > 0) return D[n];
    D[n] = (dp(n-1) + dp(n-2)) % mod;
    return D[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    cout << dp(n) % mod;
    return 0;
}
