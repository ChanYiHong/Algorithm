#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, string> > v;
    for(int i = 0; i < N; i++){
        int num;
        string str;
        cin >> num >>str;
        v.push_back(make_pair(num,str));
    }
    sort(v.begin(), v.end());
    vector<pair<int, string> >::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++){
        cout << iter->first << " ";
        cout << iter->second << '\n';
    }
    return 0;
}