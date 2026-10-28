#include <bits/stdc++.h>
using namespace std;

int kierunek[1025];
map<int, vector<int>> pakiety;
map<int, vector<int>> nowePakiety;

bool VectorContains(vector<int> vect, int n){
    for(int &i: vect){
        if(i == n) return true;
    }
    return false;
}

void PrzekazPakiety(int k){
    for(int &i : pakiety[k]){
        nowePakiety[kierunek[k]].push_back(i);
    }
}

void UpdatePakiety(){
    pakiety = nowePakiety;
    nowePakiety.clear();
}


int main(){

    fstream plik("odbiorcy.txt");
    

    for(int i = 0; i <= 1024; i ++){
        kierunek[i] = -1;
    }

    int odbiorca = 0,nadawca = 1;

    int nieOdbiorcy = 0;
    vector<int> WszyscyOdbiorcy;

    

    for(int i = 1; i <= 1024; i++){
        pakiety[i].push_back(i);
    }

    while(plik >> odbiorca){
        kierunek[nadawca] = odbiorca;
        WszyscyOdbiorcy.push_back(odbiorca);

        nadawca++;
    }

    for(int i =1; i <= 1024; i++){
        if(!VectorContains(WszyscyOdbiorcy, i)) nieOdbiorcy++;
    }

    cout<<nieOdbiorcy<<endl;


    int najmniejszaRunda = 0;
    int pkw =0; //pakiet ktory wrocil
    bool znaleziono = false;

    int ilosc = 0;
    map<int,int> najIlosc;

    for(int r = 1; r <= 1024; r++){

        for(int i = 1; i <= 1024; i++){
            PrzekazPakiety(i);
        }
        UpdatePakiety();

        for(int i = 1; i <= 1024; i++){
            ilosc = pakiety[i].size();
            if(ilosc > najIlosc[r]) najIlosc[r] = ilosc;
        }

        for(int i = 1; i <= 1024; i++){

            for(int &p : pakiety[i]){
                if(p == i && !znaleziono && r > 1){ 
                    najmniejszaRunda = r;
                    pkw = p;
                    znaleziono = true;
                }
            }
        }
    }
    cout<<najmniejszaRunda<<" "<<pkw<<endl;

    cout<<najIlosc[1]<<" "<<najIlosc[2]<<" "<<najIlosc[4]<<" "<<najIlosc[8]<<endl;

}