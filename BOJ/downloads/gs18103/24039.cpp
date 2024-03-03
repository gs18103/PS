#include <bits/stdc++.h>

#define fi first

#define se second

#define all(v) v.begin(), v.end()

#define eb emplace_back

#define em emplace

using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

typedef pair <ll, ll> pll;

int chk[10101];

vector <int> p;

int main() {

	    ios::sync_with_stdio(false);          	

	    int n;

	    cin >> n;

	

    	for(int i = 2; i <= 10000; i++) {

		        if(chk[i]) continue;

		        p.eb(i);

		        for(int j = i * i; j <= 10000; j += i) {

			            chk[j] = true;

		        }

    	}

	

	    for(int i = 0; i + 1 < p.size(); i++) {

		        if(p[i] * p[i+1] > n) {

			            cout << p[i] * p[i+1];

			            return 0;

	        	}

	    }

}