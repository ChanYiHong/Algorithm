#include <iostream>
#define mod 10007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, i, j, l;
    cin >> n;
    long long D[1001][10];
    for(i = 0; i <= 9; i++){
        D[1][i] = 1;
    }
    for(i = 2; i <= n; i++){
        for(j = 0; j <= 9; j++){
            D[i][j] = 0;
            for(l = 0; l <= 9; l++){
                if(j >= l) D[i][j] += (D[i-1][l])%mod;
            }
        }
    }
    long long answer = 0;
    for(i = 0; i <= 9; i++){
        answer += D[n][i]; 
    }
    cout << answer % mod;
    
    return 0;
}