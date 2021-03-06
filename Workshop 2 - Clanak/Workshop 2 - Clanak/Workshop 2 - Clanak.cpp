// Workshop 2 - Clanak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>

using namespace std;

const char * crt = "\n-------------------------------------------------------------\n";


class Vrijeme {
	int _sati;
	int _minute;
	int _sekunde;
public:

	//Konstruktor bez parametara
	Vrijeme()
	{
		_sati = 0;
		_minute = 0;
		_sekunde = 0;
	}
	//Konstruktor sa 3 parametra (sati, minute i sekunde)
	Vrijeme(int sati, int minute, int sekunde)
	{
		_sati = sati;
		_minute = minute;
		_sekunde = sekunde;
	}
	Vrijeme(Vrijeme &v)
	{
		_sati = v._sati;
		_minute = v._minute;
		_sekunde = v._sekunde;
	}

	//Konstruktor sa 2 parametra (sati i minute)
	Vrijeme(int sati, int minute)
	{
		_sati = sati;
		_minute = minute;
		_sekunde = 0;
	}

	//Funkciju Info sa neobaveznim parametrom tipa bool koji određuje da li će vrijeme biti ispisano u punom formatu
	//(hh:mm:ss) ili u skraćenom formatu (hh:mm). Default-no funkcija vrši ispis u punom formatu.
	void Info(bool puniFormat = true)
	{
		if (puniFormat)
		{
			cout << _sati << "." << _minute << "." << _sekunde;
		}
		else
		{
			cout << _sati << "." << _minute;
		}
	}

	//Funkciju Add koja kao rezultat vraća novi objekat tipa vrijeme koji predstavlja 
	//sumu vremena poslijeđenog kao parametar i instance this.
	Vrijeme Add(Vrijeme vrijeme)
	{
		int sek1 = _sekunde + (_minute * 60) + (_sati * 3600);
		int sek2 = vrijeme._sekunde + (vrijeme._minute * 60) + (vrijeme._sati * 3600);
		int suma = sek1 + sek2;

		Vrijeme povratni;
		povratni._sati = suma / 3600;
		suma = suma % 3600;

		povratni._minute = suma / 60;
		suma = suma % 60;

		povratni._sekunde = suma;

		return povratni;
	}

	//Funkciju Add koja kao rezultat vraća novi objekat tipa vrijeme koji predstavlja 
	//sumu parametra izraženog u minutama i vremena instance this.
	Vrijeme Add(int Minute)
	{
		int suma = _sekunde + _minute * 60 + _sati * 3600 + Minute * 60;
		Vrijeme povratni;
		povratni._sati = suma / 3600;
		suma = suma % 3600;

		povratni._minute = suma / 60;
		suma = suma % 60;

		povratni._sekunde = suma;

		return povratni;

	}

	//Funkciju CompareTo koja vraća vrijednost tipa int u zavisnosti od toga da li je vrijeme instance this prije, jednako ili poslije
	//vremena proslijeđenog kao parametar.
	//Moguće povratne vrijednosti:
	//-1 - vrijeme instance this nastupa prije vremena v2
	// 0 - vrijeme instance this je jednako vremenu v2
	// 1 - vrijeme instance this nastupa nakon vremena v2

	int CompareTo(Vrijeme v)
	{
		int sekundeThis;
		int sekundeParametar;

		sekundeThis = _sati * 3600 + _minute * 60 + _sekunde;
		sekundeParametar = v._sati * 3600 + v._minute * 60 + v._sekunde;

		if (sekundeThis < sekundeParametar)
			return -1;
		if (sekundeThis == sekundeParametar)
			return 0;
		if (sekundeThis > sekundeParametar)
			return 1;
	}
};


/*
Potrebno je kreirati aplikaciju za dijeljenje znanja putem razmjene članaka među korisnicima.

Izdvojene su sljedeće funkcionalnosti:
- Administrator sistema je zadužen za upravljanje korisničkim nalozima (Ime, Prezime, Email, DatumRegistracije, KorisnickoIme, Lozinka).
- Svaki članak (Naslov, Sadrzaj, Datum, Satnica, BrojPregleda) može sadržavati više tagova, ali pripada samo jednoj oblasti.
- Članke mogu dodavati svi registrovani korisnici.
- Korisnici aplikacije također mogu ostaviti komentar (Tekst, Datum, Popularnost) na određeni članak.
*/

/*
Na osnovu datih klasa implementirati opisane funkcionalnosti sistema. Po potrebi dopuniti klase novim atributima i/ili funkcijama.
*/

class Datum
{
	int _dan;
	int _mjesec;
	int _godina;
public:
	//Potrebne konstruktor i destruktor funkcije
	Datum(int d = 1, int m = 1, int g = 2000)
	{
		_dan = d;
		_mjesec = m;
		_godina = g;
	}
	Datum(Datum &d)
	{
		_dan = d._dan;
		_mjesec = d._mjesec;
		_godina = d._godina;
	}
	~Datum()
	{
		//
	}

	//Funkciju Info
	void Info()
	{
		cout << _dan << "." << _mjesec << "." << _godina<<endl;
	}
};

enum TipKorisnika { Administrator, Guest };
const char * TipKorisnikaChar[] = { "Administrator", "Guest" };
class Korisnik
{
	char _ime[30];
	char _korisnickoIme[20];
	char* _lozinka;
	TipKorisnika _tipKorisnika; //Administrator, Guest
	Datum *_datumRegistracije;
public:
	//Potrebne konstruktor i destruktor funkcije
	Korisnik(const char * ime = "N/A", const char * korisnickoIme = "N/A", const char * lozinka = "XYC123xyc", TipKorisnika tip = Guest, int d = 1, int m = 1, int g = 2000)
	{
		strcpy_s(_ime, ime);
		strcpy_s(_korisnickoIme, korisnickoIme);
		_lozinka = new char[strlen(lozinka) + 1];
		strcpy_s(_lozinka, strlen(lozinka) + 1, lozinka);
		_tipKorisnika = tip;
		_datumRegistracije = new Datum(d, m, g);
	}
	
	Korisnik(Korisnik &k)
	{
		strcpy_s(_ime, k._ime);
		strcpy_s(_korisnickoIme, k._korisnickoIme);
		_lozinka = new char[strlen(k._lozinka) + 1];
		strcpy_s(_lozinka, strlen(k._lozinka) + 1, k._lozinka);
		_tipKorisnika = k._tipKorisnika;
		_datumRegistracije = new Datum(*k._datumRegistracije);
	}
	
	~Korisnik()
	{
		delete[] _lozinka; _lozinka = nullptr;
	}
	//Funkciju za promjenu korisničke lozinke
	
	void PromijeniLozinku(const char * novaLozinka)
	{
		if (strcmp(_lozinka, novaLozinka) == 0 || strlen(novaLozinka) < 5)
			return;
		delete[] _lozinka;
		_lozinka = new char[strlen(novaLozinka) + 1];
		strcpy_s(_lozinka, strlen(novaLozinka) + 1, novaLozinka);
	}
	
	//Funkciju Info
	void Info()
	{
		cout << "Ime: " << _ime << endl;
		cout << "Korisnicko ime: " << _korisnickoIme << endl;
		cout << "Tip: " << TipKorisnikaChar[_tipKorisnika] << crt;
	}

	char * GetKorisnickoIme()
	{
		return _korisnickoIme;
	}

};

class Komentar
{
	char* _tekst;
	Datum _datum;
	Vrijeme _satnica;
	int _popularnost;
	Korisnik* _autor;
public:
	//Potrebne konstruktor i destruktor funkcije
	Komentar(const char * tekst, Datum d, Vrijeme v, int popularnost, Korisnik k)
		: _datum(d), _satnica(v)
	{
		_tekst = new char[strlen(tekst) + 1];
		strcpy_s(_tekst, strlen(tekst) + 1, tekst);
		_popularnost = popularnost;
		_autor = new Korisnik(k);
	}

	//Funkciju za izmjenu popularnosti komentara
	void SetPopularnost(int popularnost)
	{
		if (_popularnost < 0)
			return;
		_popularnost = popularnost;
	}
	//Funkciju Info
	void Info()
	{
		cout << _tekst << crt;
		cout << "Popularnost: " << _popularnost<<endl;
		_datum.Info();
		_satnica.Info();
		cout<<_autor->GetKorisnickoIme();
		cout << crt << crt;
	}
};

class Clanak
{
	char _naslov[150];
	char* _sadrzaj;
	Datum _datum;
	Vrijeme _satnica;
	int _brojPregleda;
	char* _tagovi[10];
	char _oblast[100];
	Korisnik* _autor;
	Komentar* _komentari;
	int _brojKomentara;
public:

	Clanak()
	{
		strcpy_s(_naslov, "N/A");
		_sadrzaj = nullptr;
		_brojPregleda = 0;
		for (size_t i = 0; i < 10; i++)
		{
			_tagovi[i] = nullptr;
		}
		strcpy_s(_oblast, "N/A");
		_autor = nullptr;
		_komentari = nullptr;
		_brojKomentara = 0;
	}

	Clanak(const char * naslov, Datum d, Vrijeme v, const char * oblast, Korisnik autor )
		:_datum(d), _satnica(v)
	{
		strcpy_s(_naslov, naslov);
		_sadrzaj = nullptr;
		strcpy_s(_oblast, oblast);
		_autor = new Korisnik(autor);
		_komentari = nullptr;
		_brojKomentara = 0;
		for (size_t i = 0; i < 10; i++)
		{
			_tagovi[i] = nullptr;
		}
		_brojPregleda = 0;

	}
	
	~Clanak()
	{
		delete[] _sadrzaj; _sadrzaj = nullptr;
		for (size_t i = 0; i < 10; i++)
		{
			if (_tagovi[i] != nullptr)
			{
				delete[] _tagovi[i]; _tagovi[i] = nullptr;
			}
		}

		delete _autor; _autor = nullptr;
		delete[] _komentari; _komentari = nullptr;

	}

	//Funkciju za dodavanje tagova za članak
	void DodajTag(const char * tag)
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (_tagovi[i] == nullptr)
			{
				_tagovi[i] = new char[strlen(tag) + 1];
				strcpy_s(_tagovi[i], strlen(tag) + 1, tag);
				return;
			}
		}
	}


	/*Funkciju za promjenu sadržaja i vremena promjene članka. Kao verifikaciju dozvole potrebno je proslijediti korisničko ime autora članka.
	Samo kreator članka ima permisije da mijenja njegov sadržaj.
	*/

	void PromijeniSadrzaj(const char * autor)
	{
		if (strcmp(autor, _autor->GetKorisnickoIme()) != 0)
			return;

	}




	//Funkciju za dodavanje komentara

	//Funkciju Info

};

int main()
{
	//Kreirati testni program koji demonstrira implementirane funckionalnosti



	system("pause>0");
	return 0;
}




