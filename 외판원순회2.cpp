#include <iostream>
#include <algorithm>
using namespace std;
int w[10][10];
int calculate(int *a, int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(w[a[i-1]][a[i]] == 0) return -1;
        sum += w[a[i-1]][a[i]];
    }
    if(w[a[n-1]][a[0]] == 0) return -1;
    sum += w[a[n-1]][a[0]];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, i ,j;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++){
        arr[i] = i; 
        for(j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }
    int min = 40000000;
    do{
        int result = calculate(arr, n);
        if(result == -1) continue;
        if(min > result) min = result;
    }while(next_permutation(arr, arr+n));
    cout << min;

    return 0;
}