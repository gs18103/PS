#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

int arr[MAX], brr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 30; i >= 0; i--) {
        if((m >> i) & 1) {
            for(int j = 0; j < n; j++) {
                brr[j] = arr[j];
            }
            for(int j = 0; j < n; j++) {
                if(arr[j]) {
                    brr[((j - (1 << i)) % n + n) % n] ^= 1;
                }
            }
            for(int j = 0; j < n; j++) {
                arr[j] = brr[j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}