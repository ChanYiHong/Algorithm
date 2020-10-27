#include <iostream>
#include <vector>
#define A 300
#define B 60
#define C 10

using namespace std;

vector<int> microwave(int N){
    
    vector<int> ret(3, 0);
    int num = N;

    while(num > 0){
        if(num >= A){
            num -= A;
            ret[0]++;
        }else if(num >= B && num < A){
            num -= B;
            ret[1]++;
        }else if(num >= C && num < B){
            num -= C;
            ret[2]++;
        }else{
            break;
        }
    }

    if(num != 0){
        ret[0] = -1;
    }
    
    return ret;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> ans = microwave(n);
    if(ans[0] == -1){
        cout << -1;
        exit(0);
    }
    for(int i = 0; i < 3; i++){
        cout << ans[i] << " ";
    }

    return 0;
}