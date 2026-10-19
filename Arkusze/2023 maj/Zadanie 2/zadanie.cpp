#include <bits/stdc++.h>
using namespace std;

string ReverseString(string s){
    int len = s.length() - 1;
    string newstr;

    for(int i = 0; i <= len; i++){
        newstr.push_back(s[len - i]);
    }
    return newstr;
}

string zamienNaBinarny(int n){    
    string str;
    while(n > 0){
        int a = n % 2;
        n /= 2;
        str.push_back(char(a + '0'));
    }

    return ReverseString(str);


}

int zamienNaDziesietny(string str){
    int miejsce = 0;
    int len = str.length() - 1;
    int dzies = 0;

    for(char &c : str){
        dzies += (c - '0')* pow(2,len - miejsce);

        miejsce++;
    }

    return dzies;
}

int Bloki(int a){
    string str = zamienNaBinarny(a);

    int ile = 1; //1 bo pierwszy blok
    int len = str.length() - 1;

    for(int i = 0; i <= len - 1; i++){
            if(str[i] != str[i+1]) ile++;
    }

    return ile;

}

int BlokiBin(string str){
    int ile = 1; //1 bo pierwszy blok
    int len = str.length() - 1;

    for(int i = 0; i <= len - 1; i++){
            if(str[i] != str[i+1]) ile++;
    }

    return ile;

}

int DZ(string l, int s){
    if(s == 10) return stoi(l);
    int liczba = 0;

    int miejsce = 0;
    int len = l.length() -1 ;
    for(char &c : l){
        liczba += (c - '0') * pow(s, (len - miejsce));
        miejsce++;
    }

    return liczba;

}

map<char, int> LITERA;

void UzupelnijMape(){
    LITERA['A'] = 10;
    LITERA['B'] = 11;
    LITERA['C'] = 12;
    LITERA['D'] = 13;
    LITERA['E'] = 14;
    LITERA['F'] = 15;
}



int ZAMIENZLITERY(string l, int s){
    int liczba = 0;
    int len = l.length() - 1;

    for(char &c : l){
        int war = (c >= 'A') ? LITERA[c] : c  - '0';
        
        liczba = liczba * 16 + war;
    }

    return liczba;

}

string ZAMIEN(string l, int s,int t){
    if(s == t) return l;
    // l - liczba, s - jej system, t - system ktory chcemy
    int d = DZ(l,s);
    string liczba;

    while(d > 0){
        int x = d % t;
        d /= t;
        liczba.push_back(x + '0');
    }

    liczba = ReverseString(liczba);

    return liczba;


}

string XOR(string l1, int s1, string l2, int s2){
    // l1 liczba 1, s1 systme liczby 1

    //10011100
    //10110011
    //00101100

    l1 = ZAMIEN(l1, s1, 2);

    if (s2 == 16) {
        int a = ZAMIENZLITERY(l2, 16);
        l2 = zamienNaBinarny(a);
    } else {
        l2 = ZAMIEN(l2, s2, 2);
    }

    
    

    if(l1.length() != l2.length()){
        int temp = 0;
        string tempstr;
        int len1 = l1.length();
        int len2 = l2.length();
        string newl2;

        if(len1 != len2){

            if(len2 > len1){
                temp = len1;
                len1 = len2;
                len2 = temp;

                tempstr = l1;
                l1 = l2;
                l2 = tempstr;
            }

            //len1 > len2
            //2002 rok matura za tydzien

            int roznica = len1 - len2;

            for(int i = 0; i < roznica; i++){
                newl2.push_back('0');
            }

            for(char &c : l2){
                newl2.push_back(c);
            }
        }
        
        l2 = newl2;
    }

    //rowna dlugosc slow

    string wynik;
    for(int i = 0; i <= l1.length() -1;i++){
        char a = l1[i];
        char b = l2[i];

        if(a != b){
            wynik.push_back('1');
        }else{
            wynik.push_back('0');
        }
    }

    return wynik;
    
}


int main(){
    UzupelnijMape();

    fstream plik("bin.txt");
    string a;
    int bloki = 0;
    
    int mniejNizTrzy = 0;

    int najDzies = 0;
    int dzies = 0;
    string najDziesBin;

    while(plik>>a){
        bloki = BlokiBin(a);
        dzies = zamienNaDziesietny(a);

        if(bloki <= 2) mniejNizTrzy++;
        if(dzies > najDzies){
            najDzies = dzies;
            najDziesBin = a;
        } 
    }

    cout<<mniejNizTrzy<<endl;
    cout<<najDziesBin<<endl;

    string p = XOR("123", 10, "101101", 2);
    string q = XOR(p, 2, "2D", 16);

    cout<<DZ(q, 2);
}