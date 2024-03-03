#include <cstdio>
int main() {int q;scanf("%d", &q);while(q--){long long n;scanf("%lld", &n);if(n%9==0||n%3==2)puts("TAK");else puts("NIE");}}