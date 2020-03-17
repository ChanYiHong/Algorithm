#include <iostream>
#include <algorithm>

using namespace std;
int p[1001] = {0,};
int D[1001] = {0,};
int dp(int n)
{
    if(n == 1) return p[1];
    if(D[n] > 0) return D[n];
    for(int i = 1; i <= n; i++){
        D[n] = max(D[n], dp(n-i) + p[i]);
    }
    return D[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    cout << dp(n);
    return 0;
}