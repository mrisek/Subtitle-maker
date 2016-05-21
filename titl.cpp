#include "titl.h"

void Red::InitQ()
{
	element *pozicija=this->celo;
	element *pomocni;
	while(pozicija->sljedeci!=NULL){
    pomocni=pozicija->sljedeci;
    pozicija->sljedeci = pozicija->sljedeci->sljedeci;
    delete pomocni;
    }
    this->zacelje=this->celo;
};

void Red::EnqueueQ(string tekst, elementtype startSat, elementtype startMin, elementtype startSek, elementtype startMilSek,
	elementtype krajSat, elementtype krajMin, elementtype krajSek, elementtype krajMilSek)
{
    element *novi=new element;
    novi->tekst=tekst;
    novi->startVrijeme.sati=startSat;
    novi->startVrijeme.minute=startMin;
    novi->startVrijeme.sekunde=startSek;
    novi->startVrijeme.milisekunde=startMilSek;
    novi->krajVrijeme.sati=krajSat;
    novi->krajVrijeme.minute=krajMin;
    novi->krajVrijeme.sekunde=krajSek;
    novi->krajVrijeme.milisekunde=krajMilSek;
    novi->sljedeci=NULL;
    this->zacelje->sljedeci=novi;
    this->zacelje=novi;
};

bool Red::IsEmptyQ()
{
    if (this->celo==this->zacelje) return true;
    return false;
};

void Red::DequeueQ()
{
    if (this->IsEmptyQ()) return;
    element * privremeni;
    privremeni = this->celo->sljedeci;
    this->celo->sljedeci = this->celo->sljedeci->sljedeci;
    if(this->celo->sljedeci==NULL) this->zacelje=this->celo;
    delete privremeni;
};

string Red::FrontQ()
{
    if(!this->IsEmptyQ())
    return this->celo->sljedeci->tekst;
};

void Red::PrintQ()
{
	element* pozicija;
	if(this->IsEmptyQ()) {cout<<"Prazan red."<<endl; return;}
	pozicija = this->celo;
	int broj=0;
	while(pozicija->sljedeci!=NULL){
		broj++;
	    cout<<broj<<"\n"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<" --> "<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<"\n"<<
			pozicija->sljedeci->tekst<<"\n\n";
	    pozicija = pozicija->sljedeci;
	}
    cout<<endl;
    
};

void Red::ChangeQ(string naziv, int linija, string tekst, string vrijemePocetak, string vrijemeKraj)
{
	element* pozicija;
	if(this->IsEmptyQ()) {cout<<"Prazan red."<<endl; return ;}
	pozicija = this->celo;
	int broj=0;
	
	ofstream changeTitlFile;
	changeTitlFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".titl").c_str());	
	
	while(pozicija->sljedeci!=NULL){
		broj++;
		if(broj == linija)
		{	
		    changeTitlFile<<setfill('0')<<setw(2)<<vrijemePocetak.substr(0,2).c_str()<<";"<<setfill('0')<<setw(2)<<vrijemePocetak.substr(3,2).c_str()<<";"<<
			setfill('0')<<setw(2)<<vrijemePocetak.substr(6,2).c_str()<<";"<<setfill('0')<<setw(3)<<vrijemePocetak.substr(9,3).c_str()<<";"<<
			setfill('0')<<setw(2)<<vrijemeKraj.substr(0,2).c_str()<<";"<<setfill('0')<<setw(2)<<(vrijemeKraj.substr(3,2).c_str())<<";"<<
			setfill('0')<<setw(2)<<vrijemeKraj.substr(6,2).c_str()<<";"<<setfill('0')<<setw(3)<<vrijemeKraj.substr(9,3).c_str()<<";"<<
			tekst<<";";		
		}
		else
		{
		    changeTitlFile<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<";"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<";"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<";"<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<";"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<";"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<";"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<";"<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<";"<<
			pozicija->sljedeci->tekst<<";";
		}
		pozicija = pozicija->sljedeci;
	}
	changeTitlFile.close();
};

string Red::IspisiSrtDatoteku()
{
	stringstream datoteka;
	element* pozicija;
	if(this->IsEmptyQ()) {return "Prazan red";}
	pozicija = this->celo;
	int broj=0;	
	while(pozicija->sljedeci!=NULL){
		broj++;
	    datoteka<<broj<<"\n"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<" --> "<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<"\n"<<
			pozicija->sljedeci->tekst<<"\n\n";
	    pozicija = pozicija->sljedeci;
	}
    cout<<endl;
    
    return datoteka.str();
};

string Red::IspisiTitlDatoteku(bool konzola)
{
	stringstream datoteka;
	element* pozicija;
	if(this->IsEmptyQ()) {return "Prazan red";}
	pozicija = this->celo;
	int broj=0; //ispis u datoteku
	if(!konzola)
	{
		while(pozicija->sljedeci!=NULL)
		{
			broj++;
		    datoteka<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<";"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<";"<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<";"<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<";"<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<";"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<";"<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<";"<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<";"<<
				pozicija->sljedeci->tekst<<";";
		    pozicija = pozicija->sljedeci;
		}
	}
	else //ispis u konzolu
	{
		while(pozicija->sljedeci!=NULL){
			broj++;
		    cout<<"Linija "<<broj<<":\n"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<":"<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<" - "<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<":"<<
				setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<"\n"<<
				pozicija->sljedeci->tekst<<"\n\n";
		    pozicija = pozicija->sljedeci;
		}
		
	}	
    cout<<endl;
    
    return datoteka.str();
};

void Red::KreirajSrtDatoteku(string naziv)
{
	stringstream ss;
	
	element* pozicija;
	if(this->IsEmptyQ()) {cout<<"Prazan red."<<endl; return;}
	pozicija = this->celo;
	int broj=0;
	
	ofstream myfile;
	myfile.open(naziv.c_str());
	
	while(pozicija->sljedeci!=NULL){
		broj++;
	    myfile<<broj<<"\n"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->startVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->startVrijeme.milisekunde)<<" --> "<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sati)<<":"<<setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.minute)<<":"<<
			setfill('0')<<setw(2)<<(pozicija->sljedeci->krajVrijeme.sekunde)<<","<<setfill('0')<<setw(3)<<(pozicija->sljedeci->krajVrijeme.milisekunde)<<"\n"<<
			pozicija->sljedeci->tekst<<"\n\n";
	    pozicija = pozicija->sljedeci;
	}
    cout<<endl;
    
    myfile.close();
};
    
int Red::SizeQ()
{
	if(this->IsEmptyQ()) {cout<<"Prazan red."<<endl; return 0;}
	element* pozicija;
	pozicija=this->celo;
	int size=0;
	while(pozicija!=this->zacelje){
		size++;
		pozicija=pozicija->sljedeci;
	}
	return size;
}

void titl::pozdravnaPoruka()
{
	setlocale(LC_ALL,""); // postavljam lokalni jezik u upotrebu
	system("cls");
	cout<<"\n\n\n\n\n\n\n________________________________________________________________________________\n"<<endl;
	cout<<"                    Dobrodošli u program za rad sa titlovima!\n"<<endl;
	cout<<"________________________________________________________________________________\n\n\n\t\t\t";
	system("pause");
}

void titl::oProgramu()
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                           ***  Detalji o programu  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"\t\tNaziv: Program za rad sa titlovima"<<endl;
	cout<<"\t\tVerzija: 1.0"<<endl;
	cout<<"\t\tIzradio: Matija Risek"<<endl;
	cout<<"\t\tDatum: 15.01.2016."<<endl;
	cout<<"\n\n================================================================================\n\n\n\t\t";
	system("pause");
	meni();
}

void titl::izlaz()
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                                Kraj programa!\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"\n\n\n\t\t\t";
	system("pause");
}

void titl::kreirajNovuDatoteku()
{
	system("cls");
	string naziv = "";
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                   ***  Kreiranje datoteke sa titlovima  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"Upišite naziv datoteke koju želite kreirati"<<endl;
	cin>>naziv;
	naziv.append(".titl"); //dodavanje ekstenzije .titl koju program koristi za stvaranje novog titla
	
	// Primjer stvaranja datoteke
	ofstream myfile;
	// Provjera postoji li datoteka
	ifstream ifile(naziv.c_str()); //zbog ifstream-a mi je potreban const char pointer pa koristim funkciju c_str()
	if(!ifile)// Provjeravam postoji li datoteka sa istim imenom i formatom, ovo je sluèaj kad ne postoji.
	{
		myfile.open(naziv.c_str()); //zbog ifstream-a mi je potreban const char pointer pa koristim funkciju c_str()
	
		Red r;
		string tekstTitla = "";
		string vrijemeP="";
		string vrijemeK="";
		int broj = 0;
		
		system("cls");
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"\t***  "<<naziv<<"  ***\n"<<endl;
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"Kad ste gotovi, upišite \"KRAJ\""<<endl;
		for(;;){
			cin.ignore();
			broj++;
			cout<<"\nUnesite tekst "<<broj<<". titla: "<<endl;
			getline(cin,tekstTitla);
			if(tekstTitla == "KRAJ" || tekstTitla == "kraj") break;
			cout<<"Unesite vrijeme poèetka prikaza "<<broj<<". titla (HH:MM:SS,mS)"<<endl;
			cin>>vrijemeP;
			cout<<"Unesite vrijeme kraja prikaza "<<broj<<". titla (HH:MM:SS,mS)"<<endl;
			cin>>vrijemeK;
			
			// kreiranje titla na temelju korisnièkog unosa pomoæu implementirane strukture podataka - reda	
			r.EnqueueQ(tekstTitla, atoi( vrijemeP.substr(0,2).c_str() ), atoi( vrijemeP.substr(3,2).c_str() ), 
				atoi( vrijemeP.substr(6,2).c_str() ), atoi( vrijemeP.substr(9,3).c_str() ), 
				atoi( vrijemeK.substr(0,2).c_str() ), atoi( vrijemeK.substr(3,2).c_str() ),
				atoi( vrijemeK.substr(6,2).c_str() ), atoi( vrijemeK.substr(9,3).c_str() ));

		}
		
		cout<<"\n";
		r.IspisiTitlDatoteku(false);
		myfile<<r.IspisiTitlDatoteku(false);

		myfile.close();
		
		cout<<"Datoteka s nazivom "<<naziv<<" je uspješno kreirana!"<<endl;
	}
	else// Ukoliko veæ postoji datoteka sa odabranim imenom
	{
		cout<<"\nDatoteka s tim imenom vec postoji.\nZelite prebrisati postojecu datoteku? (da/ne)"<<endl;
		string unos;
		bool odabir = false;
		do{
			cin>>unos;
			if(unos=="da" || unos=="Da" || unos=="DA" || unos=="dA")
			{
				cin.ignore();
				myfile.open(naziv.c_str()); //zbog ifstream-a mi je potreban const char pointer pa koristim funkciju c_str()
				Red r;
				string tekstTitla = "";
				string vrijemeP="";
				string vrijemeK="";
				int broj = 0;
				
				system("cls");
				cout<<"________________________________________________________________________________\n"<<endl;
				cout<<"                        "<<naziv<<".titl"<<"  ***\n"<<endl;
				cout<<"________________________________________________________________________________\n"<<endl;
				cout<<"Kad ste gotovi, upišite \"KRAJ\""<<endl;
				for(;;){
					cin.ignore();
					broj++;
					cout<<"\nUnesite tekst "<<broj<<". titla: "<<endl;
					getline(cin,tekstTitla);
					if(tekstTitla == "KRAJ" || tekstTitla == "kraj") break;
					cout<<"Unesite vrijeme poèetka prikaza "<<broj<<". titla (HH:MM:SS,mS)"<<endl;
					cin>>vrijemeP;
					cout<<"Unesite vrijeme kraja prikaza "<<broj<<". titla (HH:MM:SS,mS)"<<endl;
					cin>>vrijemeK;
					
					// kreiranje titla na temelju korisnièkog unosa pomoæu implementirane strukture podataka - reda	
					r.EnqueueQ(tekstTitla, atoi( vrijemeP.substr(0,2).c_str() ), atoi( vrijemeP.substr(3,2).c_str() ), 
						atoi( vrijemeP.substr(6,2).c_str() ), atoi( vrijemeP.substr(9,3).c_str() ), 
						atoi( vrijemeK.substr(0,2).c_str() ), atoi( vrijemeK.substr(3,2).c_str() ),
						atoi( vrijemeK.substr(6,2).c_str() ), atoi( vrijemeK.substr(9,3).c_str() ));
		
				}
				
				cout<<"\n";
				r.IspisiTitlDatoteku(false);
				myfile<<r.IspisiTitlDatoteku(false);
		
				myfile.close();
				
				cout<<"Datoteka s nazivom "<<naziv<<" je uspješno prebrisana novom datotekom!"<<endl;	
				
				break;
			}
			else if(unos=="ne" || unos=="Ne" || unos=="NE" || unos=="nE"){
				cin.ignore();
				cout<<"\nDatoteka nije prebrisana."<<endl;
				odabir = true;
				break;
			}
			else
			{
				cin.ignore();
				cout<<"\nPogrešan unos. Pokušajte ponovo."<<endl;
				odabir = false;
			}

		}while(!odabir);
	}
	cout<<"\n================================================================================\n";
	system("pause");
	meni();
}

void titl::eksportirajTitl(string naziv, string format)
{
	string line;
	ifstream myfile (naziv.c_str());
	
	if(myfile.is_open())
	{
		Red r;
		string tekstTitla = "";
		
		elementtype vrijemePSati = 0;
		elementtype vrijemePMinute = 0;
		elementtype vrijemePSekunde = 0;
		elementtype vrijemePMilisekunde = 0;
		
		elementtype vrijemeKSati = 0;
		elementtype vrijemeKMinute = 0;
		elementtype vrijemeKSekunde = 0;
		elementtype vrijemeKMilisekunde = 0;
		
		int brojac = 0;		// broj argumenta
		int redniBroj = 1;	// redni broj titla

		// Prva faza promjene formata datoteke
		ofstream exportFile;	//stvaram datoteku u koju æu eksportirati titl
		if(format == "srt")
		{
			exportFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".srt").c_str());
		}
		else if(format == "rt")
		{
			exportFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".rt").c_str());	
			exportFile<<"<Window\n  Width    = \"640\"\n  Height   = \"480\"\n  WordWrap = \"true\"\n  Loop     = \"true\"\n  bgcolor  = \"black\"\n>\n<Font\n  Color = \"white\"\n  Face  = \"Arial\"\n  Size  = \"+2\"\n>\n<center>\n<b>\n\n";
		}
		else if(format == "sub")
		{
			exportFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".sub").c_str());
			exportFile<<"{HEAD\nDISCID=\nDVDTITLE=\nCODEPAGE=1250\nFORMAT=ASCII\nLANG=\nTITLE=1\nORIGINAL=ORIGINAL\nAUTHOR=\nWEB=\nINFO=\nLICENSE=\n}";
		}
		else if(format == "ssa")
		{
			exportFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".ssa").c_str());
			exportFile<<"[Script Info]\n; This is a Sub Station Alpha v4 script.\nTitle: test\nScriptType: v4.00\nCollisions: Normal\nPlayDepth: 0\n\n[V4 Styles]\nFormat: Name, Fontname, Fontsize, PrimaryColour, SecondaryColour, TertiaryColour, BackColour, Bold, Italic, BorderStyle, Outline, Shadow, Alignment, MarginL, MarginR, MarginV, AlphaLevel, Encoding\nStyle: Default,Arial,20,16777215,65535,65535,-2147483640,-1,0,1,3,0,2,10,10,10,0,1\n\n[Events]\nFormat: Marked, Start, End, Style, Name, MarginL, MarginR, MarginV, Effect, Text";
		}
		else if(format == "ass")
		{
			exportFile.open(naziv.erase(naziv.find("."),naziv.length()).append(".ass").c_str());
			exportFile<<"[Script Info]\n; This is an Advanced Sub Station Alpha v4+ script.\nTitle: test\nScriptType: v4.00+\nCollisions: Normal\nPlayDepth: 0\n\n[V4+ Styles]\nFormat: Name, Fontname, Fontsize, PrimaryColour, SecondaryColour, OutlineColour, BackColour, Bold, Italic, Underline, StrikeOut, ScaleX, ScaleY, Spacing, Angle, BorderStyle, Outline, Shadow, Alignment, MarginL, MarginR, MarginV, Encoding\nStyle: Default,Arial,20,&H00FFFFFF,&H0300FFFF,&H00000000,&H02000000,0,0,0,0,100,100,0,0,1,2,2,2,10,10,10,1\n\n[Events]\nFormat: Layer, Start, End, Style, Actor, MarginL, MarginR, MarginV, Effect, Text";
		}

		
		while(getline(myfile,line, ';')) //èitanje argument po argument
		{
			brojac++;
			//cout<<"Redni broj: "<<redniBroj<<" - Brojac: "<<brojac<<" Linija: "<<line<<"\n";
			if(brojac==1)
				vrijemePSati = atoi(line.c_str());			
			else if(brojac==2)
				vrijemePMinute = atoi(line.c_str());
			else if(brojac==3)
				vrijemePSekunde = atoi(line.c_str());
			else if(brojac==4)
				vrijemePMilisekunde = atoi(line.c_str());
			else if(brojac==5)
				vrijemeKSati = atoi(line.c_str());
			else if(brojac==6)
				vrijemeKMinute = atoi(line.c_str());
			else if(brojac==7)
				vrijemeKSekunde = atoi(line.c_str());
			else if(brojac==8)
				vrijemeKMilisekunde = atoi(line.c_str());
			else if(brojac==9)
			{
				tekstTitla = line;
				r.EnqueueQ(tekstTitla, 
					vrijemePSati, vrijemePMinute, vrijemePSekunde, vrijemePMilisekunde,
					vrijemeKSati, vrijemeKMinute, vrijemeKSekunde, vrijemeKMilisekunde);	
				
				//Druga faza promjene formata datoteke			
				if(format == "srt")
				{
					exportFile<<redniBroj<<"\n"<<
						setfill('0')<<setw(2)<<vrijemePSati<<":"<<setfill('0')<<setw(2)<<vrijemePMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemePSekunde<<","<<setfill('0')<<setw(3)<<vrijemePMilisekunde<<" --> "<<
						setfill('0')<<setw(2)<<vrijemeKSati<<":"<<setfill('0')<<setw(2)<<vrijemeKMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemeKSekunde<<","<<setfill('0')<<setw(3)<<vrijemeKMilisekunde<<"\n"<<
						tekstTitla<<"\n\n";					
				}
				else if(format == "rt")
				{
					exportFile<<"<Time begin=\""<<
						setfill('0')<<setw(1)<<vrijemePSati<<":"<<setfill('0')<<setw(2)<<vrijemePMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemePSekunde<<"."<<setfill('0')<<setw(1)<<vrijemePMilisekunde<<"\" end=\""<<
						setfill('0')<<setw(1)<<vrijemeKSati<<":"<<setfill('0')<<setw(2)<<vrijemeKMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemeKSekunde<<"."<<setfill('0')<<setw(1)<<vrijemeKMilisekunde<<"\" /><clear/>"<<
						tekstTitla<<"\n";						
				}
				else if(format == "sub")
				{
					exportFile<<"\n{T "<<
						setfill('0')<<setw(2)<<vrijemePSati<<":"<<setfill('0')<<setw(2)<<vrijemePMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemePSekunde<<":"<<setfill('0')<<setw(2)<<vrijemePMilisekunde<<"\n"<<
						tekstTitla<<"\n}\n{T "<<						
						setfill('0')<<setw(2)<<vrijemeKSati<<":"<<setfill('0')<<setw(2)<<vrijemeKMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemeKSekunde<<":"<<setfill('0')<<setw(2)<<vrijemeKMilisekunde<<"\n\n}";				
				}
				else if(format == "ssa")
				{
					exportFile<<"\nDialogue: Marked=0,"<<setfill('0')<<setw(1)<<vrijemePSati<<":"<<setfill('0')<<setw(2)<<vrijemePMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemePSekunde<<"."<<setfill('0')<<setw(2)<<vrijemePMilisekunde<<","<<
						setfill('0')<<setw(1)<<vrijemeKSati<<":"<<setfill('0')<<setw(2)<<vrijemeKMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemeKSekunde<<"."<<setfill('0')<<setw(2)<<vrijemeKMilisekunde<<",Default,NTP,0000,0000,0000,!Effect,"<<
						tekstTitla;
				}
				else if(format == "ass")
				{
					exportFile<<"\nDialogue: 0,"<<setfill('0')<<setw(1)<<vrijemePSati<<":"<<setfill('0')<<setw(2)<<vrijemePMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemePSekunde<<"."<<setfill('0')<<setw(2)<<vrijemePMilisekunde<<","<<
						setfill('0')<<setw(1)<<vrijemeKSati<<":"<<setfill('0')<<setw(2)<<vrijemeKMinute<<":"<<
						setfill('0')<<setw(2)<<vrijemeKSekunde<<"."<<setfill('0')<<setw(2)<<vrijemeKMilisekunde<<",Default,,0,0,0,,"<<
						tekstTitla;	
				}

						
				redniBroj++;
				brojac=0;
			}
		}
		
		// Treæa faza izmjene formata datoteke
		// Zatvaranje specifièno za pojedini tip titla
		if(format == "srt")
		{
			//ništa specifièno
		}
		else if(format == "rt")
		{
			exportFile<<"</b>\n</center>";		
		}
		else if(format == "sub")
		{
				//ništa specifièno		
		}
		else if(format == "ssa")
		{
			//ništa specifièno
		}
		else if(format == "ass")
		{
			//ništa specifièno	
		}
		
		system("cls");
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"                         ***  Promjena formata titlova  ***\n"<<endl;
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"Datoteka "<<naziv<<" je uspješno eksportirana!"<<endl;

	exportFile.close();
	myfile.close();
	}
	else
	{
		system("cls");
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"                         ***  Promjena formata titlova  ***\n"<<endl;
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"Datoteku nije moguæe otvoriti."<<endl; 
		system("pause");
		meni();
	}
}

// Ispis putanje prilagoðene pretraživanju
string titl::urediPutanju(string path)
{
	string s=path;
	replace( s.begin(), s.end(), '\\', '/');
	return s;
}

// Ispis ureðene putanje direktorija gdje se pohranjuju titlovi
string titl::vratiPutanjuGlavnogDirektorija()
{
    CHAR my_documents[MAX_PATH];
    HRESULT result=SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
    if(result!=S_OK)
        cout<<"Došlo je do pogreške: "<<result<<"\n";
    else
        return urediPutanju(my_documents);
}

// Ispis ekstenzije datoteke
string titl::vratiEkstenzijuDatoteke(const string& str)
{
	size_t found = str.find_last_of(".");
	return str.substr(found+1);
}

// Ispis sadržaja direktorija s obzirom na odabranu ekstenziju
bool titl::ispisiSadrzajDirektorija(string ekstenzija)
{
	DIR *dir;
	struct dirent *ent;
	bool postojeDatoteke = false;
	string putanja=urediPutanju(vratiPutanjuGlavnogDirektorija());
	const char *c =putanja.c_str();
	if ((dir=opendir(c)) != NULL)
	{
		while((ent=readdir(dir)) != NULL)
		{
			if(vratiEkstenzijuDatoteke(ent->d_name) == ekstenzija){
				cout<<"  *  "<<ent->d_name<<endl;
				postojeDatoteke=true;
			}
		}
		closedir(dir);
	}
	else
	{
		perror("");
		cout<<"Došlo je do pogreške.";
	}
	return postojeDatoteke;	
}

//Ispis svih podržanih formata datoteka iz glavnog direktorija
bool titl::ispisiSvePodrzaneDatoteke()
{
	DIR *dir;
	struct dirent *ent;
	bool postojeDatoteke = false;
	string putanja=urediPutanju(vratiPutanjuGlavnogDirektorija());
	const char *c =putanja.c_str();
	if ((dir=opendir(c)) != NULL)
	{
		while((ent=readdir(dir)) != NULL)
		{
			if(vratiEkstenzijuDatoteke(ent->d_name) == "ass" ||
				vratiEkstenzijuDatoteke(ent->d_name) == "srt" ||
				vratiEkstenzijuDatoteke(ent->d_name) == "rt" ||
				vratiEkstenzijuDatoteke(ent->d_name) == "sub" ||
				vratiEkstenzijuDatoteke(ent->d_name) == "ssa")
			{
				cout<<"  *  "<<ent->d_name<<endl;
				postojeDatoteke = true;
			}
		}
		closedir(dir);
	}
	else
	{
		perror("");
		cout<<"Došlo je do pogreške.";
	}
	return postojeDatoteke;
}

// Ispis svih linija koje su zapisane u nekoj datoteci
void titl::ispisiIzDatoteke(string naziv)
{
	string line;
	ifstream myfile(naziv.c_str());	
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			cout<<line<<'\n';
		}
	myfile.close();
	}
	else cout<<"Nije moguæe otvoriti tu datoteku."<<endl; 
}

// Metoda za promjenu formata odabrane datoteke
void titl::promjeniFormatDatoteke()
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                         ***  Promjena formata titlova  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n";
	cout<<"Lista dostupnih titlova:\n"<<endl;
	if(ispisiSadrzajDirektorija("titl")){
		cout<<"\nOdaberite titl koji želite eksportirati:"<<endl;
	}
	else
	{
		cout<<"Nema dostupnih titlova."<<endl;
		system("pause");
		return;
	}
	bool izlaz=false;
	string naziv="";
	short broj;
	cin>>naziv;
	do{
		cout<<"\nPodržani formati su:\n   (1) .srt\n   (2) .sub\n   (3) .rt\n   (4) .ass\n   (5) .ssa"<<endl;
		cout<<"Unesite broj željenog formata titlova ili unesite nulu (0) za izlaz:"<<endl;
		cin>>broj;
		if(broj==1)
		{
			eksportirajTitl(naziv, "srt");
		}
		else if(broj==2)
		{
			eksportirajTitl(naziv, "sub");
		}
		else if(broj==3)
		{
			eksportirajTitl(naziv, "rt");	
		}
		else if(broj==4)
		{
			eksportirajTitl(naziv, "ass");	
		}
		else if(broj==5)
		{
			eksportirajTitl(naziv, "ssa");
		}
		else if(broj==0)
		{
			break;
		}
		else
		{
			system("cls");
			cout<<"________________________________________________________________________________\n"<<endl;
			cout<<"                         ***  Promjena formata titlova  ***\n"<<endl;
			cout<<"________________________________________________________________________________\n";			
			cout<<"Pogrešan unos."<<endl;
			izlaz=true;
			system("pause");
			break;
		}
	}while(broj!=0 || izlaz!=true);
	cin.ignore();
	meni();
}


void titl::izmjeniTitl(string naziv)
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                            ***  "<<naziv<<"  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	string line;
	ifstream myfile (naziv.c_str());
	
	if(myfile.is_open())
	{
		Red r;
		string tekstTitla = "";
		string pocetakVrijeme = "";
		string krajVrijeme = "";
		
		elementtype vrijemePSati = 0;
		elementtype vrijemePMinute = 0;
		elementtype vrijemePSekunde = 0;
		elementtype vrijemePMilisekunde = 0;
		
		elementtype vrijemeKSati = 0;
		elementtype vrijemeKMinute = 0;
		elementtype vrijemeKSekunde = 0;
		elementtype vrijemeKMilisekunde = 0;
		
		int brojac = 0;		// broj argumenta
		int redniBroj = 1;	// redni broj titla
		
		while(getline(myfile,line, ';')) //èitanje argument po argument
		{
			brojac++;
			//cout<<"Redni broj: "<<redniBroj<<" - Brojac: "<<brojac<<" Linija: "<<line<<"\n";
			if(brojac==1)
				vrijemePSati = atoi(line.c_str());			
			else if(brojac==2)
				vrijemePMinute = atoi(line.c_str());
			else if(brojac==3)
				vrijemePSekunde = atoi(line.c_str());
			else if(brojac==4)
				vrijemePMilisekunde = atoi(line.c_str());
			else if(brojac==5)
				vrijemeKSati = atoi(line.c_str());
			else if(brojac==6)
				vrijemeKMinute = atoi(line.c_str());
			else if(brojac==7)
				vrijemeKSekunde = atoi(line.c_str());
			else if(brojac==8)
				vrijemeKMilisekunde = atoi(line.c_str());
			else if(brojac==9)
			{
				tekstTitla = line;
				r.EnqueueQ(tekstTitla, vrijemePSati, vrijemePMinute, vrijemePSekunde, vrijemePMilisekunde, vrijemeKSati, vrijemeKMinute, vrijemeKSekunde, vrijemeKMilisekunde);						
				redniBroj++;
				brojac=0;
			}
		}
		r.IspisiTitlDatoteku(true);
		myfile.close();
		
		int linija = 0;
		cout<<"Koju liniju titla želite izmjeniti?"<<endl;
		cin>>linija;
		cin.ignore();
		cout<<"Unesite tekst "<<linija<<". titla:"<<endl;
		getline(cin,tekstTitla);
		cout<<"Unesite vrijeme poèetka prikaza "<<linija<<". titla (HH:MM:SS,MSS)"<<endl;
		cin>>pocetakVrijeme;
		cout<<"Unesite vrijeme poèetka prikaza "<<linija<<". titla (HH:MM:SS,MSS)"<<endl;
		cin>>krajVrijeme;
		
		r.ChangeQ(naziv, linija, tekstTitla, pocetakVrijeme, krajVrijeme);
	}
	else
		cout<<"Datoteku nije moguæe otvoriti."<<endl;
		
	return;
}

// Metoda za ispravak odabranog titla
void titl::ispraviTitlove()
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                           ***  Ispravak titlova  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	
	cout<<"Lista kreiranih titlova:\n"<<endl;
	if(ispisiSadrzajDirektorija("titl")){
		cout<<"\nOdaberite titl koji želite izmjeniti:"<<endl;
	}
	else
		cout<<"Nema dostupnih titlova."<<endl;
	
	string naziv="";
	cin>>naziv;
	
	izmjeniTitl(naziv);
	cin.ignore();
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                           ***  Ispravak titlova  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"Datoteka je uspješno izmjenjena!";
	cout<<"\n================================================================================\n";
	system("pause");
	meni();
}

// Metoda za pregled podržanih titlova
void titl::pregledajTitlove()
{
	system("cls");
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"                            ***  Pregled titlova  ***\n"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"Popis podržanih titlova:\n"<<endl;
	if(ispisiSvePodrzaneDatoteke()){
		string naziv = "";
		cout<<"\nUnesite naziv titla kojeg želite pregledati: "<<endl;
		cin>>naziv;
		cin.ignore();
		system("cls");
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"                            ***  "<<naziv<<"  ***\n"<<endl;
		cout<<"________________________________________________________________________________\n"<<endl;
		cout<<"\n\n";
		ispisiIzDatoteke(naziv);
	}
	else{
		cout<<"Nema pronaðenih datoteka."<<endl;
	}
	
	
	cout<<"\n================================================================================\n";
	system("pause");
	meni();
}

// Metoda za glavni izbornik
void titl::meni()
{
	system("cls");
	cout<<"\n================================================================================"<<endl;
	cout<<"                            ***  GLAVNI MENI  ***\n\n";
	cout<<"================================================================================\n"<<endl;
	cout<<"\t\t(1)  Kreiranje datoteke sa titlovima \t\t"<<endl;
	cout<<"\t\t(2)  Promjena formata titlova \t\t\t"<<endl;
	cout<<"\t\t(3)  Ispravke titlova \t\t\t\t"<<endl;
	cout<<"\t\t(4)  Pregled titlova \t\t\t\t"<<endl;
	cout<<"\t\t(5)  O programu \t\t\t\t\t"<<endl;
	cout<<"\t\t(6)  Izlaz \t\t\t\t"<<endl;
	cout<<"\n________________________________________________________________________________"<<endl;
	cout<<"________________________________________________________________________________\n"<<endl;
	cout<<"\t\tOdaberite opciju menija: ";
		
	bool odabir=false;
	string izbor = "";
	do
	{
		cin>>izbor;
		if(izbor=="1")
			kreirajNovuDatoteku();			
		else if(izbor=="2")
			promjeniFormatDatoteke();
		else if(izbor=="3")
			ispraviTitlove();
		else if(izbor=="4")
			pregledajTitlove();
		else if(izbor=="5")
			oProgramu();
		else if(izbor=="6")
			break;
		else{
			cout<<"\t\tPogrešan unos. Odaberite broj izmeðu 1-6\n\t\t";
			system("pause");
			meni();
		}
	}while(odabir != false);
}
