#include <iostream>

using namespace std;
int arr[1001];
int v[1001];
// 역 추적
void go(int n)
{
    if(n == 0) return;
    go(v[n]);
    cout << arr[n] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int D[1001];
    for(int i = 1; i <= n; i++){
        D[i] = 1;
        v[i] = 0;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j] && D[i] < D[j] + 1){
                D[i] = D[j] + 1;
                v[i] = j; 
            }
        }
    }
    int max = 0;
    int position = 0;
    for(int i = 1; i <= n; i++){
        if(max < D[i]){
            position = i;
            max = D[i];
        }
    }
    go(position);
    return 0;
}