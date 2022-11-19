#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

///************************************************PILE**************************************************///

template <class T>
class Pile
{
private:
    int nbelem;//nombre d element
    T* adr;//pointeurs sur les elemnts de la pile
    int sommet;//sommet de la pile
public:
    Pile();//constructeur
    Pile(int );//constructeur
    Pile(const Pile&);
    ~Pile();//destricteur
    int push(T );//enpiler
    double pop();//depiler
    void afficher();//afficher
    int PileSaturee();//tester la saturation
    int PileVide();
    bool operator==(Pile & p);//surcharge de l'opperateur ==
    bool operator>(Pile & p);//surcharge de l'opperateur >
    bool operator<(Pile & p);//surcharge de l'opperateur <
    Pile operator+(Pile & p);//surcharge de l'opperateur +
    Pile operator-(Pile & p);//surcharge de l'opperateur -
    void operator=(Pile & p);//surcharge de l'opperateur =


    int getSommet();
    int getNbelem()
    {
        return nbelem;
    }
    friend ostream& operator<<(ostream& o,const Pile<T>& p)
    {
        for(int i=0; i<p.sommet; i++)
            o<<p.adr[i];
        cout<<endl;
        return o;
    }
};







///**********************************VECTOR 2eme version*************************************///





template <class T>
class Vect
{
private :
    int nbelem;//nombre elements
    T * adr;//pointeurs sur des elements
public :
    Vect(int,const T *);//constructeur
    Vect();//constructeur 2
    ~Vect();//destricteur
    Vect(const Vect&);//constructeur de recopie
    void afficher();//afficher le vecteur
    int getNbelem();//recuperer le nombre d'element
    Vect  operator+( Vect const  &obj );//l'operateur + des vecteurs
    Vect  operator-( Vect const  &obj );//l'operateur - des vecteurs
    void  operator=( Vect const  &obj );//l'operateur = des vecteurs
    bool operator==(const Vect&);//operateur == des vecteurs
    bool operator>(const Vect&);//operateur > des vecteurs
    friend ostream& operator<<(ostream& o,const Vect& v)
    {
        for(int i=0; i<v.nbelem; i++)
            o<<v.adr[i]<<"\t";
            cout<<endl;
        return o;
    }
};





#endif // TEMPLATE_H_INCLUDED
