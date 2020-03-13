#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    stack<int> s;
    vector<char> v;
    int count = 0;
    int success = 1;
    for(int i = 0; i < N; i++){
        while(1){
            if(arr[i] > count){
                s.push(++count);
                v.push_back('+');
                continue;
            }
            if(arr[i] == s.top()){
                s.pop();
                v.push_back('-');
                break;
            }
            if(arr[i] < s.top()){
                success = 0;
                break;
            }
        }
        if(success == 0) break;
    }
    if(success == 0) cout << "NO";
    else{
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << '\n';
        }
    }
    return 0;
}
