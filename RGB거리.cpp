#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long D[1001][3];
    long long pay[1001][3];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            int num;
            cin >> num;
            pay[i][j] = num;
        }
    }
    D[1][0] = pay[1][0];
    D[1][1] = pay[1][1];
    D[1][2] = pay[1][2];
    for(int i=2;i<=n;i++){
        D[i][0] = D[i][1] = D[i][2] = 0;
        D[i][0] += min(D[i-1][1], D[i-1][2]) + pay[i][0];
        D[i][1] += min(D[i-1][0], D[i-1][2]) + pay[i][1];
        D[i][2] += min(D[i-1][0], D[i-1][1]) + pay[i][2];
    }
    long min = 1000000000;
    for(int i = 0; i < 3; i++){
        if(min > D[n][i]) min = D[n][i];
    }
    cout << min;
    return 0;
}


