#include <bits/stdc++.h>
using namespace std;

int main(){

    fstream plik("symbole.txt");
    string a,b,c;

    int wiersz = 2;
    string symbole[2000];

    for(int i{}; i < 2000; i++){
        plik>>symbole[i];
    }

    for(int i = 1; i < 1998; i++){
        if(symbole[i].size() == 0) continue;

        a = symbole[i-1];
        b = symbole[i];
        c = symbole[i + 1];

        for(int ii = 1; ii <= 10; ii++){
            //srodek to b[i]
            char ch = b[ii];
            if(
                a[ii-1] == ch && a[ii] == ch && a[ii+1] == ch &&
                b[ii-1] == ch && b[ii] == ch && b[ii+1] == ch &&
                c[ii-1] == ch && c[ii] == ch && c[ii+1] == ch
            ){
                cout<<"Kwadrat na "<<wiersz<<" "<<ii+1<<endl;
            }
        }
        wiersz++;
    }
}