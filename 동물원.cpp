#include <iostream>
#define mod 9901
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,i;
    cin >> n;
    int D[100001][3] = {1};
    
    D[1][0] = D[1][1] = D[1][2] = 1;
    for(i = 2; i <= n; i++){
        D[i][0] = (D[i-1][0] + D[i-1][1] + D[i-1][2])%mod;
        D[i][1] = (D[i-1][0] + D[i-1][2])%mod;
        D[i][2] = (D[i-1][0] + D[i-1][1])%mod;
    }
    cout << (D[n][0] + D[n][1] + D[n][2])%mod;

    return 0;
}
