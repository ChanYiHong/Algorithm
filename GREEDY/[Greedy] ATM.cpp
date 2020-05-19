#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int answer = 0;
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += arr[i];
        answer += temp;
    }
    cout << answer;

    return 0;
}