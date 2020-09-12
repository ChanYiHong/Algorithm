#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10];
    for(int i =0;i<10;i++){
        cin >> arr[i];
    }
    int arr2[10];
    for(int i =0;i<10;i++){
        arr2[i] = arr[i]%42;
    }
    
    int count = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i == j){
                count++;
                break;
            }
            if(arr2[j] == arr2[i]){
                break;
            }
        }
    }

    cout << count;
    return 0;
}