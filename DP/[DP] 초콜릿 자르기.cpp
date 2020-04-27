#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int t = n*m;
    int D[t];

    D[1] = 0;
    for(int i = 2; i <= t; i++){
        int a = i / 2;
        int b = i - a; 
        D[i] = D[a] + D[b] + 1;
    }
    cout << D[t];
    return 0;
}