#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbysec(pair<int, int> &a, pair<int, int> &b){
    return (a.second < b.second);    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    // first 부분 sort
    sort(v.begin(), v.end());
    // second 부분 sort
    sort(v.begin(), v.end(), sortbysec);

    int cnt = 1;
    int loc = v[0].second;
    for(int i = 1; i < n; i++){
        if(loc <= v[i].first){
            loc = v[i].second;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}