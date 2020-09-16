#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0;i<T;i++){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int k = 0;
        while(str[k] != '\0'){
            for(int j=0;j<n;j++){
                cout << str[k];
            }
            k++;
        }
        cout << '\n';
    }
    return 0;
}