#include <iostream>
#include <algorithm>
using namespace std;

bool check[9];
int result[9];

void go(int index, int n, int m)
{
    if(index == m){
        for(int i = 0; i < m; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(check[i] == true) continue;
        if(index == 0 || result[index-1] < i){
            check[i] = true;
            result[index] = i;
            go(index+1, n, m);
            check[i] = false;
        }
    }
}

void go2(int index, int selected, int n, int m)
{
    if(selected == m){
        for(int i = 0; i < m; i++){
            cout << result[i] << ' ';
        }
    }
    cout << '\n';

    if(index > n) return;
    result[selected] = index;
    go2(index + 1, selected + 1, n , m);
    result[selected] = 0;
    go2(index + 1, selected, n, m);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    go(0, n, m);

    return 0;
}