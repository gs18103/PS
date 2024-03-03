#include <stdio.h>
#include <string.h>

char A[10101], B[10101];
int ans[10101];

int main() {
    scanf("%s %s", A, B);
    int iA = strlen(A) - 1, iB = strlen(B) - 1;
    int len = iA > iB ? iA : iB;
    int idx = 0;
    while(iA >= 0 && iB >= 0) {
        ans[idx] += (A[iA] - '0') + (B[iB] - '0');
        ans[idx+1] += ans[idx] / 10;
        ans[idx] %= 10;
        idx++, iA--, iB--;
    }
    while(iA >= 0) {
        ans[idx] += A[iA] - '0';
        ans[idx+1] += ans[idx] / 10;
        ans[idx] %= 10;
        idx++, iA--;
    }
    while(iB >= 0) {
        ans[idx] += B[iB] - '0';
        ans[idx+1] += ans[idx] / 10;
        ans[idx] %= 10;
        idx++, iB--;
    }
    if(ans[len+1] != 0) printf("%d", ans[len+1]);
    for(int i = len; i >= 0; i--) {
        printf("%d", ans[i]);
    }
}