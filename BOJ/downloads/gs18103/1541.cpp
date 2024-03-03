#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> num;
    vector <int> sign;
    string s;
    int cur = 0;
    cin >> s;
    sign.push_back(1);
    for(int i = 0; i < s. size(); i++)
    {
        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i] == '+')
                sign.push_back(1);
            if(s[i] == '-')
                sign.push_back(-1);
            num.push_back(cur);
            cur = 0;
        }
        else
        {
            cur = cur * 10 + s[i] - '0';
        }
    }
    num.push_back(cur);

    int ans = 0;
    bool m = false;
    for(int i = 0; i < num.size(); i++)
    {
        if(sign[i] == -1)
            m = true;
        if(m) ans -= num[i];
        else ans += num[i];
    }
    cout << ans << endl;
}
