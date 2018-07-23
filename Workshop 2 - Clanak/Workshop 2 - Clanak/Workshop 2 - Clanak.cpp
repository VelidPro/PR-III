// Workshop 2 - Clanak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

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

	//Funkciju Info
};

enum TipKorisnika { Administrator, Guest };
class Korisnik
{
	char _ime[30];
	char _korisnickoIme[20];
	char* _lozinka;
	TipKorisnika _tipKorisnika; //Administrator, Guest
public:
	//Potrebne konstruktor i destruktor funkcije

	//Funkciju za promjenu korisničke lozinke

	//Funkciju Info

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

	//Funkciju za izmjenu popularnosti komentara

	//Funkciju Info

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

	//Funkciju za dodavanje tagova za članak

	/*Funkciju za promjenu sadržaja i vremena promjene članka. Kao verifikaciju dozvole potrebno je proslijediti korisničko ime autora članka.
	Samo kreator članka ima permisije da mijenja njegov sadržaj.
	*/

	//Funkciju za dodavanje komentara

	//Funkciju Info

};

int main()
{
	//Kreirati testni program koji demonstrira implementirane funckionalnosti

	system("pause>0");
	return 0;
}




