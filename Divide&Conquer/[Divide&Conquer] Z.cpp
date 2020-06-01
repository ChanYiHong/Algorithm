#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, r, c;
int cnt = 0;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

void DQ(int x, int y, int size)
{
    if(size == 1){
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(r == nx && c == ny) {
                cout << cnt;
                exit(0);
            }
            cnt++;          
        }
        return;
    }
    
    if(r >= x && r < x + size && c >= y && c < y + size){
        DQ(x, y, size/2);
        DQ(x, y + size/2, size/2);
        DQ(x + size/2, y, size/2);
        DQ(x + size/2, y + size/2, size/2);
    }
    else{
        cnt += size * size;
        return;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> r >> c;
    int N = pow(2, n);
    DQ(0, 0, N);
    return 0;
}

