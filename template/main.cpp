
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"template.cpp"
using namespace std;

int main()
{
    cout<<"******************Pile 1***************\n";
    Pile<int> p1(5);
    for(int i=1; i<=5; i++)
        p1.push(i);
    cout<<p1;
    cout<<"******************Pile 2***************\n";
    Pile<int> p2(5);
    for(int i=9; i<=14; i++)
        p2.push(i);
    cout<<p2;

    cout<<"******************Pile 3***************\n";
    Pile<int> p3=p1+p2;

    cout<<p3<<endl;



    ///*************************Vectors**********************
    int T[3]={0,1,2};
    Vect<int> v1(3,T);
    cout<<"***************Vector 1****************\n";
    cout<<v1;
    Vect<int> v2=v1;
    cout<<"***************Vector 2****************\n";
    cout<<v2;
     Vect<int> v3=v1+v2;
    cout<<"***************Vector 3****************\n";
    cout<<v3;


    ///**************************Stack of vector*********************
    Pile<Vect<int>> pile1(3);
    pile1.push(v1);
    cout<<"*************Affichage du  pile apres la premiere enpilation\n ";
    cout<<pile1;
    pile1.push(v2);
    cout<<"*************Affichage du  pile apres la deuxieme enpilation\n ";
    cout<<pile1;


  ///**************************Stack of stack*********************
  cout<<"$$$$$$$$$$$$$Pile de piles$$$$$$$$$$$$$$$$$$\n";
  Pile<Pile<int>> pp1(3);
  pp1.push(p1);
  pp1.push(p2);
  cout<<"Affichage de pp1\n";
  cout<<pp1;
cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    return 0;
}
