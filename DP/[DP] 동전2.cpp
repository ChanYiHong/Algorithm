#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int coin[101];
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    int D[10001];
    for(int i = 1; i <= 10001; i++) D[i] = 100001;
    D[0] = 0;

    for(int i = 0; i < n; i++){
        int value = coin[i];
        for(int j = value; j <= k; j++){
            D[j] = min(D[j], D[j - value] + 1);
        }
    }
    if(D[k] == 100001) cout << -1;
    else cout << D[k];
    
    return 0;
}