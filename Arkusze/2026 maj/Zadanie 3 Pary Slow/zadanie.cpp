#include <bits/stdc++.h>
using namespace std;

int Suma(string a)
{
    int s = 0;

    for (char &c : a)
    {
        s += c;
    }

    return s;
}

int maxElementVector(vector<int> vect)
{
    int maks = 0;

    for (int &i : vect)
    {
        if (i > maks)
            maks = i;
    }

    return maks;
}

int SumaWystapien(char x, string a, string b)
{
    int nA = 0;
    int nB = 0;

    for (char &c : a)
    {
        if (c == x)
            nA++;
    }
    for (char &c : b)
    {
        if (c == x)
            nB++;
    }

    return min(nA, nB);
}

bool Contains(vector<char> vec, char c)
{

    for (char &x : vec)
    {
        if (x == c)
            return true;
    }

    return false;
}

int PrefiksSufiks(string a, string b)
{
    int n = min(a.length(), b.length());

    for (int len = n; len >= 1; len--)
    {
        if (a.substr(0, len) == b.substr(b.length() - len))
        {
            return len;
        }
    }
    return 0;
}

int ZnajdzDPS(string a, string b)
{
    return max(PrefiksSufiks(a, b), PrefiksSufiks(b, a));
}

int SumaWystWszLiter(string a, string b)
{

    int n = 0;
    vector<char> sprawdzone;

    for (char &c : a)
    {
        if (!Contains(sprawdzone, c))
        {
            n += SumaWystapien(c, a, b);
            sprawdzone.push_back(c);
        }
    }
    // jeden for starcza bo zeby byla suma to litera musi byc w obu stringach

    return n;
}

int main()
{

    fstream plik("pary.txt");
    string a, b;
    int najSuma = 0;
    string najA, najB;

    int najSumaWyst = 0;
    string najSWA, najSWB;

    while (plik >> a, plik >> b)
    {

        int sum = abs(Suma(a) - Suma(b));
        if (sum > najSuma)
        {
            najSuma = sum;
            najA = a;
            najB = b;
        }

        int ss = SumaWystWszLiter(a, b);
        if (ss > najSumaWyst)
        {
            najSumaWyst = ss;
            najSWA = a;
            najSWB = b;
        }

        int ps = ZnajdzDPS(a, b);
        if (ps >= 5)
        {
            cout << a + " " + b + " " << ps << endl;
        }
    }

    // Zadanie  3.1
    cout << "=========" << endl;
    cout << najA + " " + najB + " " << najSuma << endl;
    cout << najSWA + " " + najSWB + " " << najSumaWyst << endl;
}