#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair <int, int> > vec;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(b,a));
    }
    vector<pair<int, int> >::iterator iter; 
    sort(vec.begin(), vec.end());

    for(iter = vec.begin(); iter != vec.end(); iter++){
        cout << iter-> second << " ";
        cout << iter-> first << '\n';
    }

    return 0;
}