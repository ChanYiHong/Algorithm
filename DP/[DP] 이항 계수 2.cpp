#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 0; i < 5; ++i){
        cout << i << '\n';
    }

    for(int i = 0; i < 5; i++){
        cout << i << '\n';
    }

    string name = "";
    name = name + "hello";
    cout << name;

    int k = 1;
    string temp = "";
    temp += (k + '0');
    cout << temp;

    return 0;
}