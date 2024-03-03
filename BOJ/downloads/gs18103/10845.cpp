#include <stdio.h>
#include <string.h>

int arr[10000];

int top = -1, bottom = 0, num = 0;

void push(int data)
{
    arr[top+1] = data;
    top = (top+1) % 10000;
    num++;
}

int pop()
{
    if(num == 0) return -1;
    int data = arr[bottom];
    arr[bottom] = 0;
    num--;
    bottom++;
    return data;
}

int front()
{
    if(num == 0) return -1;
    return arr[bottom];
}

int back()
{
    if(num == 0) return -1;
    return arr[top];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char x[10];
        scanf("%s", &x);
        if(!strcmp(x, "push"))
        {
            int data;
            scanf("%d", &data);
            push(data);
        }
        if(!strcmp(x, "pop"))
        {
            int data;
            printf("%d\n", pop());
        }
        if(!strcmp(x, "size"))
        {
            printf("%d\n", num);
        }
        if(!strcmp(x, "empty"))
        {
            if(num == 0) printf("1\n");
            else printf("0\n");
        }
        if(!strcmp(x, "front"))
        {
            printf("%d\n", front());
        }
        if(!strcmp(x, "back"))
        {
            printf("%d\n", back());
        }
    }
}
