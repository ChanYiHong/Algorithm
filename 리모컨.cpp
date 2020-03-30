#include <iostream>
#include <algorithm>
using namespace std;
bool broken[10];
int possible(int c)
{
    if(c == 0){
        return broken[0] ? 0 : 1;
    }
    int len = 0;
    while(c > 0){
        if(broken[c%10]) return 0;
        len += 1;
        c /= 10;
    }
    return len;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, i, j, b, num;
    cin >> n >> b;
    for(i=0;i<b;i++){
        cin >> num;
        broken[num] = true;
    }
    int current;
    int min;
    int count = 0;
    // 그냥 100에서 +, - 만 해서 가는 경우 일단 구함.
    min = n - 100;
    if(min < 0) min = -min;

    for(i = 0; i <= 1000000; i++){
        int c = i;
        int len = possible(c);
        if(len > 0){
            int press = c - n;
            if(press < 0) press = -press;
            if(min > len + press) min = len + press;
        }
    }

    cout << min;

    return 0;
}