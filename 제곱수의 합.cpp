#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,i,j;
    cin >> n;
    long long D[100001];
    for(i = 1; i <= n; i++){
        // 1의 제곱의 덧셈 꼴이 초기값이 됨
        D[i] = i;
        for(j = 1; j * j <= i; j++){
            // D[n] = D[n - i*i] + 1;
            if(D[i] > D[i - j * j] + 1){
                D[i] = D[i - j*j] + 1;
            }
        }
    }
    cout << D[n];
    return 0;
}