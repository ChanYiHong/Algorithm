#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void mean(vector<int>& v)
{
    double sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << round(sum / v.size()) << '\n';
}
void median(vector<int>& v)
{
    sort(v.begin(), v.end());
    cout << v[v.size()/2] << '\n';
}
void atmost(vector<int>& v)
{
    int number;
    int count = 0;
    int plus[4001] = {0,};
    int minus[4001] = {0,};

    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0) plus[v[i]]++;
        else if(v[i] < 0) minus[abs(v[i])]++;
        else if (v[i] == 0) plus[0]++;
    }

    int max = -1;
    for(int i = 0; i < 4001; i++){
        if(max < plus[i]) max = plus[i];
        if(max < minus[i]) max = minus[i];
    }
    vector<int> dummy;
    for(int i = 0; i < 4001; i++){
        if(max == plus[i]) dummy.push_back(i);
        if(max == minus[i]) dummy.push_back(-i);
    }

    sort(dummy.begin(), dummy.end());
    if(dummy.size() == 1) cout << dummy[0] << '\n';
    else cout << dummy[1] << '\n';
}
void range(vector<int>& v)
{
    sort(v.begin(), v.end());
    cout << v[v.size()-1] - v[0] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    mean(vec);
    median(vec);
    atmost(vec);
    range(vec);

    return 0;
}