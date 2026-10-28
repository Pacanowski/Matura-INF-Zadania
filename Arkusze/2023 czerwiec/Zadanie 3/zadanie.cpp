    #include <bits/stdc++.h>
    using namespace std;

    int silnia(int n){
        int s = 1;
        for(int i = n; i > 1; i--){
            s *= i;
        }

        return s;
    }

    bool VectorContains(vector<char> vec, char c){
        for(auto &h : vec){
            if (h == c) return true;
        }
        return false;
    }

    string Zamien(string l, int sys1, int nowySys){
        int dzies = 0;

        for(char &c: l){
            int n = c - '0';
            dzies = dzies * sys1 + n;

        }
        if(nowySys == 10) return to_string(dzies);

        string nowa;
        int reszta = 0;
        while(dzies > 0){
            reszta = dzies % nowySys;
            nowa.push_back( char(reszta + '0'));
            dzies /= nowySys;
        }

        reverse(nowa.begin(), nowa.end());

        return nowa;


    }



    int main(){
        fstream plik("anagram.txt");
        string a;

        int zera = 0;
        int jedynki = 0;

        int z = 0, pz = 0;
        int naj  = 0;
        int ilenaj = 0; //z - zrownowaznoe pz - prawie zroznowazone
        vector<string> jakieNaj;

        string wszystkie[1001];
        int miejsce = 0;

        while(plik >> a){ 
            wszystkie[miejsce] = a;
            miejsce++;
            zera = 0; jedynki = 0;

            for(char &c : a){
                if(c == '1') jedynki++;
                if(c == '0') zera++;
            }

            if(zera == jedynki) z++;
            if(abs(zera - jedynki) == 1) pz++;

            int najAnagram = 0;
            if(a.length() - 1 == 7){
                string newstr;
                int x, y;

                x = zera; y = jedynki;
                if(jedynki > zera) swap(x,y);
                //ustawienie zeby x > y

                int m = silnia(8)/( silnia(x) * silnia(8 - x)); // mozliwosc ustawien
                int n = silnia(7)/ (silnia(x) * silnia(8 - x));

                int k = m - n;

                if(k > naj){
                    naj = k;
                } 
                if(k == naj){
                    ilenaj++;
                    jakieNaj.push_back(a);
                }





            }

        }

        cout<<z<<endl;
        cout<<pz<<endl;

        for(auto &s: jakieNaj){
            cout<<s<<endl;
        }

        int najRoz = 0;

        string wynik;
        string najWynik;
        for(int i = 0; i + 1< 1001; i++){
            string aa = wszystkie[i];
            string bb = wszystkie[i+1];

            string aaa = Zamien(aa, 2, 10);
            string bbb = Zamien(bb, 2,10);

            int l1 = stoi(aaa);
            int l2 = stoi(bbb);
            
            int w = abs(l1 - l2);

            wynik = Zamien(to_string(w),10,2);

            if(w > najRoz){
                najRoz = w;
                najWynik = wynik;
            }


        }
        cout<<"   "<<endl;
        cout<<najWynik<<endl;

        string dziesietne[1001];
        int majaZero = 0;
        int bezZera = 0;

        int najSuma = 0;
        bool znaleziono = false;
        int najLiczba = 0;

        for(int i = 0; i + 1< 1001; i++){
            string dz = Zamien(wszystkie[i], 2, 10);
            dziesietne[i] = dz;
            vector<char> chars;

            for(char &c : dz){
                if(c == '0'){
                    majaZero++;
                    break;
                }

                if(!VectorContains(chars, c)) chars.push_back(c);
            }
            

            int suma = 0;
            for(char &ch : chars){
                suma += ch - '0';
            }

            if(suma > najSuma) najSuma = suma;
                
        
        }
        for(int i = 0; i + 1< 1001; i++){
            string dz = Zamien(wszystkie[i], 2, 10);
            dziesietne[i] = dz;
            vector<char> chars;

            for(char &c : dz){
                if(!VectorContains(chars, c)) chars.push_back(c);
            }
            int suma = 0;
            for(char &ch : chars){
                suma += ch - '0';
            }

            if(suma == najSuma && !znaleziono){
                znaleziono = true;
                najLiczba = stoi(dz);
            }
                
        
        }

        bezZera = 1000 - majaZero;
        cout<<bezZera<<endl;
        cout<<najLiczba<<endl;




    }