#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int E_n, S_n, M_n;
    cin >> E_n >> S_n >> M_n;
    int E, S, M, count;
    E = S = M = count = 1;
    while(1){
        if(E_n == E && S_n == S && M_n == M) break;
        E++;
        S++;
        M++;
        if(E == 16) E = 1;
        if(S == 29) S = 1;
        if(M == 20) M = 1;  
        count++;
    }
    cout << count;
    return 0;
}