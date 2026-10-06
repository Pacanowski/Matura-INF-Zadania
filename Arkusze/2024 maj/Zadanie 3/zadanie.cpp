#include <bits/stdc++.h>
using namespace std;

string WyznaczNPSkrot(string str){
    string newstr;

    for(char &c: str){
        if((c - '0') % 2 != 0) newstr.push_back(c);
    }

    return newstr;
}

bool maSkrot(string str){
    return WyznaczNPSkrot(str).size() != 0;
}


int main(){

    fstream plik("skrot.txt");
    int n = 0;

    string a;
    int najBezSkrotu = 0;


    vector<string> bezSkrotu;

    while(plik >> n){
        a = to_string(n);

        if(!maSkrot(a)){
            bezSkrotu.push_back(a);
            if(n > najBezSkrotu) najBezSkrotu = n;
        } 

    }

    cout<<bezSkrotu.size()<<endl<<najBezSkrotu<<endl;

    

}