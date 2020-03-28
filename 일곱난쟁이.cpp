#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int dwarf[9];
    int i,j,k, sum = 0;
    for(i=0;i<9;i++){
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf+9);
    for(i=0;i<9;i++){
        for(j=i+1;j<9;j++){
            if(sum - dwarf[i] - dwarf[j] == 100){
                for(k=0;k<9;k++){
                    if(k==i || k==j) continue;
                    cout << dwarf[k] << '\n';
                }
                return 0;
            }
        }
    }
}