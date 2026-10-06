    #include <bits/stdc++.h>
    using namespace std;

    vector<int> pierwszyWiersz;
    vector<int> drugiWiersz;
    vector<int> pierwszyKopia;

    void KopiujPierwszy(){
        pierwszyKopia = pierwszyWiersz;
    }

    bool jestDzielnikiemJakiejsLiczby(int n){
        for(int &i : drugiWiersz){
            if( i % n == 0) return true;
        }
        return false;
    }

    int main(){

        fstream plik("liczby.txt");

        

        int a = 0;
        int ileJestDzielnikiem = 0;

        int PodzielneLiczbyA = 0;

        vector<int> PodzielneLiczby;

        

        for(int i = 0; i < 3020; i++){
            plik>>a;
            if(i < 3000) pierwszyWiersz.push_back(a);
            if(i >= 3000) drugiWiersz.push_back(a);
        }

        for(int &p : pierwszyWiersz){
            if(jestDzielnikiemJakiejsLiczby(p)) ileJestDzielnikiem++;
        }

        cout<<ileJestDzielnikiem<<endl;

        sort(pierwszyWiersz.begin(), pierwszyWiersz.end(), greater<int>());

        int nr = 0;
        for(int &i : pierwszyWiersz){
            nr++;

            if(nr == 101) cout<<i<<endl;
        }

        
        int nrElementu = 0;
        int stareI = 0;
        int pierwszeI = 0;
        for( int &i : drugiWiersz){
            pierwszeI = i;
            
            pierwszyKopia = pierwszyWiersz;
            stareI = 0;

            while(i > 1){
                nrElementu = 0;
                stareI = i;
                for(int &p : pierwszyKopia){
                    nrElementu++;

                    if(p != 0 && i % p == 0){
                        
                        i /= p;
                        p = 0;
                        break;
                    }
                }

                if(i == stareI){
                    i = -1;
                }

            }

            if( i == 1){
                PodzielneLiczbyA++;
                PodzielneLiczby.push_back(pierwszeI);
            } 

        }

        for(int &i : PodzielneLiczby){
            cout<<i<<endl;
        }

        //cout<<PodzielneLiczbyA<<endl;

        

    }