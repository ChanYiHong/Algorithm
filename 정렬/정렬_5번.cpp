#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long N;
    cin >> N;
    vector<long long> vec;
    for(long long i = N; i >= 1; i/=10){
        vec.push_back(i%10);
    }
    sort(vec.begin(), vec.end(), desc);
    for(long long i = 0; i < vec.size(); i++){
        cout << vec[i];
    }

    return 0;
}