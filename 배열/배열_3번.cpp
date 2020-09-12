#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    int result;

    result = A * B * C;

    int temp = result;
    int count = 1;
    while(temp/10 != 0){
        temp = temp / 10;
        count++;
    }

    int arr[10] = {0,};
    int temp1 = 0;
    int temp2 = 0;

    for(int j =0;j<count;j++){
        temp1 = result / (pow(10, j));
        temp2 = temp1 % 10;
        arr[temp2] = arr[temp2] + 1; 
    }
    

    for(int i =0;i<10;i++){
        cout << arr[i] << '\n';
    }

    return 0;
}