#include <iostream>
#include <vector>
#include <set>
#include "mini.h"
#include "GT.h"
#include "tip_familie.h"
#include "monovolum.h"
#include "indisponibil.h"
#include "frauda.h"
#include "contrabanda.h"

using namespace std;

template <class T>
class Vanzare
{
    static int cumparatori;

//    int nr_stoc,nr_vandute;
    set<pair<T*,int>> stoc,vandute;
public:
    Vanzare(set<pair<T*,int>> = set<pair<T*,int>>());
    Vanzare(const Vanzare &);
    virtual ~Vanzare();
    Vanzare& operator= (const Vanzare &);

    set<pair<T*,int>> Selectie();
    Vanzare& operator -=(pair<T*,int>);
    Vanzare& operator +=(pair<T*,int>);
};

template <class T>
int Vanzare<T>::cumparatori = 0;

template <class T>
Vanzare<T>::Vanzare(set<pair<T*,int>> masini):stoc(masini)
{++cumparatori;}

template <class T>
Vanzare<T>::Vanzare(const Vanzare<T>& x)
{throw frauda();}

template <class T>
Vanzare<T>::~Vanzare()
{
    for (auto x : stoc)
        delete (x.first);
    for (auto x : vandute)
        delete (x.first);
    --cumparatori;
}

template <class T>
Vanzare<T>& Vanzare<T>::operator= (const Vanzare<T>& x)
{throw frauda();return *this;}

template <class T>
set<pair<T*,int>> Vanzare<T>::Selectie()
{
    return stoc;
}

template <class T>
Vanzare<T>& Vanzare<T>::operator -=(pair<T*,int> x)
{
    if(stoc.find(x)!=stoc.end())
    {
        stoc.erase(x);
        vandute.insert(x);
        return *this;
    }
    else
        throw indisponibil();
}

template <class T>
Vanzare<T>& Vanzare<T>::operator +=(pair<T*,int> x)
{
    stoc.insert(x);
}



template <>
class Vanzare<monovolum>
{
    static int cumparatori;

//    int nr_stoc,nr_vandute;
    set<pair<monovolum*,bool>> vandute;
    std::string cand;
public:
    set<pair<monovolum*,bool>>stoc;
    Vanzare(set<pair<monovolum*,bool>> = set<pair<monovolum*,bool>>(), std::string = "2000 01 01");
    Vanzare(const Vanzare<monovolum>& );
    virtual ~Vanzare();
    Vanzare& operator= (const Vanzare &);

    set<pair<monovolum*,bool>> Selectie();
    Vanzare& operator -=(pair<monovolum*,bool>);
    Vanzare& operator +=(pair<monovolum*,bool>);
    int GivePret(pair<monovolum*,bool>) const;

};

int Vanzare<monovolum>::cumparatori = 0;

Vanzare<monovolum>::Vanzare(set<pair<monovolum*,bool>> masini, std::string data):stoc(masini), cand(data)
{++cumparatori;}

Vanzare<monovolum>::Vanzare(const Vanzare<monovolum>& x)
{throw frauda();}

Vanzare<monovolum>::~Vanzare()
{
    for (auto x : stoc)
        delete (x.first);
    for (auto x : vandute)
        delete (x.first);
    --cumparatori;
}

Vanzare<monovolum>& Vanzare<monovolum>::operator= (const Vanzare<monovolum>& x){
throw frauda();
return *this;}

set<pair<monovolum*,bool>> Vanzare<monovolum>::Selectie()
{
    return stoc;
}

Vanzare<monovolum>& Vanzare<monovolum>::operator -=(pair<monovolum*,bool> x)
{
    if(stoc.find(x)!=stoc.end())
    {
        stoc.erase(x);
        vandute.insert(x);
        return *this;
    }
    else
        throw indisponibil();
}

Vanzare<monovolum>& Vanzare<monovolum>::operator +=(pair<monovolum*,bool> x)
{
    stoc.insert(x);
    return *this;
}

int Vanzare<monovolum>::GivePret(pair<monovolum*,bool> x) const
{
    int an = stoi(x.first->DataFabricarii());
    int an2= stoi(cand);
    bool vara = stoi(cand.substr(5)) > 5  && stoi(cand.substr(5)) < 9;
    return vara ? (50000/(an2-an+1) - 5000/(an2-an+1)) : 50000/(an2-an+1);
}

void afiseaza_meniu(){
  std::cout << "Ce vrei sa faci?\n";
  std::cout << "1. Sa vand o masina.\n";
  std::cout << "2. Sa vad ce selectie de masini e pe stoc\n";
  std::cout << "3. Sa aflu cat ar costa masina mea de vis.\n";
  std::cout << "4. Exit\n";

}

int main()
{/*
    Vanzare<monovolum> a(set<pair<monovolum*,bool>>(),"2000 07 03");
    a+={0,1};
    a-={0,1};
    monovolum *b = new monovolum();
    cout<<*b;
    a+={b,1};
    cout<<a.GivePret({b,1});
    a-={0,0};
  ///frauda
    Vanzare<monovolum> a(set<pair<monovolum*,bool>>(),"2000 07 03");
    Vanzare<monovolum> b;
    b=a;
    */
    int nr=0;
    Vanzare<monovolum> a(set<pair<monovolum*,bool>>(),"2000 07 03");
    do{
        afiseaza_meniu();
        int op;
        double y,z;
        std::string x,w;
    std::cin >> op;
    if(op==1){
cout<<"Ce masina vrei sa vinzi?\n1.hatchback\n2.combi\n3.sedan\n";
cin>>x;
cout<<"Ce lungime are?\n";
cin>>y;
cout<<"Ce volum are?\n";
cin>>z;
cout<<"Care este data fabricarii?\n";
cin>>w;
monovolum M(y,z,w);
automobil::GiveTip(x);
monovolum *N=new monovolum();
*N=M;
a+={N,1};
nr++;
//cout<<M<<"\n";
//cout<<*N<<"\n";
cout<<"\nTi-am dat "<<a.GivePret({N,1})<<" lei pe ea\n";
    cout<<"Vanzare efectuata cu succes!\n";
    a+={N,1};
    }
    else if (op==2){
  for (pair<monovolum*,bool> i:a.Selectie())
        cout <<*(i.first);
    }
    else if (op==3){
cout<<"De care?\n1.hatchback\n2.combi\n3.sedan\n";
cin>>x;
cout<<"Ce lungime sa aiba?\n";
cin>>y;
cout<<"Ce volum sa aiba?\n";
cin>>z;
cout<<"Care sa fie data fabricarii?\n";
cin>>w;
monovolum M(y,z,w);
automobil::GiveTip(x);
monovolum *N=new monovolum();
*N=M;
cout<<M<<"\n";
//cout<<*N<<"\n";
cout<<"\nTe-ar costa "<<a.GivePret({N,1})<<" lei\n";
    }
    else if(op==4) break;
    else {cout<<"Nu am inteles ce vrei sa faci, incearca din nou\n";}
    } while(true);
    return 0;
}
