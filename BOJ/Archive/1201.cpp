#import<cstdio>
int main(){int n,m,k,c=1,i;scanf("%d%d%d",&n,&m,&k);if(m*k<n||m+k-1>n){puts("-1");return 0;}while(c<=n){while(n-c-k+1<m-1)k--;for(i=c+k-1;i>=c;i--)printf("%d ",i);c+=k;m--;}}