#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){

    int len = str.length() -1;

    for(int i= 0; i<= len; i++){
        if(str[i] != str[len - i]) return false;
    }

    return true;
}

int PrzeliczNaLiczbe(string str){
    string newstr;

    for(char &c: str){
        if(c == 'o') newstr.push_back('0');
        if(c == '+') newstr.push_back('1');
        if(c == '*') newstr.push_back('2');
    }

    if(newstr == "") return 0;

    return stoi(newstr, nullptr, 3);
}

string PrzeliczNaTrojkowy(int a){

    string newstr;

    while(a > 0){
        int c = a % 3;

        if(c == 0) newstr.push_back('o');
        if(c == 1) newstr.push_back('+');
        if(c == 2) newstr.push_back('*');

        a /= 3;
    }

    reverse(newstr.begin(), newstr.end());

    return newstr;
}

int main(){

    fstream plik("symbole.txt");
    string a,b,c;

    int palindromy = 0;

    int najwiekszaLiczba = 0;
    string najwiekszaString;

    int suma = 0;

    while(plik >> a){
            if(isPalindrome(a)){
                palindromy++;
                cout<<a + " jest palindromem "<<endl;
            } 

            int naj = PrzeliczNaLiczbe(a);
            suma += naj;
            if(naj > najwiekszaLiczba){
                najwiekszaLiczba = naj;
                najwiekszaString = a;
            }
    }

    //Zadanie 1
    cout<<palindromy<<endl;
    //Zadanie 3
    cout<<najwiekszaLiczba<<" "<<najwiekszaString<<endl;
    //Zadanie 4 
    cout<<suma<<" "<<PrzeliczNaTrojkowy(suma)<<endl;

}