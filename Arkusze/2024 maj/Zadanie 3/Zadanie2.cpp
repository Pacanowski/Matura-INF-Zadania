#include <bits/stdc++.h>
using namespace std;

int WyznaczNPSkrot(string str){
    string newstr;

    for(char &c: str){
        if((c - '0') % 2 != 0) newstr.push_back(c);
    }

    return stoi(newstr);
}

int main(){

    fstream plik("skrot2.txt");
    int n = 0, skrot = 0;

    vector<int> szukaneLiczby;

    while(plik >> n){
        skrot = WyznaczNPSkrot(to_string(n));

        if(gcd(n, skrot) == 7) szukaneLiczby.push_back(n);
    }

    for(int &i : szukaneLiczby){
        cout<<i<<endl;
    }

}