#include <iostream>
#include <algorithm>
using namespace std;

int answer[8];
void go(int index, int n, int m)
{
    if(index == m){
        for(int i = 0; i < m; i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        answer[index] = i;
        go(index+1, n, m);
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    go(0, n, m);

    return 0;
}