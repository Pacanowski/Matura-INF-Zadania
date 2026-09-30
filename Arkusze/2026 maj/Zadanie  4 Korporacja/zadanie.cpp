#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> pracownicy;
map<int, int> przelozony;

int PoliczPrzelozonych(int a)
{
    // a - pracownik ktorego przelozonych szukamy
    int p = 0; //  koncowa liczba przelozonych

    while (true)
    {
        if (przelozony[a] == 0)
        {
            return p;
        }

        a = przelozony[a];
        p++;
    }
    // fallback
    return 0;
}

int main()
{
    fstream plik("korpo.txt");
    int pracownik = 0, pracodawca = 0;

    int PracownicyBezPodwladnych = 0;
    int Naj = 0, Prac = 0;
    int NajPrzelozonych = 0, IleMaNaj = 0;

    przelozony[1] = 0;

    while (plik >> pracodawca)
    {
        pracownik++;
        przelozony[pracownik] = pracodawca;

        pracownicy[pracodawca].push_back(pracownik);
    }

    for (int i = 1; i <= 50000; i++)
    {
        int p = pracownicy[i].size(); // liczba bezposrednich podwladnych

        if (p == 0)
        {
            PracownicyBezPodwladnych++;
        }

        if (p > Naj)
        {
            Naj = p;
            Prac = i;
        }

        int prz = PoliczPrzelozonych(i);
        if (prz > NajPrzelozonych)
            NajPrzelozonych = prz;
    }

    for (int i = 1; i <= 50000; i++)
    {
        int prz = PoliczPrzelozonych(i);
        if (prz == NajPrzelozonych)
        {
            IleMaNaj++;
        }
    }

    // Zadanie 4.2
    cout << PracownicyBezPodwladnych << " pracownikow nie jest przelozonym zadnego pracownika" << endl;

    // Zadanie  4.3
    cout << Prac << " " << Naj << endl;

    // Zadanie  4.4
    cout << IleMaNaj << " " << NajPrzelozonych << endl;
}