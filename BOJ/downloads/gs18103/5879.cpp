#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

int arr[22];
int chk[1200000];
set <int> s;
vector <p> v1;
vector <p> v2;

int abs(int k){return k > 0 ? k : - k;}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int ans = 0;
    int cnt = 0;

    int maxi = 1;
    for(int i = n / 2; i < n; i++)
        maxi *= 3;

    for(int i = 1; i < (1 << (n / 2)); i++)
    {
        int d = 0, t = i, x = 0, tcnt = 0;
        int tarr[11];
        while(t > 0)
        {
            if(t & 1) tarr[x++] = arr[d];
            t = t / 2;
            d++;
        }
        s.clear();
        for(int j = 0; j < (1 << (x - 1)); j++)
        {
            int sum1 = 0, sum2 = 0;
            int tt = j;
            for(int k = 0; k < x; k++, tt /= 2)
            {
                if(tt % 2 == 0) sum1 += tarr[k];
                else sum2 += tarr[k];
            }
            if(sum1 == sum2) tcnt = 1;
            if(s.find(abs(sum1 - sum2)) == s.end())
                s.insert(abs(sum1-sum2));
        }
        set<int>::iterator it;
        for(it = s.begin(); it != s.end(); it++)
            v1.push_back(p(*it, i));
        cnt += tcnt;
    }
    for(int i = 1; i < (1 << (n - n / 2)); i++)
    {
        int d = n/2, t = i, x = 0, tcnt = 0;
        int tarr[11];
        while(t > 0)
        {
            if(t & 1) tarr[x++] = arr[d];
            t = t / 2;
            d++;
        }
        s.clear();
        for(int j = 0; j < (1 << (x - 1)); j++)
        {
            int sum1 = 0, sum2 = 0;
            int tt = j;
            for(int k = 0; k < x; k++, tt /= 2)
            {
                if(tt % 2 == 0) sum1 += tarr[k];
                else sum2 += tarr[k];
            }
            if(sum1 == sum2) tcnt = 1;
            if(s.find(sum1 - sum2) == s.end())
                s.insert(abs(sum1-sum2));
        }
        set<int>::iterator it;
        for(it = s.begin(); it != s.end(); it++)
            v2.push_back(p(*it, i));
        cnt += tcnt;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int d1 = 0, d2 = 0, dd = 0;
    while(d1 < v1.size() && d2 < v2.size())
    {
        if(v1[d1].first > v2[d2].first) d2++;
        else if(v1[d1].first < v2[d2].first) d1++;
        else
        {
            int c1 = 1, c2 = 1;
            while(d1 + c1 < v1.size() && v1[d1+c1].first == v1[d1].first) c1++;
            while(d2 + c2 < v2.size() && v2[d2+c2].first == v2[d2].first) c2++;
            for(int i = d1; i < d1 + c1; i++)
            {
                for(int j = d2; j < d2 + c2; j++)
                {
                    if(chk[v1[i].second + (v2[j].second << (n/2))] == 1) continue;
                    ans++;
                    chk[v1[i].second + (v2[j].second << (n/2))] = 1;
                }
            }
            d1 += c1, d2 += c2;
        }
    }

    printf("%d", ans + cnt);
}
