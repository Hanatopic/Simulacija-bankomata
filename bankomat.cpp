#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
class Bankomat {
private:
	string brojRacuna;
	string imeVlasnika;
	double stanjeRacuna;
	vector <string> historijaTransakcija;
public:
	string formatiranjeBrojeva(double stanje)const {
		stringstream ss;
		ss << fixed << setprecision(2) << stanje;
		return ss.str();
	}
	Bankomat(string brRacuna, string imeVl, double stanjeR) :brojRacuna(brRacuna), imeVlasnika(imeVl), stanjeRacuna(stanjeR) {
		historijaTransakcija.push_back("Racun otvoren sa pocetnim stanjem: " + formatiranjeBrojeva(stanjeR) + "KM");
	}
	void Uplati(double iznos) {
		if (iznos<=0)
		{
			cout << "Iznos uplate mora biti veci od 0!"<<endl;
		}
		else
		{
			stanjeRacuna += iznos;
			historijaTransakcija.push_back("Uplata: +" + formatiranjeBrojeva(iznos) + "KM");
			cout << "Uspjesno ste uplatili:"<<iznos<<"KM."<<endl;
		}
	}
	void Isplati(double iznos) {
		if (iznos<=0)
		{
			cout << "Neispravan iznos za isplatu!\n";
		}
		else if (iznos>stanjeRacuna)
		{
			cout << "Nedovoljno sredstava na racunu!\n";
		}
		else
		{
			stanjeRacuna -= iznos;
			historijaTransakcija.push_back("Isplata: -" + formatiranjeBrojeva(iznos) + "KM");
			cout << "Uspjesno ste podigli:" << iznos << "KM.\n";
		}
	}
	void prikazStanjaRacuna() const {
		cout << "----------------------------\n";
		cout << "Korisnik: " << imeVlasnika << endl;
		cout << "Broj racuna: " << brojRacuna << endl;
		cout << "Trenutno stanje racuna: " << fixed<<setprecision(2)<< stanjeRacuna<<"KM" << endl;
		cout << "----------------------------\n";
	}
	void historijaTransak() const {
		cout << "---Historija transakcija---\n";
		for (int i = 0; i < historijaTransakcija.size(); i++)
		{
			cout << "-" << historijaTransakcija[i] << endl;
		}
		cout << "----------------------------\n";
	}
};
int main()
{
	Bankomat IvinRacun("BA987654321", "Ivo Andric", 1250.20);
	int izbor;
	double iznos;
	do
	{
		cout << "------BANKOMAT------" << endl;
		cout << "1.Provjera stanja racuna" << endl;
		cout << "2.Uplata novca na racun" << endl;
		cout << "3.Isplata novca na racun" << endl;
		cout << "4.Historija transakcija" << endl;
		cout << "5.Izlaz" << endl;
		cout << "Izaberite opciju (1-5):" << endl;
		cin>> izbor;
		switch (izbor)
		{		
		case 1:
			IvinRacun.prikazStanjaRacuna();
			break;
		case 2:
			cout << "Unesite iznos za uplatu (KM):" << endl;
			cin >> iznos;
			IvinRacun.Uplati(iznos);
			break;
		case 3:
			cout << "Unesite iznos za isplatu (KM):" << endl;
			cin >> iznos;
			IvinRacun.Isplati(iznos);
			break;
		case 4:
			IvinRacun.historijaTransak();
			break;
		case 5:
			cout << "Hvala sto ste koristili bankomat!" << endl;
			break;
		default:
			cout << "Nevazeca opcija! Pokusajte ponovo." << endl;
			break;
		}
	} while (izbor!=5);
	std::cin.get();
	return 0;
}


