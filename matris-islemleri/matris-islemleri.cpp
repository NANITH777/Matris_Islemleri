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

void matrisToplama()
{

	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> satir;
	cout << " \t\t\t sutun sayisini girin[0-10]:  "; cin >> sutun;

	int secim;

	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}

		cout << endl;

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				matrisb[i][j] = rand() % 11;
			}
		}
		cout << endl;

	}

	if (secim == 2)
	{
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl << endl;

		cout << "     A matrisi:\n\n";
		for (int i = 0; i < satir; i++)
		{

			for (int j = 0; j < sutun; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				do
				{
					cout << setw(8) << "MatrisB[" << i << "]" << "[" << j << "]:";
					cin >> matrisb[i][j];
				} while (matrisb[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl;

	}
	

	cout << "     B matrisi: \n\n";
	for (int i = 0; i < satir; i++)
	{
		for (int j = 0; j < sutun; j++)
		{
			cout << setw(8) << matrisb[i][j];
		}
		cout << "\n";
	}


	cout << "\n      sonuc matrisi( MATRIS C);\n\n";
	for (int i = 0; i < satir; i++)
	{
		for (int j = 0; j < sutun; j++)
		{
			matrisc[i][j] = matrisa[i][j] + matrisb[i][j];
			cout << setw(8) << matrisc[i][j];
		}
		cout << endl;
	}
}

void matrisCikarma()
{
	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> satir;
	cout << " \t\t\t sutun sayisini girin[0-10]:  "; cin >> sutun;

	int secim;

	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}

		cout << endl << endl;

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				matrisb[i][j] = rand() % 11;
			}
		}
		cout << endl;
	}

	if (secim == 2)
	{
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl << endl;

		cout << "     A matrisi:\n\n";
		for (int i = 0; i < satir; i++)
		{

			for (int j = 0; j < sutun; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				do
				{
					cout << setw(8) << "MatrisB[" << i << "]" << "[" << j << "]:";
					cin >> matrisb[i][j];
				} while (matrisb[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
	}

	cout << endl;

	cout << "      B matrisi: \n\n";
	for (int i = 0; i < satir; i++)
	{
		for (int j = 0; j < sutun; j++)
		{
			cout << setw(8) << matrisb[i][j];
		}
		cout << "\n";
	}
	cout << endl;

	cout << "      sonuc matrisi( MATRIS C);\n\n";
	for (int i = 0; i < satir; i++)
	{
		for (int j = 0; j < sutun; j++)
		{
			matrisc[i][j] = matrisa[i][j] - matrisb[i][j];
			cout << setw(8) << matrisc[i][j];
		}
		cout << endl;
	}
}


void matrisCarpma()
{
	unsigned int m;

	cout << " \t\t\t Bir kare matrisi girin\n ";
	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> m;

	int secim;

	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}

	if (secim == 2)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl << endl;

		cout << "      A matrisi:\n\n";
		for (int i = 0; i < m; i++)
		{

			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << endl;
		}
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrisb[i][j] = rand() % 11;
		}
	}
	cout << endl;

	cout << "     B matrisi: \n\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(8) << matrisb[i][j];
		}
		cout << "\n";
	}
	cout << endl;

	cout << "\n        sonuc matrisi;\n\n";
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < m; j++)
		{
			matrisc[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				matrisc[i][j] += matrisa[i][k] * matrisb[k][j];
			}
		}

	}
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < m; j++)
		{
			cout << setw(8) << matrisc[i][j];
		}
		cout << endl;
	}
}


void matrisIzBulma()
{
	unsigned int n;
	cout << " \t\t\t Bir kare matrisi girin\n ";
	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> n;


	int secim;
	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}

	if (secim == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl;
		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				iz += matrisa[i][i];
		}
		cout << endl;
	}

	cout << setw(8) << "Matris izi: " << iz;
}

void matrisTranspozesi()
{
	unsigned int m;
	cout << " \t\t\t Bir kare matrisi girin\n ";
	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> m;

	int secim;

	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}

	if (secim == 2)
	{

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}


	cout << " \n\n\     Matris Transpozesi:\n\n";
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < m; j++)
		{
			transpomatris[i][j] = matrisa[j][i];
			cout << setw(8) << transpomatris[i][j];
		}
		cout << endl;
	}
}


void matrisTersi()
{
	unsigned int m;

	cout << " \t\t\t Bir kare matrisi girin\n ";
	cout << " \t\t\t satir sayisini[0-10] girin:  "; cin >> m;

	int secim;

	cout << " \n\t\tRastegele mi yoksa kendi matris olusturmak mi istiyorsun\n\n";
	cout << " \t\t 1) Rastegele\n ";
	cout << " \t\t 2) Bir matris olusturun\n";
	cin >> secim;

	if (secim == 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrisa[i][j] = rand() % 11;
			}
		}
		cout << endl;

		cout << setw(5) << "A matrisi: \n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << "\n";
		}
	}

	if (secim == 2)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				do
				{
					cout << setw(8) << "MatrisA[" << i << "]" << "[" << j << "]:";
					cin >> matrisa[i][j];
				} while (matrisa[i][j] > 10);      //  Matrisin elemanlari [0-10] araliginda olmasi lazim

			}
		}

		cout << "\n\n    A matrisi:\n\n";
		for (int i = 0; i < m; i++)
		{

			for (int j = 0; j < m; j++)
			{
				cout << setw(8) << matrisa[i][j];
			}
			cout << endl;
		}
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
				tersmatris[i][j] = 1;
			else
				tersmatris[i][j] = 0;
		}
	}

	float d, k;
	for (int i = 0; i < m; i++)
	{
		d = matrisa[i][i];
		for (int j = 0; j < m; j++)
		{
			matrisa[i][j] = matrisa[i][j] / d;
			tersmatris[i][j] = tersmatris[i][j] / d;
		}
		for (int x = 0; x < m; x++)
		{
			if (x != i)
			{
				k = matrisa[x][i];
				for (int j = 0; j < m; j++)
				{
					matrisa[x][j] = matrisa[x][j] - (matrisa[i][j] * k);
					tersmatris[x][j] = tersmatris[x][j] - (tersmatris[i][j] * k);
				}
			}
		}
	}

	cout << " \n\n        Matrisin tersi: \n\n ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(10) << tersmatris[i][j];
		}
		cout << endl;
	}
}

////////////////******* copyright NANITH 2022-2023 *********/////////////////////////