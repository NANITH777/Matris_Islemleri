#include<iostream>
#include<iomanip>         //setw() kullanabilmek icin
#include<locale>         // Diller ve karakter setleri kütüphanesi
#include<Windows.h>      // yazı rengi için

using namespace std;

float matrisa[10][10], matrisb[10][10], matrisc[10][10], transpomatris[10][10];
float tersmatris[10][10];   // 10 sayisi maksimum olarak alinir
unsigned int satir, sutun;
int iz = 0;

void matrisToplama();
void matrisCikarma();
void matrisCarpma();
void matrisIzBulma();
void matrisTranspozesi();
void matrisTersi();

int main()
{
    std::cout << "Hello World!\n";
}