#include <iostream>

using namespace std;
void draw(int x, int y, int size);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            draw(i,j,n);
        }
        cout << '\n';
    }
    return 0;
}
void draw(int x, int y, int size){
    if((x/size)%3==1 && (y/size)%3==1)
        cout << ' ';
    else{
        if(size/3 == 0)
            cout << '*';
        else
            draw(x,y,size/3);
    }
}