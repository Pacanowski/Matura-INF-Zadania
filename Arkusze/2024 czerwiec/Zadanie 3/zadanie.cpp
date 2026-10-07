#include <bits/stdc++.h>
using namespace std;

bool czyMaFragment(string str){
    int len = str.length() -1 ;

    if(len < 3) return false;

    for(int i = 0; i <=len - 2; i++){
        if(str[i] == 'k' && str[i + 2] == 't') return true;
    }

    return false;
}

string Zakoduj(string str){
    string newstr;

    for(char &c: str){
        int newchar = c + 13;
        if(newchar >= 123){
            newchar -= 26;
        } 
        newstr.push_back(char( newchar ) );
    }
    return newstr;
}

string ReverseString(string str){
    string newstr;
    int len = str.length()-1;

    for(int i = 0; i <= len; i++){
        newstr.push_back(str[len - i]);
    }
    return newstr;
}

bool CzyLiteraWystpWPolowie(string str){
    map<char, int> wystapienia;
    int pol = ceil((str.length() -1)/2) ;

    for(char &c: str){
        wystapienia[c]++;
    }

    for(auto &c : wystapienia){
        if(c.second >    pol) return true;
    }

    return false;


}

int main(){

    fstream plik("slowa.txt");
    string a;

    int slowaZFragmentem = 0;

    string zakodowana;
    string reversed;
    int szukaneSlowa = 0;
    string najdluzsze;

    vector<string> slowaZLiteraWPolowie;

    while(plik >> a){
        if(czyMaFragment(a)) slowaZFragmentem++;

        
        zakodowana = Zakoduj(a);

        reversed = ReverseString(a);
        //cout<< a + " " + reversed + " " + zakodowana<<endl;
        if(reversed == zakodowana){
            szukaneSlowa++;
            if(a.length() > najdluzsze.length()) najdluzsze = a;
        } 

        if(CzyLiteraWystpWPolowie(a)) slowaZLiteraWPolowie.push_back(a);
    }

    cout<<slowaZFragmentem<<endl;
    cout<<szukaneSlowa<<endl;
    cout<<najdluzsze<<endl;
    //cout<<Zakoduj("aren");

    for(string &s : slowaZLiteraWPolowie){
        cout<<s<<endl;
    }

}