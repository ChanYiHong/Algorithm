#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int arr[n];
        int count = 0;
        int order[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(count <= 5){
                order[i] = 0;
            }
            else{
                order[i] = 1;
            }
            count++;
        }
        do{
            for(int i = 0; i < n; i++){
                if(order[i] == 0){
                    cout << arr[i] << ' ';
                }
            }
            cout << '\n';
        }while(next_permutation(order, order+n));
        cout << '\n';
    }
    return 0;
}