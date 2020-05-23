#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    long long D[31];
    D[0] = 1;
    D[1] = 0;
    D[2] = 3;
    for(int i = 3; i <= n; i++){
        if(i % 2 == 1) D[i] = 0;
        else {
            D[i] = D[i-2] * 3;
            for(int j = 4; i - j >= 0 ; j+=2){
                D[i] += 2 * D[i-j];
            }
        }
    }
    cout << D[n];
    return 0;
}