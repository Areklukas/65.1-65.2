#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 1000;
float tab[SIZE][2];

void zadanie1() 
{
	cout<<"Zadanie 65.1:"<<endl;
	double minLicznik=999999999, minMianownik=999999999, minUlamek=999999999;
	double ulamek;
  	for (int i = 0; i < SIZE; i++) 
  	{
    	ulamek = tab[i][0] / tab[i][1];
    	if (ulamek <= minUlamek) 
		{
      		if (ulamek == minUlamek && tab[i][1] > minMianownik) continue;
      		minUlamek = ulamek;
      		minLicznik = tab[i][0];
      		minMianownik = tab[i][1];
    	}
	}
  cout<<"Licznik: "<< minLicznik<<" Mianownik: "<<minMianownik<<endl;
}

int liczba(int x, int y) 
{
  	if (x < y) return liczba(y, x);
 	if (y == 0) return x;
  	return liczba(y, x % y);
}

void zadanie2() 
{
  	cout<<endl<<"Zadanie 65.2: "<<endl;
  	int licz=0;
  	for (int i=0; i<SIZE; i++) 
	{
    	if (liczba(tab[i][0], tab[i][1])>1) continue;
    	licz++; 
  	}
  	cout<<licz<<endl<<endl;
}

int main() {
  	ifstream in("dane_ulamki.txt");
  	for (int i=0; i<SIZE; i++) 
  	{
    	in>>tab[i][0]>>tab[i][1];
  	}
  	in.close();
  	zadanie1();
  	zadanie2();
}
