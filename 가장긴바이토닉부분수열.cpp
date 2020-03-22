#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, i, j;
    cin >> n;
    int list[1001];
    long long up[1001];
    long long down[1001];
    for(i = 1; i <= n; i++){
        cin >> list[i];
    }
    up[1] = 1;
    // 증가하는 쪽
    for(i = 2; i <= n; i++){
        up[i] = 1;
        for(j = 1; j < i; j++){
            if(list[j] < list[i] && up[i] < up[j] + 1){
                up[i] = up[j] + 1;
            }
        }
    }
    // 감소하는 쪽
    down[n] = 1;
    for(i = n-1; i >= 1; i--){
        down[i] = 1;
        for(j = n; j > i; j--){
            if(list[j] < list[i] && down[i] < down[j] + 1){
                down[i] = down[j] + 1;
            }
        }
    }
    int max = 0;
    for(i = 1; i <= n; i++){
        if(max < up[i] + down[i] - 1) max = up[i] + down[i] - 1;
    }
    cout << max;
    return 0;
}
       

