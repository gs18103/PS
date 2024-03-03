#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

typedef pair <int, int> p;

char x[1000010];
bool chk[1000010];
char s[40];

int main()
{
    scanf("%s%s", x, s);
    int len1 = strlen(x);
    int len2 = strlen(s);

    stack <p> stk;

    if(len2 == 1)
    {
        int cnt = 0;
        for(int i = 0; i < len1; i++)
        {
            if(x[i] != s[0])
            {
                printf("%c", x[i]);
                cnt++;
            }
        }
        if(cnt == 0) printf("FRULA");
        return 0;
    }

    for(int i = 0; i < len1; i++)
    {
        if(x[i] == s[0])
            stk.push(p(i, 0));
        else if(!stk.empty())
        {
            if(x[i] == s[stk.top().second + 1])
            {
                stk.push(p(i, stk.top().second + 1));
                if(stk.top().second == len2 - 1)
                {
                    for(int j = 0; j < len2; j++)
                    {
                        chk[stk.top().first] = true;
                        stk.pop();
                    }
                }
            }
            else
                while(!stk.empty())
                    stk.pop();
        }
    }
    int cnt = 0;
    for(int i = 0; i < len1; i++)
    {
        if(!chk[i])
        {
            printf("%c", x[i]);
            cnt++;
        }
    }
    if(cnt == 0) printf("FRULA");
}
