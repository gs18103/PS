#include <bits/stdc++.h>

using namespace std;

int sz = 0, arr[101010];

void Up(int node) {
    if(node == 1) return;
    if(arr[node/2] < arr[node]) {
        swap(arr[node/2], arr[node]);
        Up(node/2);
    }
}

void Push(int x) {
    sz++;
    arr[sz] = x;
    Up(sz);
}

void Down(int node) {
    int idx = node, mx = arr[node];
    if(node * 2 <= sz && arr[node*2] > mx) {
        mx = arr[node*2];
        idx = node * 2;
    }
    if(node * 2 + 1 <= sz && arr[node*2+1] > mx) {
        mx = arr[node*2+1];
        idx = node * 2 + 1;
    }
    if(idx == node) return;
    swap(arr[node], arr[idx]);
    Down(idx);
}

void Pop() {
    if(sz == 0) return;
    swap(arr[sz], arr[1]);
    sz--;
    if(sz > 0) Down(1);
}

int Top() {
    if(sz == 0) return 0;
    return arr[1];
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int x;
        scanf("%d", &x);
        if(x == 0) {
            printf("%d\n", Top());
            Pop();
        }
        else Push(x);
    }
}