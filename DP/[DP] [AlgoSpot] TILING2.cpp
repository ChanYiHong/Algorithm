#include <iostream>
#include <algorithm>
#include <cstring>

#define M 1000000007

using namespace std;

int N;
int D[101];

int dp(int index)
{
    if(index <= 1) return 1;
    if(D[index] != -1) return D[index];

    D[index] = (dp(index-2) + dp(index-1))%M ;

    return D[index];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        memset(D, -1, sizeof(D));
        cout << dp(N) <<'\n';
    }
    
    return 0;
}