// Workshop 1 - eRestoran.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

const char *crt = "\n-------------------------------------------------------\n";

/* Vježbe 1 - Principi OOP. klase, objekti.
Zadatak: Na osnovu opisa sistema prepoznati osnovne klase i atribute, kao i njihove relacije, te implementirati osnovne metode koje omogucavaju kreiranje i
ispis narudzbi klijentu. Obavezno implementirati Get i Set metode.

Tema: e-Restoran

Namjena aplikacije e-Restoran jeste da omoguci kreiranje narudzbi klijentima restorana putem standardnih PC i mobilnih uredjaja.
U procesu kreiranja narudzbe neophodno je da klijent obavi registraciju gdje upisuje svoje osnovne podatke:
ime, prezime, kontakt broj i adresu.
Nakon uspjesne registracije klijenti mogu da kreiraju narudzbu na osnovu online ponude odabranog restorana.
Ponuda restorana se sastoji od jela i pica.
Uz svako jelo i pice se prikazuje kratak opis i cijena. Narudzba koju klijent kreira sadrzi najmanje jedno jelo ili pice,
ukupnu cijenu narudzbe i status isporuke.
*/


class Klijent
{
	char * _ime;
	char * _prezime;
	char * _kontaktBroj;
	char * _adresa;

public:
	//Konstruktori
	Klijent(const char * ime = "N/A", const char * prezime = "N/A", const char * broj = "xxx-xxx-xxx", const char * adresa = "N/A")
	{
		_ime = new char[strlen(ime) + 1];
		strcpy_s(_ime, strlen(ime) + 1, ime);

		_prezime = new char[strlen(prezime) + 1];
		strcpy_s(_prezime, strlen(prezime) + 1, prezime);

		_adresa = new char[strlen(adresa) + 1];
		strcpy_s(_adresa, strlen(adresa) + 1, adresa);

		_kontaktBroj = new char[strlen(broj) + 1];
		strcpy_s(_kontaktBroj, strlen(broj) + 1, broj);
	}
	Klijent(Klijent &obj)
	{
		_ime = new char[strlen(obj._ime) + 1];
		strcpy_s(_ime, strlen(obj._ime) + 1, obj._ime);

		_prezime = new char[strlen(obj._prezime) + 1];
		strcpy_s(_prezime, strlen(obj._prezime) + 1, obj._prezime);

		_adresa = new char[strlen(obj._adresa) + 1];
		strcpy_s(_adresa, strlen(obj._adresa) + 1, obj._adresa);

		_kontaktBroj = new char[strlen(obj._kontaktBroj) + 1];
		strcpy_s(_kontaktBroj, strlen(obj._kontaktBroj) + 1, obj._kontaktBroj);
	}
	
	//Destruktor
	~Klijent()
	{
		delete[] _ime; _ime = nullptr;
		delete[] _prezime; _prezime = nullptr;
		delete[] _kontaktBroj; _kontaktBroj = nullptr;
		delete[] _adresa; _adresa = nullptr;
	}

	//Set Funkcije
	void Set(char *& atribut, const char * vrijednost)
	{
		atribut = new char[strlen(vrijednost) + 1];
		strcpy_s(atribut, strlen(vrijednost) + 1, vrijednost);
	}
	void SetIme(const char * ime) // Staviti u private
	{
		Set(_ime, ime);
	}
	void SetPrezime(const char * prezime)
	{
		Set(_prezime, prezime);
	}
	void SetKontaktBroj(const char * broj)
	{
		Set(_kontaktBroj, broj);
	}
	void SetAdresa(const char * adresa)
	{
		Set(_adresa, adresa);
	}

	//Get Funkcije
	char * GetIme()
	{
		return _ime;
	}
	char * GetPrezime()
	{
		return _prezime;
	}
	char * GetAdresa()
	{
		return _adresa;
	}
	char * GetKontaktBroj()
	{
		return _kontaktBroj;
	}
};

class Jelo
{
private:
	char * _naziv;
	char _opis[200];
	float _cijena;
public:
	//Konstruktor i Destruktor
	Jelo(const char * naziv = "N/A", const char * opis = "N/A", float cijena = 0)
	{
		SetNaziv(naziv);
		SetOpis(opis);
		SetCijena(cijena);
	}
	~Jelo()
	{
		delete[] _naziv; _naziv = nullptr;
	}

	//SetFunkcije
	void Set(char *&atribut, const char * vrijednost)
	{
		atribut = new char[strlen(vrijednost) + 1];
		strcpy_s(atribut, strlen(vrijednost) + 1, vrijednost);
	}
	void SetNaziv(const char * naziv)
	{
		Set(_naziv, naziv);
	}
	void SetOpis(const char * opis)
	{
		strcpy_s(_opis, opis);
	}
	void SetCijena(float cijena)
	{
		_cijena = cijena;
	}

	//Get funckije
	char * GetNaziv() { return _naziv; }
	char * GetOpis() { return _opis; }
	float GetCijena() { return _cijena; }

};

class Pice
{
private:
	char * _naziv;
	char _opis[200];
	float _cijena;
public:
	//Konstruktor i Destruktor
	Pice(const char * naziv = "N/A", const char * opis = "N/A", float cijena = 0)
	{
		SetNaziv(naziv);
		SetOpis(opis);
		SetCijena(cijena);
	}
	~Pice()
	{
		delete[] _naziv; _naziv = nullptr;
	}

	//SetFunkcije
	void Set(char *&atribut, const char * vrijednost)
	{
		atribut = new char[strlen(vrijednost) + 1];
		strcpy_s(atribut, strlen(vrijednost) + 1, vrijednost);
	}
	void SetNaziv(const char * naziv)
	{
		Set(_naziv, naziv);
	}
	void SetOpis(const char * opis)
	{
		strcpy_s(_opis, opis);
	}
	void SetCijena(float cijena)
	{
		_cijena = cijena;
	}

	//Get funckije
	char * GetNaziv() { return _naziv; }
	char * GetOpis() { return _opis; }
	float GetCijena() { return _cijena; }
};

class Restoran
{
private:
	char * _naziv;
    char * _brTelefona;
	Klijent * _listaKlijenata;
	int _trenutnoKlijenata;
    Pice *_listaPicaUPonudi[50];
	int _trenutnoPica;
	Jelo *_listaJelaUPonudi[50];
	int _trenutnoJela;

public:
	//Konstruktor
	Restoran(const char * naziv, const char * brTelefona)
	{
		_naziv = new char[strlen(naziv) + 1];
		strcpy_s(_naziv, strlen(naziv) + 1, naziv);

		_brTelefona = new char[strlen(brTelefona) + 1];
		strcpy_s(_brTelefona, strlen(brTelefona) + 1, brTelefona);

		_listaKlijenata = nullptr; // Niz ce se prosirivati svakim novim klijentom

		for (size_t i = 0; i < 50; i++)
		{
			_listaJelaUPonudi[i] = nullptr;
			_listaPicaUPonudi[i] = nullptr;
		}
		_trenutnoKlijenata = 0;
		_trenutnoJela = 0;
		_trenutnoPica = 0;
	}
	
	//Destruktor
	~Restoran()
	{
		delete[] _naziv; _naziv = nullptr;
		delete[] _brTelefona; _brTelefona = nullptr;

		delete[] _listaKlijenata; _listaKlijenata = nullptr;
		_trenutnoJela = 0;
		_trenutnoPica = 0;
		_trenutnoKlijenata = 0;
	}

	//SetFunkcije
	void Set(char *& atribut, const char * vrijednost)
	{
		atribut = new char[strlen(vrijednost) + 1];
		strcpy_s(atribut, strlen(vrijednost) + 1, vrijednost);
	}
	void SetNaziv(const char * naziv)
	{
		Set(_naziv, naziv);
	}
	void SetBrTelefona(const char * brTelefona)
	{
		Set(_brTelefona, brTelefona);
	}

	//Get Funckije
	char * GetNaziv() { return _naziv; }
	char * GetBrTelefona() { return _brTelefona; }
	int GetTrenutnoKlijenata() { return _trenutnoKlijenata; }

	//Funkcije Add
	void AddKlijent(const char * ime, const char * prezime, const char *adresa, const char * broj)
	{
		Klijent * temp = new Klijent[_trenutnoKlijenata + 1];
		for (size_t i = 0; i < _trenutnoKlijenata; i++)
		{
			temp->SetIme(_listaKlijenata[i].GetIme());
			temp->SetPrezime(_listaKlijenata[i].GetPrezime());
			temp->SetAdresa(_listaKlijenata[i].GetAdresa());
			temp->SetKontaktBroj(_listaKlijenata[i].GetKontaktBroj());
		}
		delete[] _listaKlijenata;
		_listaKlijenata = temp;
		_listaKlijenata[_trenutnoKlijenata].SetIme(ime);
		_listaKlijenata[_trenutnoKlijenata].SetAdresa(adresa);
		_listaKlijenata[_trenutnoKlijenata].SetPrezime(prezime);
		_listaKlijenata[_trenutnoKlijenata].SetKontaktBroj(broj);
		_trenutnoKlijenata++;
	}
	void AddJelo(const char * naziv, const char * opis, float cijena)
	{
		if (_trenutnoJela == 50)
			return;
		_listaJelaUPonudi[_trenutnoJela] = new Jelo(naziv, opis, cijena);
		_trenutnoJela++;
	}
	void AddPice(const char * naziv, const char * opis, float cijena)
	{
		if (_trenutnoPica == 50)
			return;
		_listaPicaUPonudi[_trenutnoPica] = new Pice(naziv, opis, cijena);
		_trenutnoPica++;
	}
	
	void Ponuda()
	{
		cout << "Jela: "<<crt;
		for (size_t i = 0; i < _trenutnoJela; i++)
		{
			cout<<_listaJelaUPonudi[i]->GetNaziv() << "    " << _listaJelaUPonudi[i]->GetCijena() << " KM" << endl;
			cout<<_listaJelaUPonudi[i]->GetOpis() << endl<<endl;
		}
		cout << crt;
		cout<<"\nPica: "<<crt;
		for (size_t i = 0; i < _trenutnoPica; i++)
		{
			cout << _listaPicaUPonudi[i]->GetNaziv() << "    " << _listaPicaUPonudi[i]->GetCijena() << " KM" << endl;
			cout << _listaPicaUPonudi[i]->GetOpis() << endl<<endl;
		}
		cout << crt;
	}
};


class Narudzba
{
private:
	Jelo * _narucenaJela[50];
	int _trenutnoNarucenihJela;
	Pice * _narucenaPica[50];
	int _trenutnoNarucenihPica;
	char _statusIsporuke[50];


public:
	//Konstruktor i destruktor
	Narudzba()
	{
		strcpy_s(_statusIsporuke, "Nije naruceno");

		for (size_t i = 0; i < 50; i++)
		{
			_narucenaJela[i] = nullptr;
			_narucenaPica[i] = nullptr;
		}
		_trenutnoNarucenihJela = 0;
		_trenutnoNarucenihPica = 0;
	}
	~Narudzba()
	{
		for (size_t i = 0; i < 50; i++)
		{
			delete _narucenaJela[i]; _narucenaJela[i] = nullptr;
			delete _narucenaPica[i]; _narucenaPica[i] = nullptr;
		}
	}

	//Set funkcije
	void SetStatusIsporuke(const char * status)
	{
		strcpy_s(_statusIsporuke, status);
	}

	//Get Funckije
	char* GetStatusIsporuke() { return _statusIsporuke; }

	void DodajUNarudzbu(Pice p = NULL, Jelo j = NULL)
	{
		if (&p != NULL)
		{
			_narucenaPica[_trenutnoNarucenihPica] = &p;
			_trenutnoNarucenihPica++;
		}
		if (&j != NULL)
		{
			_narucenaJela[_trenutnoNarucenihJela] = &j;
			_trenutnoNarucenihJela++;
		}
	}
	bool Naruci()
	{
		if ((_trenutnoNarucenihJela + _trenutnoNarucenihPica) == 0)
		{
			return false;
		}
		else
		{
			strcpy_s(_statusIsporuke, "U pripremi");
			return true;
		}
	}
};



int main()
{
	Restoran himzo("Himzo","033-555-555");
	himzo.AddPice("Coca Cola", "Gazirano bezalkoholno pice, crne boje", 2.50);
	himzo.AddPice("Kisela", "Gazirano bezalkoholno pice, providne boje. Gazirana voda.", 1.50);
	himzo.AddPice("Voda", "Negazirano bezalkoholno pice. Bez boje, mirisa i okusa.", 1);
	himzo.AddPice("Kafa", "Bezalkoholni kofeinski napitak, crne boje.", 1);

	himzo.AddJelo("Cevapi", "Mesnato jelo duzine cackalice. 10 komada - Desetka", 7);
	himzo.AddJelo("Burek", "Pita sa mljevenim mesom", 2.50);
	himzo.AddJelo("Corba", "Corbasto jelo sa povrcem", 3);

	himzo.Ponuda();

	Narudzba a;




	system("pause>0");
	return 0;
}


