#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    float arr[N];
    float MAX = -1;
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        if(arr[i]>MAX){
            MAX = arr[i];
        }
    }

    float sum = 0;
    for(int i = 0;i<N;i++){
        arr[i] = (arr[i] / MAX)*100;
        sum = sum + arr[i];
    }
    float result = sum / N;

    cout << result;

    return 0;
}