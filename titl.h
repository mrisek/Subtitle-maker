#include<iostream>
#include<string>
#include<fstream> //ifstream
#include<sstream> //stringstream
#include<iomanip> //setfill, setw
#include <cstring> //obrada stringa
#include <cstdlib> //obrada vremena
#include <windows.h> //pristup Windows direktoriju
#include<dirent.h>//putanja direktorija
#include <cstddef>//ekstenzija datoteke
#include <shlobj.h>//editiranje putanje direktorija
#include <algorithm>
using namespace std;
#pragma comment(lib, "shell32.lib")//editiranje putanje

using namespace std;
typedef int elementtype;
void meni();

class vrijeme
{
	public:
		elementtype sati = 0;
		elementtype minute = 0;
		elementtype sekunde = 0;
		elementtype milisekunde = 0;
};

class titl : public vrijeme
{
	public:
		vrijeme startVrijeme;
		vrijeme krajVrijeme;
		string tekst;
		
		//Osnovne metode
		void pozdravnaPoruka();
		void meni();
		void oProgramu();
		void izlaz();
		
		//Metode za rad sa titlovima
		string urediPutanju(string path);
		string vratiPutanjuGlavnogDirektorija();
		string vratiEkstenzijuDatoteke(const string& str);
		bool ispisiSadrzajDirektorija(string ekstenzija);
		bool ispisiSvePodrzaneDatoteke();
		
		//Metode za rad sa Windows datoteènim sustavom
		void ispisiIzDatoteke (string naziv);
		void promjeniFormatDatoteke();
		void izmjeniTitl(string naziv);
		void ispraviTitlove();
		void pregledajTitlove();
		void kreirajNovuDatoteku();
		void eksportirajTitl(string naziv, string format);
		
};

class element : public titl
{
	public:
		titl t;
		element* sljedeci;
		
		element()
		{
			sljedeci=NULL;
		}
};

class Red
{
	private:
    	element *celo, *zacelje;
    public:
		Red()
		{
	    	celo=new element;
	    	zacelje=celo;
	    }
	    ~Red()
		{
			delete celo;
	    }
		void InitQ();
		void EnqueueQ(string tekst, elementtype startSat, elementtype startMin, elementtype startSek, elementtype startMilSek,
			elementtype krajSat, elementtype krajMin, elementtype krajSek, elementtype krajMilSek);
		bool IsEmptyQ();
		void DequeueQ();
		void ChangeQ(string naziv, int linija, string tekst, string vrijemePocetak, string vrijemeKraj);
		string FrontQ();
		void PrintQ();
		string IspisiSrtDatoteku();
		string IspisiTitlDatoteku(bool konzola);
		void KreirajSrtDatoteku(string naziv);
		int SizeQ();
};
