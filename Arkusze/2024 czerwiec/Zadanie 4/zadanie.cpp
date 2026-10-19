#include <bits/stdc++.h>
using namespace std;

bool VectorContains(vector<int> vec, int n){
    for(int &i : vec){
        if(i == n) return true;
    }
    return false;
}

int znajdzNajIloscPakietow(int arr[1025]){
    arr[0] = 1;
    int maxElem = 0;

    for(int i = 1; i <= 1024; i++){
        if(arr[i] < 0) continue;
        if(arr[i] > 9999999) continue;
        if(arr[i] > maxElem) maxElem = arr[i];
    }

    return maxElem;
}


int main(){

    fstream plik("odbiorcy.txt");
    int odbiorca = 0;
    int nadawca = 1; // wiersz

    vector<int> odbiorcy;
    int nieOdbiorcy = 0;

    int rundaGdyWroci,pakietKtoryWrocil = 0;

    int kierunek[1025];
    int pakiet[1025];

    int n1 = 0;
    int n2 = 0;
    int n4 = 0;
    int n8 = 0;

    int iloscPakietow[1025];


    bool znalezionoPakiet = false;


    // nadawca || odbiorca


    while(plik >> odbiorca){
        odbiorcy.push_back(odbiorca);

        kierunek[nadawca] = odbiorca;

        nadawca++;
    }

     for(int i =  1; i<= 1024; i++){
        if(!VectorContains(odbiorcy, i)) nieOdbiorcy++;
        }
    cout<<nieOdbiorcy<<endl;

    for(int i = 1; i<= 1024; i++){
        pakiet[i] = i;
    }
    

    for(int r = 1; r < 1000; r++){
        int nowe_pakiety[1025];

        for(int i = 1; i<= 1024; i++){
            nowe_pakiety[i] = kierunek[pakiet[i]];
            
        }

        for(int i = 1; i<= 1024; i++){
            if(pakiet[i] != nowe_pakiety[i]) iloscPakietow[i]++;
            pakiet[i] = nowe_pakiety[i];
        }

        for(int i = 1; i<= 1024; i++){
            if(!znalezionoPakiet && pakiet[i] == i && r > 1){
                rundaGdyWroci = r;
                znalezionoPakiet = true;
                pakietKtoryWrocil = i;
                break;
            }
        }

        if(r == 1) n1 = znajdzNajIloscPakietow(iloscPakietow);
        if(r == 2) n2 = znajdzNajIloscPakietow(iloscPakietow);
        if(r == 4) n4 = znajdzNajIloscPakietow(iloscPakietow);
        if(r == 8) n8 = znajdzNajIloscPakietow(iloscPakietow);

       
    }
    


    cout<<rundaGdyWroci<<", ";
    cout<<pakietKtoryWrocil<<endl;
    cout<<n1<< " "<<n2<<" "<<n4<<" "<<n8<<endl;

   
}