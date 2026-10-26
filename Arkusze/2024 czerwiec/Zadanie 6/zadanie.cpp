#include <bits/stdc++.h>
using namespace std;

string Przelicz(string liczba, int sys, int nowySys){
    int dzies = 0;
    int len = liczba.length()-1;
    for(int i{}; i <= len; i++){
       char c = liczba[i];
        int n = (c - '0');
        dzies = dzies * sys + n;
    }
    if(nowySys == 10) return to_string(dzies);

    int reszta = 0;
    string nowy;

    while(dzies > 0){
        reszta = dzies % nowySys;
        nowy.push_back(char(reszta + '0'));
        dzies /= nowySys;
    }
    reverse(nowy.begin(), nowy.end());
    return nowy;
}
void Policz(string a, int sys, string b, int sys2, char dzialanie, int nowySys ){
    
    int aa = stoi(Przelicz(a, sys, 10));
    int bb = stoi(Przelicz(b, sys2, 10));

    string wynik;
    if(dzialanie == '+') wynik = Przelicz(to_string(aa + bb), 10, nowySys);
    if(dzialanie == '-') wynik = Przelicz(to_string(aa - bb), 10, nowySys);

    cout<<wynik<<endl;
}

int main(){
    Policz("203", 5, "4401", 5, '+', 5);
    Policz("4541", 6, "2455", 6, '-', 6);
}