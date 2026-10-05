#include <bits/stdc++.h>
using namespace std;

bool VectorContains(vector<int> vec, int a){
    for(int &i : vec){
        if(i == a) return true;
    }
    return false;
}

int ilePunktowWKwadracie(vector<pair<int,int>> vect){
    int min  = 0, max = 5000;

    int ilePunktow = 0;

    for(pair p : vect){
        int x = p.first;
        int y = p.second;
        if(x > min && x < max && y > min && y < max) ilePunktow++;
    }

    return ilePunktow;
}

void ZnajdzTrojke(vector<pair<int,int>> vect){

    vector<int> wypisaneX;
    vector<int> wypisaneY;

    for(pair p : vect){

        for(pair pp : vect){

            for(pair ppp : vect){

                int x = p.first;
                int y = p.second;

                int xx = pp.first;
                int yy = pp.second;

                int xxx = ppp.first;
                int yyy = ppp.second;

<<<<<<< HEAD
                if(x != xx && x != xxx && y != yy && y != yyy){ //zeby nie bralo tego samego puntktu
                    if(abs(x - xx) == abs(xx - xxx) && abs(y - yy) == abs(yy -yyy)){ //rowna odleglosc

                        if(!VectorContains(wypisaneX, x) && !VectorContains(wypisaneY, y) && 
                        !VectorContains(wypisaneX, xx) && !VectorContains(wypisaneY, yy) &&
                        !VectorContains(wypisaneX, xxx) && !VectorContains(wypisaneY, yyy)
                        //Sprawdza czy juz wypisal dane 3 punkty (jest tylko jedna trojka z poleceniea)
=======
                if(x != xx && x != xxx && y != yy && y != yyy){
                    if(abs(x - xx) == abs(xx - xxx) &&
                        abs(y - yy) == abs(yy -yyy)
                    ){
                        if(!VectorContains(wypisaneX, x) && !VectorContains(wypisaneY, y) && 
                        !VectorContains(wypisaneX, xx) && !VectorContains(wypisaneY, yy) &&
                        !VectorContains(wypisaneX, xxx) && !VectorContains(wypisaneY, yyy)
>>>>>>> e89f9fe5389e9a8cf55d14880e8f5ed74c06f255
                        //JESTEM DOSLOWNIE TERRY DAVIS
                    ){
                            wypisaneX.push_back(x);
                            wypisaneY.push_back(y);
                            cout<<"("<<x<<" , "<<y<<")"<<" "<<"("<<xx<<" , "<<yy<<")"<<" "<<"("<<xxx<<" , "<<yyy<<")"<<endl;             
                        }
                    }
                }
            }
        }
    }
}

int main(){

    fstream plik("dron.txt");
    int x = 0, y = 0;
    int posX =0, posY = 0;

    int ilePar = 0;

    vector<pair<int,int>> punkty;

    while(plik>>x, plik>>y){
        int nwd = gcd(abs(x),abs(y));
        if(nwd > 1) ilePar++;

        posX += x;  
        posY += y;

        punkty.push_back(pair(posX,posY));

    }
    //Zadanie 3.1
    cout<<ilePar<<endl;
    cout<<ilePunktowWKwadracie(punkty)<<endl;
    ZnajdzTrojke(punkty);

}