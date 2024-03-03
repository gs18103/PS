#include <string>
#include <iostream>
using namespace std;

string s[3] = {"Vaporeon", "Jolteon", "Flareon"};
int main() {
    int n;
    cin >> n;
    cout << s[++n%3];
}