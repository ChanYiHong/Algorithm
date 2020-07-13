#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 1; i < N; i++){
        int sum = i;
        int copy = i;
        while (copy){
            sum += (copy % 10);
            copy /= 10;
        }
        if(sum == N){
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';

    return 0;
}