#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(char a, char b){return a > b;}

int main()
{
    string s;
    cin >> s;
    int sum = 0, len = s.size();
    for(int i = 0; i < len; i++)
        sum += s[i] - '0';
    if(sum % 3 != 0)
    {
        cout << -1;
    }
    else
    {
        bool flag = false;
        for(int i = 0; i < len; i++)
            if(s[i] == '0') flag = true;
        if(flag == false)
        {
            cout << -1;
        }
        else
        {
            sort(s.begin(), s.end(), cmp);
            cout << s;
        }
    }
}
