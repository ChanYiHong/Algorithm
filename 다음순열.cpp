#include <iostream>
#include <algorithm>
using namespace std;

bool next_permutation(int *a, int n)
{
    // 내림차순이 끝나는 지점을 찾음.
    int i = n - 1;
    while(a[i] < a[i-1] && i != 0) i -= 1;
    // 내림 차순이면 끝 순열임.
    if(i == 0) return false;
    // i-1 번 째 있는 애보다 더 큰 애를 뒤쪽에서 찾음
    int j = n - 1;
    while(a[j] <= a[i-1]) j -= 1;
    swap(a[i-1], a[j]);
    // 뒤에 있는 걸 오름차순으로 정리
    j = n - 1;
    while(i < j){
        swap(a[i], a[j]);
        i+=1;
        j-=1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(next_permutation(arr, n)){
        for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
    }
    else cout << -1;
    return 0;
}