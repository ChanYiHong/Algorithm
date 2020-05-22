#include <iostream>
#include <algorithm>
using namespace std;

int answer[9];
void go(int index, int selected, int n, int m)
{
    if(selected == m){
        for(int i = 0; i < m; i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(index > n) return;
    answer[selected] = index;
    go(index, selected + 1, n , m);
    go(index + 1, selected, n, m);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    
    return 0;
}