#include <bits/stdc++.h>
using namespace std;

bool JestCyfra(char c){
    return c >= '0' && c <= '9';
}

bool VectorContains(vector<char> vec, char a){
    for(char &c : vec){
        if(c == a) return true;
    }
    return false;
}

int IleRoznychCyfr(string str){
    vector<char> litery;

    for(char &c : str){
        if(!VectorContains(litery, c)) litery.push_back(c);
    }

    return litery.size();
}

int main(){

    fstream plik("dane.txt");
    string str;
    plik>>str;

    int liczbyOd50 = 0;

    map<int, int> wystapienia;
    int najWystp = 0;
    int ileWystp = 0;

    vector<string> numery;
    int najmniejRoznychCyfr = 9999;

    for(int i = 1; i<str.length() -2 ; i++){
        if(str[i] == '5' && str[i + 1] == '0' && !JestCyfra(str[i-1])) liczbyOd50++;

        char c = str[i];

        if(JestCyfra(c)){
            int x = c - '0';
            wystapienia[x]++;
        }
    }
    string numer;
    string numerDoVectora;
    for(int i = 0; i<str.length() - 1 - 9  ; i++){
        char c = str[i];
        numer = "";
        numerDoVectora = "";
        
        //Sprawdzanie czy numer zaczyna sie od 5 istnieje
        if(c == '5' 
            && !JestCyfra(str[i-1])
            && JestCyfra(str[i+1])
            && JestCyfra(str[i+2]) && JestCyfra(str[i+3]) && JestCyfra(str[i+4])
            && JestCyfra(str[i+5]) && JestCyfra(str[i+6]) && JestCyfra(str[i+7])
            && JestCyfra(str[i+8]) && !JestCyfra(str[i+9])
        ){
            //moze kiedys dodam for loop
            numer.push_back(str[i]);
            numer.push_back(str[i + 1]);
            numer.push_back(str[i + 2]);
            numer.push_back(str[i + 3]);
            numer.push_back(str[i + 4]);
            numer.push_back(str[i + 5]);
            numer.push_back(str[i + 6]);
            numer.push_back(str[i + 7]);
            numer.push_back(str[i + 8]);
        }

        if(numer != ""){
            //wypisuje numery bo zadanie tak chce
            cout<<numer<<endl;
        }

        //Wszystkie numery dodaje do vectora
        if(JestCyfra(str[i])
            && !JestCyfra(str[i-1])
            && JestCyfra(str[i+1])
            && JestCyfra(str[i+2]) && JestCyfra(str[i+3]) && JestCyfra(str[i+4])
            && JestCyfra(str[i+5]) && JestCyfra(str[i+6]) && JestCyfra(str[i+7])
            && JestCyfra(str[i+8]) && !JestCyfra(str[i+9])
        ){
            //moze kiedys dodam for loop
            numerDoVectora.push_back(str[i]);
            numerDoVectora.push_back(str[i + 1]);
            numerDoVectora.push_back(str[i + 2]);
            numerDoVectora.push_back(str[i + 3]);
            numerDoVectora.push_back(str[i + 4]);
            numerDoVectora.push_back(str[i + 5]);
            numerDoVectora.push_back(str[i + 6]);
            numerDoVectora.push_back(str[i + 7]);
            numerDoVectora.push_back(str[i + 8]);
        }

         if(numerDoVectora != ""){
            numery.push_back(numerDoVectora);
        }
    }

    cout<<liczbyOd50<<endl;

    for(int i = 0; i < wystapienia.size(); i++){
        if(wystapienia[i] > ileWystp){
            ileWystp = wystapienia[i];
            najWystp = i;
        } 
    }
    cout<<najWystp<<" "<<ileWystp<<endl;

    for(string num : numery){
        int cyfry = IleRoznychCyfr(num);
        if(cyfry < najmniejRoznychCyfr) najmniejRoznychCyfr = cyfry;
    }

    for(string num : numery){
        int cyfry = IleRoznychCyfr(num);
        if(cyfry == najmniejRoznychCyfr) cout<<najmniejRoznychCyfr<<" "<<num<<endl;
    }

}