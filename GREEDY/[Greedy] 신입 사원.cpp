#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<pair<int,int> > v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());

        int ans = n;
        int bound = v[0].second;
        
        for(int i = 1; i < n; i++){
            if(v[i].second > bound){
                ans--;
            }
            bound = min(bound, v[i].second);
        }
        
        cout << ans << '\n';
    }

    return 0;
}







