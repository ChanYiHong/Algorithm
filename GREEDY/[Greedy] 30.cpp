#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool descending(int &a, int &b){
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string num;
    cin >> num;
    int n = 0;
    vector<int> v;

    for(int i = 0; i < num.length(); i++){
        int temp = num[i] - '0';
        v.push_back(temp);
        n++;
    }
    sort(v.begin(), v.end(), descending);

    // 3의 배수는 각 자리 다 더해서 3의 배수면 3의 배수..
    long long sum = 0;
    for(int i = 0; i < v.size() - 1; i++){
        sum += v[i];
    }

    if(v[v.size()-1] != 0 || sum % 3 != 0) cout << -1;
    else{
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
        }
    }
    return 0;
}

