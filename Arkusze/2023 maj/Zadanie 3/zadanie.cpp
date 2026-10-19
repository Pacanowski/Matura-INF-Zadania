#include <bits/stdc++.h>
using namespace std;

//ostatni podpunkt nie dziala jeszcze

pair<string,int> MaxOfMap(map<string,int> mapa){
    int maxElem = 0;
    string fragment;
    
    for(auto &p : mapa){
        int val = p.second;
        if (val> maxElem){
            maxElem = val;
            fragment = p.first;
        } 
    }

    return pair(fragment, maxElem);
} 

pair<string,int> MinOfMap(map<string,int> mapa){
    int minElem = 9999;
    string fragment;
    
    for(auto &p : mapa){
        int val = p.second;
        if (val < minElem){
            minElem = val;
            fragment = p.first;
        } 
    }

    return pair(fragment, minElem);
}

bool CzyJestCiagiemSzesc(int vect[9999], int s){
    if(s + 5 >= 9999) return false;

    int n1 = vect[s];
    int n2 = vect[s + 1];
    int n3 = vect[s + 2];
    int n4 = vect[s + 3];
    int n5 = vect[s + 4];
    int n6 = vect[s + 5];

    if( (n4 > n3 && n3 > n2 && n2 > n1) && n5 > n6) return true;
    if( (n3 > n2 && n2 > n1) && n4 > n5 && n5 > n6) return true;
    if( (n2 > n1) && n3 > n4 && n4 > n5 && n5 > n6) return true;

    return false;

}

int main(){

    fstream plik("pi.txt");
    string calosc = "";
    
    string frag;
    char l;

    map<string, int> wystapienia;

    pair<string, int> max;
    pair<string,int> min;

    int wieksze  = 0;

    int liczby[9999];
    int miejsce = 0;
    int ileCiagow = 0;

    while(plik >> l){
        calosc.push_back(l);
        liczby[miejsce] = l - 48;
        miejsce++;
    }

    for(int i =0; i <= 9999; i++){
        frag = "";

        frag.push_back(calosc[i]);
        frag.push_back(calosc[i + 1]);

        if(stoi(frag) > 90) wieksze++;

        wystapienia[frag]++;

        if(CzyJestCiagiemSzesc(liczby, i)) ileCiagow++;
        
        
    }

    int zmiana = 0;
        int dR = 1;
        int dM = 1;
        int dlugosc = 0;

        int maksDlugosc = 0;
        int maksStart = 0;

    for(int i = 0; i< 10000; i++){
            dR = 0;
            dM = 0;
            zmiana = i;

            for(int j = i; j + 1< 10000 && liczby[j] < liczby[j + 1]; j++){
                dR++;
                zmiana = j + 1;
            }

            for(int j = zmiana; j + 1<10000 && liczby[j] > liczby[j + 1]; j++ ){
                dM++;
            }

            if(dM != 1 && dR != 1){
                dlugosc = dM + dR;
            }

            if(dlugosc > maksDlugosc){
                maksStart = i;
                maksDlugosc = dlugosc;
            }


        }

        cout<<maksStart<<endl;
        
        for(int i = maksStart; i <= maksStart + maksDlugosc; i++){
            cout<<liczby[i];
        }
        cout<<endl;

    cout<<wieksze<<endl;

    max = MaxOfMap(wystapienia);
    min = MinOfMap(wystapienia);

    string maxFrag = max.first;
    int maxCount = max.second;

    string minFrag = min.first;
    int minCount = min.second;

    cout<<"Najmniej: "<<minFrag<<" "<<minCount<<endl;
    cout<<"Najwiecej: "<<maxFrag<<" "<<maxCount<<endl;

    cout<<ileCiagow<<endl;

}