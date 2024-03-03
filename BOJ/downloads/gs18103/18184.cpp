#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;

vector<int> asdf;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	if(k==1<<n){
		printf("YES\n");
		for(int i=0;i<(1<<n);i++) printf("%d ", i);
		printf("\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		int a=1<<i;
		if(a&k){
			for(int j=a;j<2*a;j++) asdf.push_back(j);
		}
	}
	printf("YES\n");
	for(auto &i : asdf){
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}
