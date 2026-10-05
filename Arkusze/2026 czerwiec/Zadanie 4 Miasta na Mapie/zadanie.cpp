#include <bits/stdc++.h>
using namespace std;

int main()
{

    fstream plik("mapa.txt");
    int nr = 0, x = 0, y = 0, m = 0;

    int najM = 0;
    int najMnr = 0;

    int xs[1001];
    int ys[1001];

    int ms[1001];

    map<int, int> MiastaWypisane;
    int najmD = 9999999;

    int sumaLudnosci = 0;
    float gestosc = 0.0f;
    int najdluzszyBok = 0;
    int liczbaMieszkancowAglo = 0;

    while (plik >> x, plik >> y, plik >> m)
    {
        nr++;

        xs[nr] = x;
        ys[nr] = y;
        ms[nr] = m;

        if (m > najM)
        {
            najM = m;
            najMnr = nr;
        }
    }

    for (int k = 1; k <= 1000; k++)
    {
        for (int l = 1; l <= 1000; l++)
        {
            if (k == l)
            {
                continue;
            }

            int xx = abs(xs[k] - xs[l]);
            int yy = abs(ys[k] - ys[l]);

            int d = xx + yy;

            if (d < najmD)
            {
                najmD = d;
            }
        }
    }

    for (int k = 1; k <= 1000; k++)
    {
        for (int l = 1; l <= 1000; l++)
        {
            if (k == l)
            {
                continue;
            }

            // najmD
            int xx = abs(xs[k] - xs[l]);
            int yy = abs(ys[k] - ys[l]);

            int d = xx + yy;

            if (d == najmD)
            {
                if (MiastaWypisane[l] != k && MiastaWypisane[k] != l)
                {
                    MiastaWypisane[l] = k;
                    MiastaWypisane[k] = l;
                    cout << najmD << " miedzy miastami: " << k << " " << l << endl;
                }
            }
        }

        // Zadanie 4.3
    }

    for (int i = 1; i < 250; i++)
    {
        sumaLudnosci = 0;
        gestosc = 0;

        for (int k = 1; k <= 1000; k++)
        {

            if (xs[k] > 0 && xs[k] < i && ys[k] > 0 && ys[k] < i)
            {
                sumaLudnosci += ms[k];

                gestosc = (float)sumaLudnosci / (float)(i * i);

                if (gestosc > 2.0f)
                {
                    if (i > najdluzszyBok)
                    {
                        najdluzszyBok = i;
                        liczbaMieszkancowAglo = sumaLudnosci;
                    }
                }
            }
        }
    }

    cout << najMnr << " " << najM << endl;
    cout << najdluzszyBok << " " << liczbaMieszkancowAglo << endl;
}