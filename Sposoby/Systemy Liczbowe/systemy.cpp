#include <bits/stdc++.h>
using namespace std;


string Przelicz(string liczba, int system, int nowySystem){
    if(system == nowySystem) return liczba;
    int dzies = 0;

    if(system == 10){
        dzies = stoi(liczba);
    }else{

        for(char &c: liczba){
            int n = (c - '0');
            dzies = dzies * system + n;
        }
    }
    if(nowySystem == 10) return to_string(dzies);
   
    string nowa; 
    int reszta = 0;

    while(dzies > 0){
        reszta = dzies % nowySystem;    
        nowa.push_back(char(reszta + '0'));
        dzies /= nowySystem;
    }
    reverse(nowa.begin(), nowa.end());
    return nowa;


}

int main(){

    cout<<Przelicz("20", 10, 2)<<endl;  


}