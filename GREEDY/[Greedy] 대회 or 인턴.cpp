#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    // n 이 8, m 이 2
    // 여학생이 남학생에 비해 많은 경우
    if(n / 2 >= m){
        // 남는 여학생
        // 8 - 4 = 4명이 남음
        int temp = n - (m*2);
        if(temp >= k){
            cout << m;
        }
        else{
            int dif = k - temp;
            if(dif %3 == 0){
                dif = dif/3;
            }  
            else{
                dif = dif/3 + 1;
            }
            cout << m - dif;
        }   
    }
    // 남학생이 여학생에 비해 많은 경우
    else{
        // 남는 남학생
        int temp = m - (n/2);
        if(temp >= k){
            cout << n / 2;
        }
        else{
            int dif = k - temp;
            if(dif %3 == 0){
                dif = dif/3;
            }  
            else{
                dif = dif/3 + 1;
            }
            cout << (n / 2) - dif;
        }
    }
    return 0;
}