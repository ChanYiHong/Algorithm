#include <iostream>
#include <algorithm>
#include <cstring>
#define M 10007
using namespace std;
int D[1001][1001];

int dp(int N, int K){
    
    if(K == 1 || N == 1) return 1;
    if(K == 0) return 0;  
    int& ret = D[N][K];
    if(ret != -1) return ret;
    
    ret = dp(N-1, K) + dp(N-1, K-1);
    return ret%M;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    memset(D, -1, sizeof(D));
    cout << dp(n, k);
    
    return 0;
}