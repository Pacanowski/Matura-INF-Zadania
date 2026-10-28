#include <bits/stdc++.h>
using namespace std;

string Przelicz(int l1, int sys1, int nowySys){
    string l = to_string(l1);
    int dzies = 0;

    for(char &c : l){
        int n = c - '0';
        dzies = dzies * sys1 + n;
    }

    if(nowySys == 10) return to_string(dzies);

    int reszta = 0;
    string nowa;
    while(dzies > 0){
        reszta = dzies % nowySys;
        nowa.push_back(reszta + '0' );
        dzies /= nowySys;
    }

    reverse(nowa.begin(), nowa.end());
    return nowa;
}

int main(){
    cout<<Przelicz(101201,3,9)<<endl;
    cout<<Przelicz(2487,9,3)<<endl; 
}