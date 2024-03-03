#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    if(n % 6 == 0) {
        cout << "1 2\n2 3\n2 4\n4 5\n5 6\n";
    }
    else if(n % 6 == 1) {
        cout << "1 2\n2 3\n2 4\n4 5\n5 6\n4 " << n << '\n';
    }
    else if(n % 6 == 2) {
        cout << "1 2\n2 3\n3 4\n4 5\n5 6\n2 " << n - 1 << "\n4 " << n << "\n";
    }
    else if(n % 6 == 3) {
        cout << "1 2\n2 3\n3 4\n3 5\n5 6\n4 " << n - 2 << "\n3 " << n - 1 << "\n" << n - 1 << " " << n << "\n";
    }
    else if(n % 6 == 4) {
        cout << "1 2\n2 3\n3 4\n3 5\n5 6\n4 " << n - 2 << "\n3 " << n - 1 << "\n" << n - 1 << " " << n << "\n";
        cout << n - 3 << " 4\n";
    }
    else if(n % 6 == 5) {
        cout << "1 2\n2 3\n3 4\n4 5\n5 6\n";
        cout << n << ' ' << n - 1 << '\n';
        cout << n - 1 << ' ' << n - 2 << '\n';
        cout << n - 2 << ' ' << n - 3 << '\n';
        cout << "4 " << n - 3 << '\n';
        cout << "4 " << n - 4 << '\n';
    }
    for(int i = 1; i < n / 6; i++) {
        cout << 6 * i << ' ' << 6 * i + 1 << '\n';
        cout << 6 * i + 1 << ' ' << 6 * i + 2 << '\n';
        cout << 6 * i << ' ' << 6 * i + 3 << '\n';
        cout << 6 * i + 3 << ' ' << 6 * i + 4 << '\n';
        cout << 6 * i << ' ' << 6 * i + 5 << '\n';
        cout << 6 * i + 5 << ' ' << 6 * i + 6 << '\n';
    }
}