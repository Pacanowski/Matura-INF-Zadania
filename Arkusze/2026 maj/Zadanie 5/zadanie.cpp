#include <bits/stdc++.h>

using namespace std;

int PrzeliczZSystemu(int x, int s)
{
    // x - liczba do przeksztalcenia, s - system liczbowy
    return stoi(to_string(x), nullptr, s);
}

int PrzeliczNaSystem(int x, int y)
{
    string str;
    // a
    while (x > 0)
    {
        str = char(x % y + '0') + str;
        x /= y;
    }
    return stoi(str);
}

int main()
{

    int a = PrzeliczZSystemu(1440, 5);
    int b = 427 - a; // 182

    int d = PrzeliczZSystemu(110002, 3);
    int c = d + 427;

    cout << PrzeliczNaSystem(b, 5) << endl;
    cout << PrzeliczNaSystem(c, 3);
}