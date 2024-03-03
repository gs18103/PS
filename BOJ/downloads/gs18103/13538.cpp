#include <bits/stdc++.h>
#define N 524288
#define K 27
#define M 1000000000
#define INF 2000000000000009LL
#define log 22
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

/*------------------------end of pre code------------------------*/

struct Tree{
    int le,ri,v;
}tree[50*N];
int m,maxn,sz,var[N];
int init_tree(int s,int e){
    int cur=maxn++,m=s+e>>1;
    Tree &now=tree[cur];
    now.v=0;
    if(s==e)
        return cur;
    now.le=init_tree(s,m);
    now.ri=init_tree(m+1,e);
    return cur;
}
int make_tree(int s,int e,int x,int num){
    int cur=maxn++,m=s+e>>1;
    Tree &now=tree[cur]=tree[x];
    if(s==e){
        now.v++;
        return cur;
    }
    if(num>m) now.ri=make_tree(m+1,e,now.ri,num);
    else now.le=make_tree(s,m,now.le,num);
    now.v=tree[now.ri].v+tree[now.le].v;
    return cur;
}
int find_query1(int s,int e,int x,int y,int num){
    if(s==e) return s;
    int m=s+e>>1;
    Tree &t1=tree[x],&t2=tree[y];
    if(((e-s+1>>1)&num)&&tree[t2.le].v==tree[t1.le].v)
        return find_query1(m+1,e,t1.ri,t2.ri,num);
    if(!((e-s+1>>1)&num)&&tree[t2.ri].v!=tree[t1.ri].v)
        return find_query1(m+1,e,t1.ri,t2.ri,num);
    return find_query1(s,m,t1.le,t2.le,num);
}
int find_query2(int s,int e,int x,int y,int num){
    int m=s+e>>1;
    Tree &t1=tree[x],&t2=tree[y];
    if(num<s) return 0;
    if(e<=num) return t2.v-t1.v;
    return find_query2(s,m,t1.le,t2.le,num)+find_query2(m+1,e,t1.ri,t2.ri,num);
}
int find_query3(int s,int e,int x,int y,int num){
    if(s==e) return s;
    int m=s+e>>1;
    Tree &t1=tree[x],&t2=tree[y];
    int sum=tree[t2.le].v-tree[t1.le].v;
    if(sum>=num) return find_query3(s,m,t1.le,t2.le,num);
    num-=sum;
    return find_query3(m+1,e,t1.ri,t2.ri,num);
}

int main(){
    int a,l,r,x,n=N,ans;
    scanf("%d",&m);
    var[0]=init_tree(0,n-1);
    while(m--){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&x);
            sz++;
            var[sz]=make_tree(0,n-1,var[sz-1],x);
        }
        if(a==2){
            scanf("%d %d %d",&l,&r,&x);
            ans=find_query1(0,n-1,var[l-1],var[r],x);
            printf("%d\n",ans);
        }
        if(a==3){
            scanf("%d",&x);
            sz-=x;
        }
        if(a==4){
            scanf("%d %d %d",&l,&r,&x);
            ans=find_query2(0,n-1,var[l-1],var[r],x);
            printf("%d\n",ans);
        }
        if(a==5){
            scanf("%d %d %d",&l,&r,&x);
            ans=find_query3(0,n-1,var[l-1],var[r],x);
            printf("%d\n",ans);
        }
    }
}