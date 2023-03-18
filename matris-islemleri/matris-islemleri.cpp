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
	setlocale(LC_ALL, "Turkish");    // Turk karakterleri icin
	system("color 5F");
	srand(time(0));                  // Rastegele bir matris olusturmak icin 
	char final;
	int secenek;


	do
	{
		/////// M E N U //////

		cout << "\n\n\t\t\tMERHABA, HOSGELDINIZ\n\n";
		cout << "\n\t\t******************************************************" << endl;

		cout << "\n\n\t\t\t---Ne yapmak istiyorsunuz ?--- \n\n" << endl;
		cout << "\t\t\t1) MATRIS TOPLAMA" << endl;
		cout << "\t\t\t2) MATRIS CIKARMA" << endl;
		cout << "\t\t\t3) MATRIS CARPMA " << endl;
		cout << "\t\t\t4) MATRIS IZI BULMA  " << endl;
		cout << "\t\t\t5) MATRIS TRANSPOZESI ALMA  " << endl;
		cout << "\t\t\t6) MATRIS TERSI ALMA " << endl;
		cout << "\t\t\t7) Cikmak icin " << endl;

		cout << "\n\t\t******************************************************" << endl;

		cout << "\n\t\t\t Secim numarasini girin:  ";
		cin >> secenek;


		if (secenek != '1' && secenek != '2' && secenek != '3' && secenek != '4' && secenek != '5' && secenek != '6')
		{
			cout << "\a"; // Kullanci, yanlis tusa bastigindan ses cikma
			system("cls"); // Onceki girdikleri silmek
		}


		if (secenek == 1)
		{
			cout << "\n\t\t\t MATRIS TOPLAMA\n\n ";
			matrisToplama();

		}

		if (secenek == 2)
		{
			cout << "\n\t\t\t MATRIS CIKARMA\n\n ";
			matrisCikarma();
		}

		if (secenek == 3)
		{
			cout << "\n\t\t\t MATRIS CARPMA\n\n ";
			matrisCarpma();
		}

		if (secenek == 4)
		{
			cout << "\n\t\t\t MATRIS IZI BULMA\n\n ";
			matrisIzBulma();
		}

		if (secenek == 5)
		{
			cout << "\n\t\t\t MATRIS TRANSPOZESI BULMA\n\n ";
			matrisTranspozesi();
		}

		if (secenek == 6)
		{
			cout << "\n\t\t\t MATRIS TERSI BULMA\n\n ";
			matrisTersi();
		}

		if (secenek == 7)
		{
			cout << "\n\n\t\t\t cikis yaptiniz" << endl;
			exit(0); // Sistemden cikmak
		}


		cout << "\n\nBaska islem yapmak ister misiniz ? (E/H)\n";
		cin >> final;
		system("cls");

	} while (final == 'e' || final == 'E');


	cout << "HOSCAKALIN\n";

	return 0;
}