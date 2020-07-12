#include <iostream>

using namespace std;

int queue[2000001];
int head = 0;
int tail = 0;
void push(int X)
{
    queue[tail] = X;
    tail++;
}
void pop()
{
    if(head == tail) cout << -1 << '\n';
    else{
        cout << queue[head] << '\n';
        head++;
    }
}
void size()
{
    cout << tail - head << '\n';
}
void empty()
{
    if(head == tail) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void front()
{
    if(head == tail) cout << -1 << '\n';
    else cout << queue[head] << '\n';
}
void back()
{
    if(head == tail) cout << -1 << '\n';
    else cout << queue[tail-1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    string str;
    int num;
    for(int i = 0; i < N; i++){
        cin >> str;
        if (str == "push"){
            cin >> num;
            push(num);
        }
        else if (str == "pop") pop();
        else if (str == "size") size();
        else if (str == "empty") empty();
        else if (str == "front") front();
        else if (str == "back") back();
    }
    return 0;
}