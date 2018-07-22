// Klasa Datum i funkcija DodajBrojDana.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Datum {
	int *_dan;
	int *_mjesec;
	int *_godina;

public:
	Datum(int d, int m, int g);
	~Datum();
	int GetDan();
	int GetMjesec();
	int GetGodina();
	void SetDan(int d);
	void SetMjesec(int m);
	void SetGodina(int g);
	void DodajDan(int dana);
	bool Prestupna();
	void Ispis();
};

Datum::Datum(int d = 1, int m = 1, int g = 2000)
{
	_dan = new int(d);
	_mjesec = new int(m);
	_godina = new int(g);
}
Datum::~Datum()
{
	delete _dan; _dan = nullptr;
	delete _mjesec; _mjesec = nullptr;
	delete _godina; _godina = nullptr;
}
int Datum::GetDan()
{
	return *_dan;
}
int Datum::GetMjesec()
{
	return *_mjesec;
}
int Datum::GetGodina()
{
	return *_godina;
}
void Datum::Ispis()
{
	cout << *_dan << "." << *_mjesec << "." << *_godina << endl;
}
void Datum::SetDan(int d)
{
	*_dan = d;
}
void Datum::SetMjesec(int m)
{
	*_mjesec = m;
}
void Datum::SetGodina(int g)
{
	*_godina = g;
}
bool Datum::Prestupna()
{
	if (*_godina % 4 == 0)
	{
		if ((*_godina % 100 != 0) || (*_godina % 400 == 0))
		{
			return true;
		}
	}
	return false;
}
void Datum::DodajDan(int Brojdana)
{
	int brojDanaUMjesecu[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31 };
	int temp = Brojdana;

	while (temp > 0)
	{
		//Provjera da li je godina prestupna
		if (Prestupna())
		{
			brojDanaUMjesecu[1] = 28;
		}
		else
		{
			brojDanaUMjesecu[1] = 29;
		}

		// Dodavanje dana
		if (brojDanaUMjesecu[*_mjesec - 1] < (*_dan + 1))
		{
			if ((*_mjesec + 1) > 12)
			{
				(*_mjesec) = 1;
				(*_godina)++;
			}
			else
			{
				(*_dan) = 1;
				(*_mjesec)++;
			}
		}
		else
		{
			(*_dan)++;
		}

		temp--;
	}
}



int main()
{
	Datum mojDatum;
	mojDatum.Ispis();

	mojDatum.SetDan(27);
	mojDatum.SetMjesec(2);
	mojDatum.SetGodina(2000);
	mojDatum.Ispis();

	cout << "Godina " << mojDatum.GetGodina();
	if (mojDatum.Prestupna())
	{
		cout << " je prestupna.\n";
	}
	else
	{
		cout << " nije prestupna.\n";
	}

	mojDatum.DodajDan(3);
	mojDatum.Ispis();


	system("pause>0");
	return 0;
}



