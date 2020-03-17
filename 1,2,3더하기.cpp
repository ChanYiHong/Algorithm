#include <iostream>

using namespace std;
int D[11];
int dp(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    if(D[n] > 0) return D[n];
    D[n] = dp(n-1) + dp(n-2) + dp(n-3);
    return D[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << dp(n) << '\n';
    }
    return 0;
}