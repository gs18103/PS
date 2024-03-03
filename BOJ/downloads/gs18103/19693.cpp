#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, h;
    cin >> n >> h;
    long long arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long> > right;
    left.push(arr[0]);
    right.push(arr[0]);
    int prel = arr[0];
    int prer = arr[0];
    long long acc = 0;
    for(int i = 1;i < n;i++){
        long long shift = i * h;
        long long l = left.top() - shift;
        long long r = right.top() + shift;
        long long x = arr[i];
        if(x >= r){
            right.push(x - shift);
            right.push(x - shift);
            left.push(right.top() + 2 * shift);
            right.pop();
            acc += abs(x - (left.top() - shift));
        }
        else if(x <= l){
            left.push(x + shift);
            left.push(x + shift);
            right.push(left.top() - 2 * shift);
            left.pop();
            acc += abs(x - (right.top() + shift));
        }
        else{
            left.push(x + shift);
            right.push(x - shift);
        }
        l = left.top() - shift;
        r = right.top() + shift;
        prel = l;
        prer = r;
    }
    cout << acc;
    return 0;
}