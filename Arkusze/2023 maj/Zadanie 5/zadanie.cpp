#include<bits/stdc++.h>
using namespace std;

string Przelicz(string liczba, int system, int nowySystem){
    int len = liczba.length() -1;
    int dzies = 0;
    string nowa;

    for(int i{}; i <= len; i++){
        char c = liczba[i];
        int n = (c - '0');
        dzies = dzies * system + n;
    }
    if(nowySystem == 10) return to_string(dzies);

    int reszta = 0;
    
    while(dzies > 0){
        reszta = dzies % nowySystem;
        nowa.push_back(reszta);
        dzies /= nowySystem;
    }
    reverse(nowa.begin(), nowa.end());

    return nowa;
}

void Policz(string a, int sysA, string b, int sysB){
    char znak = '>';
    if( stoi(Przelicz(b, sysB, 10)) > stoi(Przelicz(a, sysA, 10))) znak = '<';

    cout<<a + "("<< sysA <<") "<<znak<<" "<< b + "("<<sysB<<")"<<endl;
}

int main(){
    Policz("134",5, "134", 6);
    Policz("2222", 3, "1111", 6);
}