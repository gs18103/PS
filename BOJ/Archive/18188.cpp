#include<bits/stdc++.h>
#define N 25

using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int, string> tii;

int n, h, w;

char a[N][N];

pi p[N], q[N];

pi f(char c){
	if(c=='W'){
		return pi(-1, 0);
	}
	if(c=='A'){
		return pi(0, -1);
	}
	if(c=='S'){
		return pi(1, 0);
	}
	if(c=='D'){
		return pi(0, 1);
	}
}

bool g(pi t){
	if(t.first<0||t.first>=h) return 0;
	if(t.second<0||t.second>=w) return 0;
	if(a[t.first][t.second]=='@') return 0;
	return 1;
}

char tt[N], uu[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w;
	for(int i=0;i<h;i++) cin>>a[i];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tt[i]>>uu[i];
		p[i]=f(tt[i]);
		q[i]=f(uu[i]);
	}
	int dx, dy;
	int zx, zy;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='D'){
				dx=i;
				dy=j;
			}
			if(a[i][j]=='Z'){
				zx=i;
				zy=j;
			}
		}
	}
	queue<tii> qu;
	qu.push(make_tuple(0, dx, dy, ""));
	while(!qu.empty()){
		int lv, x, y;
		string s;
		tie(lv, x, y, s) = qu.front();
		qu.pop();
		if(x==zx&&y==zy){
			cout<<"YES\n";
			cout<<s<<"\n";
			return 0;
		}
		if(lv==n) continue;
		pi t=pi(x+p[lv].first, y+p[lv].second);
		pi u=pi(x+q[lv].first, y+q[lv].second);
		if(g(t)) qu.push(make_tuple(lv+1, t.first, t.second, s+tt[lv]));
		if(g(u)) qu.push(make_tuple(lv+1, u.first, u.second, s+uu[lv]));
	}
	cout<<"NO\n";
	return 0;
}
