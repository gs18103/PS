#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;

int main(){
	int n;
	scanf("%d", &n);
	int a = (n+1)/3;
	int b = (n+1)/3;
	int c= n-a-b;
	printf("%d\n", a*b+b*c+c*a+1+a+b+c);
	return 0;
}
