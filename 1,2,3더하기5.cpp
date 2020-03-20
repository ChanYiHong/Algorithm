#include <iostream>
#define mode 1000000009
using namespace std;
long long D[100001][4];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    D[0][1] = D[0][2] = D[0][3] = D[1][2] = D[1][3] = D[2][1] = D[2][3] = 0;
    D[1][1] = D[2][2] = D[3][1] = D[3][2] = D[3][3] = 1;
    for(int i = 4; i < 100000; i++){
        D[i][1] = (D[i-1][2] + D[i-1][3])%mode;
        D[i][2] = (D[i-2][1] + D[i-2][3])%mode;
        D[i][3] = (D[i-3][1] + D[i-3][2])%mode;
    }
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        cout << (D[n][1] + D[n][2] + D[n][3])%mode << '\n';
    }
    return 0;
}