#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int> > pv;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pv.push_back(make_pair(a,b));
    }
        
    for(vector<pair<int, int> >::size_type i = 0; i<pv.size();i++){
        int cnt = 0;
        for(vector<pair<int, int> >::size_type j = 0; j<pv.size();j++){
            if(i==j) continue;
            if(pv[i].first < pv[j].first && pv[i].second < pv[j].second){
                cnt++;
            }
        }
        cout << cnt + 1 << " ";
    }

    return 0;
}