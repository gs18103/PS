#include <bits/stdc++.h>

using namespace std;

int L[1010], R[1010], A[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for(int i = 1; i <= n; i++) {
        L[i] = 1;
        for(int j = 1; j < i; j++) {
            if(A[j] < A[i]) L[i] = max(L[i], L[j] + 1);
        }
    }

    for(int i = n; i >= 1; i--) {
        R[i] = 1;
        for(int j = n; j > i; j--) {
            if(A[j] < A[i]) R[i] = max(R[i], R[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, L[i] + R[i] - 1);
    }
    cout << ans;
}