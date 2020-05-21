#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int coin[6] = {500, 100, 50, 10, 5, 1};

    int total = 0;
    int change = 1000 - n;
    for(int i = 0; i < 6; i++){
        total += change / coin[i];
        change %= coin[i];
    }
    cout << total;

    return 0;
}