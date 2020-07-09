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
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(make_pair(str.length(),str));
    }
    sort(v.begin(), v.end());
    vector<pair<int, string> >::iterator iter;
    string last;
    for(iter = v.begin(); iter != v.end(); iter++){
        if(iter == v.begin()){
            cout << iter->second << '\n';
            last = iter->second;
            continue;
        }
        if(last == iter->second) continue;
        else{
            cout << iter->second << '\n';
            last = iter->second;
        }
    }
    return 0;
}