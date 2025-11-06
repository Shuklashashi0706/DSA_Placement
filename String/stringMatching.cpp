#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s = "onionionson";
    string a = "onions";
    int p1 = 0, p2 = 0;
    while (p2 < a.size() && p1 < s.size())
    {
        if (s[p1] == a[p2])
        {
            p2++;
        }
        else
        {
            if (p2 != 0)
            {
                p2 = 0;
            }
        }
        p1++;
    }
    cout << p1 << " " << p2 << endl;
    cout << (p1 - (a.size())) << endl;
    return 0;
}