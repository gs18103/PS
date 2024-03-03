#include <bits/stdc++.h>

using namespace std;

int arr[1010101];

void merge_sort(int s, int e) {
    if(s == e) return;
    int m = (s + e) / 2;
    merge_sort(s, m);
    merge_sort(m+1, e);

    int idx1 = s, idx2 = m + 1;
    vector <int> v;
    while(idx1 <= m && idx2 <= e) {
        if(arr[idx1] < arr[idx2]) v.push_back(arr[idx1++]);
        else v.push_back(arr[idx2++]);
    }
    while(idx1 <= m) v.push_back(arr[idx1++]);
    while(idx2 <= e) v.push_back(arr[idx2++]);
    for(int i = s; i <= e; i++) {
        arr[i] = v[i-s];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    merge_sort(1, n);

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << '\n';
    }
}