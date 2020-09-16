#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    char str[n];
    int sum = 0;

    for(int i=0;i<n;i++)
    {
       cin >> str[i];
       sum += (int(str[i]) - 48);
    }
    cout << sum;
    return 0;
}