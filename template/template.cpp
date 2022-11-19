#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"template.h"
using namespace std;
///********************************constructeur 1*******************************
template <class T>
Pile<T>::Pile(int n)
{
    this->nbelem=n;
    this->adr=NULL;
    this->adr = new T[this->nbelem];
     if(!adr)
    {
        cout << "probleme allocation!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        exit(-1);
    }
    else cout << "=>object created (pile)\n";
    this->sommet=0;
    cout<<"je suis le constructeur 1 \n";
}


///********************************constructeur 2*******************************
template <class T>
Pile<T>::Pile()
{
    this->nbelem=0;
    this->adr=NULL;
    this->adr = new T[this->nbelem];
    if(!adr)
    {
        cout << "probleme allocation!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        exit(-1);
    }
    else cout << "=>object created (pile)\n";
    this->sommet=0;
    cout<<"je suis le constructeur----- 2 \n";
}


///******************************Constructeur de recopie******************

template <class T>
Pile<T>::Pile(const Pile& p)
{
    adr = NULL;
    adr = new T[nbelem = p.nbelem];
    if(!adr)
    {
        cout << "probleme allocation";
        exit(-1);
    }
    else
    {
        for (sommet = 0; sommet < p.sommet; sommet++)
        {
            adr[sommet] = p.adr[sommet];
        }
        cout << "=>Je suis constructeur de recopie (pile)\n";
    }
}




///*********************************enpiler***********************************

template <class T>
int Pile<T>::push(T elem)
{
    if(this->PileSaturee())//pile sature
        return 0;
    this->adr[this->sommet]=elem;
    // cout<<this->adr[this->sommet]<<endl;
    this->sommet++;
    return 1;
}


///*********************************depiler************************************


template <class T>
double Pile<T>::pop()
{
    if(this->PileVide())
    {
        cout<<"pile vide !!\n";
        exit(0);
    }
    double x= this->adr[this->sommet];
    this->sommet--;
    return x;
}


///********************************Afficher*****************************


template <class T>
void Pile<T>::afficher()
{
    cout<<"Affichage de la pile :\n";
    if(this->sommet==0) cout<<"la pile est vide !!!\n";
    for(int i=0; i<this->sommet; i++)
        cout<<"elem num    "<<i<<"    =    "<<this->adr[i]<<endl;
}




///***************************************Est sature***************************



template <class T>
int Pile<T>::PileSaturee()
{
    if(this->sommet==this->nbelem) return 1;
    return 0;
}

///******************************************Est vide*****************************


template <class T>
int Pile<T>::PileVide()
{
    if(this->sommet==0) return 1;
    return 0;
}

///******************************************Destricteur**************************

template <class T>
Pile<T>::~Pile()
{
    delete [] adr;
    cout<<"je suis le destricteur\n";
}
///*********************************Operateur ==*********************************



template <class T>
bool Pile<T>::operator==(Pile & p)
{
    if(this->nbelem!=p.nbelem) return false;
    for(int i=0; i<this->nbelem; i++)
    {
        if(this->adr[i]!=p.adr[i]) return false;
    }
    return true;
}


///*******************************Operateur >*******************************


template <class T>
bool Pile<T>::operator>(Pile & p)
{
    if(this->nbelem<p.nbelem) return false;
    for(int i=0; i<this->nbelem; i++)
    {
        if(this->adr[i]<p.adr[i]) return false;
    }
    return true;
}


///******************************Operateur <****************************************


template <class T>
bool Pile<T>::operator<(Pile & p)
{
    if(this->nbelem>p.nbelem) return false;
    for(int i=0; i<this->nbelem; i++)
    {
        if(this->adr[i]>p.adr[i]) return false;
    }
    return true;
}


///**************************operateur +*************************

template <class T>
Pile<T> Pile<T>::operator+(Pile & p)
{
    if(this->nbelem!=p.nbelem) exit(0);
    Pile p3(this->nbelem);
    for(int i=0; i<this->nbelem; i++)
    {
        p3.push(this->adr[i]+p.adr[i]);
    }
    return p3;
}



///**************************operateur -*************************

template <class T>
Pile<T> Pile<T>::operator-(Pile & p)
{
    if(this->nbelem!=p.nbelem) exit(0);
    Pile p3(this->nbelem);
    for(int i=0; i<this->nbelem; i++)
    {
        p3.push(this->adr[i]-p.adr[i]);
    }
    return p3;
}

///**************************operateur =*************************

template <class T>
void Pile<T>::operator=(Pile & p)
{
    this->nbelem=p.nbelem;
    for(int i=0; i<p.sommet; i++)
    {

        this->push(p.adr[i]);
    }

}


///******************************Recuperer le sommet**********************************


template <class T>
int Pile<T>:: getSommet()
{
    return sommet;
}






///*********************vector***********************


///****************************constructeur 1 *******************
template <class T>
Vect<T>::Vect(int n,const T *elems)
{
    this->nbelem=n;
    adr = new T[nbelem];
    for(int i=0; i<nbelem; i++)
        this->adr[i]=elems[i];

    cout<<"Je suis le constructeur"<<endl;

}


///*************************constructeur 2**********************


template <class T>
Vect<T>::Vect()
{
    this->nbelem=1;
    adr = new T[nbelem];
    cout<<"Je suis le constructeur"<<endl;

}

///*********************************constructeur de recopie***********************************
template <class T>
Vect<T>::Vect(const Vect& v)
{
    this->nbelem=v.nbelem;
    this->adr=new T [100];
    for(int i=0; i<this->nbelem; i++)
        this->adr[i]=v.adr[i];

    cout<<"Constructeur de recopie bien fait "<<endl;
}


///*******************************Afficher les elements du vecteur***************************

template <class T>
void Vect<T>::afficher()
{
    for(int i=0; i<nbelem; i++)
        cout<<this->adr[i]<<endl;
}



///******************************Operateur == du vecteur***********************************


template <class T>
bool Vect<T>::operator==(const Vect&v)
{
    if(this->nbelem!=v.nbelem)
        return false;
    for(int i=0; i<nbelem; i++)
    {
        if(adr[i]!=v.adr[i])
            return false;
    }
    return true;
}


///******************************Operateur > du vecteur***********************************


template <class T>
bool Vect<T>::operator>(const Vect&v)
{
    if(this->nbelem<v.nbelem)
        return false;
    for(int i=0; i<nbelem; i++)
    {
        if(adr[i]<v.adr[i])
            return false;
    }
    return true;
}




///****************************L'operateur =************************

template <class T>
void Vect<T>::operator=( Vect const  &obj )
{
    this->nbelem=obj.nbelem;
    for(int i=0;i<obj.nbelem;i++)
        this->adr[i]=obj.adr[i];
}



///****************************L'operateur +************************

template <class T>
Vect<T> Vect<T>::operator+( Vect const  &obj )
{
    if(this->nbelem!=obj.nbelem) exit(0);
    T tab[this->nbelem];
    for(int i=0;i<obj.nbelem;i++)
        tab[i]=obj.adr[i]+this->adr[i];
         Vect<int> v3((this->nbelem),tab);
                return v3;

}



///****************************L'operateur -************************

template <class T>
Vect<T> Vect<T>::operator-( Vect const  &obj )
{
    if(this->nbelem!=obj.nbelem) exit(0);
    Vect v3();
    v3.nbelem=(this->nbelem+obj.nbelem);
    for(int i=0;i<obj.nbelem;i++)
        v3.adr[i]=this->adr[i]-obj.adr[i];
        return v3;
}




///******************************Destricteur**********************************************


template <class T>
Vect<T>::~Vect()
{
    delete [] adr;
    cout<<"je suis le destricteur\n";
};



///**************************Recuperer le nombre d elements*****************************


template <class T>
int Vect<T>::getNbelem()
{
    return (this->nbelem);
}



