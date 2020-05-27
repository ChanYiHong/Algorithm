#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int juice[10001];
    long long D[10001];
    for(int i = 1; i <= n; i++){
        cin >> juice[i];
    }
    D[0] = 0;
    D[1] = juice[1];
    D[2] = juice[1] + juice[2];
    for(int i = 3; i <= n; i++){
        D[i] = 0;
        D[i] += max(D[i-2] + juice[i], D[i-3]+juice[i-1] + juice[i]);
        D[i] = max(D[i], D[i-1]);
    }
    cout << D[n];
    return 0;
}

//점화식 : D[n] = max(D[n-2]+juice[n], D[n-3]+juice[n] + juice[n-1], D[n-1]);
/*6
10
13
9
8
1
D[6] = max(D[4], D[3] + juice[5], D[5])
마지막을 안 밟아도 됨.


6, 13
D[2] = 12*/