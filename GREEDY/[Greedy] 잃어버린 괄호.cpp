#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    char str[51];
    cin >> str;
    vector<int> v;

    // - 인 곳을 기준으로 나눠서, 괄호를 쳐주면 됨
    // 최대한 크게 다 더한다음 뭉탱이로 빼기
    
    int i = 0;
    int num = 0;
    int sum = 0;
    while(str[i]){
        if(str[i] == '+'){
            sum += num;
            num = 0;
        }
        else if(str[i] == '-'){
            sum += num;
            v.push_back(sum);
            num = 0;
            sum = 0;
        }
        else{
            num *= 10;
            num += (str[i] - '0'); 
        }
        i++;
    }
    sum += num;
    v.push_back(sum);

    int answer = v[0];
    for(int i = 1; i < v.size(); i++){
        answer -= v[i];
    }
    cout << answer;

    return 0;
}