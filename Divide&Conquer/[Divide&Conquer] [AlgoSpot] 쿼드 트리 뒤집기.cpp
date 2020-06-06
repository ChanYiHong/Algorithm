#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str;

string reverse(string::iterator& it)
{
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w') return string(1, head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        string::iterator iter = str.begin();
        string res = reverse(iter);
        cout << res << '\n';
        str.clear();
    }
    return 0;
}