#include <bits/stdc++.h>  
  
using namespace std;  
  
char x[1010101];  
  
int main() {  
    int n;  
    scanf("%d %s", &n, x);  
    int lb = 0, ub = 1000000;  
    while(lb < ub) {  
        int m = (lb + ub + 1) / 2;  
        int I = 0, cnt = 0, IO = 0, chk = 0;  
        bool flag = false;  
        for(int i = n - 1; i >= 0; i--) {  
            if(!flag && x[i] == 'I') I++, chk++;  
            else if(x[i] == 'I' && IO > 0) IO--, cnt++;  
            if(x[i] == 'J' && IO > 0) IO--, cnt++;  
            if(x[i] == 'O' && I > 0) I--, IO++;  
            if(chk == m) flag = true;  
        }  
        if(cnt >= m) lb = m;  
        else ub = m - 1;  
    }  
    printf("%d", lb);  
}  