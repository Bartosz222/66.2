#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
public class Trojki {
public:
	ifstream wejscie;
	const int SIZE = 1000;
	string wynik;
	vector<string>Liczby;
	Trojki(string path) {
		wejscie.open(path);
	}
	~Trojki() {
		wejscie.close();
	}
	void wczytaj() {
		int a, b, c;
		for (int i = 0; i < SIZE; i++) {
			wejscie >> a >> b >> c;
			if (CzyPierwsza(a) && CzyPierwsza(b) && a * b == c) sumowanie(a, b, c);
		}
	}
	bool CzyPierwsza(int liczba) {
		if (liczba <= 1) return false;
		if (liczba % 2 == 0 && liczba != 2) return false;
		for (int i = 3; i * i <= liczba; i += 2) {
			if (liczba % i == 0) return false;
		}
		return true;
	}
	void sumowanie(int a, int b, int c) {
		string x, y, z;
		x = to_string(a);
		y = to_string(b);
		z = to_string(c);
		wynik = x + ", " + y + ", " + z;
		Liczby.push_back(wynik);
	}
	string wypisz() {
		string zapis;
		int max = Liczby.size();
		for (int i = 0; i < max; i++) {
			zapis += Liczby[i] + "\n";
		}
		return zapis;
	}
	void usun() {
		Liczby.clear();
	}
};