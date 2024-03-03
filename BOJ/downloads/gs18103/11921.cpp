#include <stdio.h>

#define BS 524288

int cnt,rc;
char inb[BS];

inline char gchar(void){if(cnt%BS==0) cnt=0,rc=fread(inb,1,BS,stdin);return cnt<rc?inb[cnt++]:0;}
inline int _readInt(int *ptr){
	int n=0,c=0;
	*ptr=0;
	while(1){
		char read=gchar();
		if(read>='0'&&read<='9') read-='0',n*=10,n+=read;
		else{*ptr=n;return n==0?0:!c;}
		c++;
	}
	*ptr=n;
	return 0;
}
inline int readInt(void){int ptr;while(_readInt(&ptr));return ptr;}
int main(void){
	int N,T,r;
	long long sum=0;
	T=readInt();N=T;
	while(T--) r=readInt(),sum+=r;
	printf("%d\n%lld\n",N,sum);
	return 0;
}