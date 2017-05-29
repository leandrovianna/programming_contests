#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

#define N 8

class Deck {
	list<int> cards;
	bool lockSort; 

	public:
		Deck() {
			lockSort = false;
		};
		void insertCard(int x);
		int getGreater();
		int getLowest();
		int playGreater();
		int playLowest();
		int playBest(int minimum); //sufficient to win or draw
		void clear();
};

void Deck::insertCard(int x) {
	this->cards.push_back(x);
}

void Deck::clear() {
	this->cards.clear();
}

int Deck::getGreater() {
	list<int>::iterator it = max_element(this->cards.begin(), this->cards.end());
	return *it;
}

int Deck::getLowest() {
	list<int>::iterator it = min_element(this->cards.begin(), this->cards.end());
	return *it;
}

int Deck::playGreater() {
	list<int>::iterator it = max_element(this->cards.begin(), this->cards.end());
	int x = *it;
	this->cards.erase(it);
	return x;
}

int Deck::playLowest() {
	list<int>::iterator it = min_element(this->cards.begin(), this->cards.end());
	int x = *it;
	this->cards.erase(it);
	return x;
}

int Deck::playBest(int minimum) {
	if (!lockSort) {
		this->cards.sort();
		lockSort = false;
	}

	list<int>::iterator x;
	for (list<int>::iterator it = this->cards.begin(); it != this->cards.end(); it++) {
		if (*it == minimum) x = it;
		else if (*it > minimum) {
			x = it;
			break;
		}
	}

	this->cards.erase(x);
	return *x;
}

int main() {
	int t, n, x;
	int a, b;
	string res;
	int scoreJ, scoreM;
	Deck deckJ, deckM;

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			deckJ.insertCard(x);
		}

		for (int i = 0; i < n; i++) {
			cin >> x;
			deckM.insertCard(x);
		}
	
		scoreJ = scoreM = 0;
		
		// n rodadas
		for (int i = 0; i < n; i++) {

			// Joao tem a maior carta, entao ele joga
			// Maria joga sua pior entao
			if (deckJ.getGreater() > deckM.getGreater()) {
				deckJ.playGreater();
				deckM.playLowest();
				scoreJ++;
			} else {
				//Joao nao tem a maior carta,
				//entao ele joga sua pior
				a = deckJ.playLowest();

				//Maria, para vencer, deve jogar uma carta suficiente
				b = deckM.playBest(a);
				
				// Maria pode ter uma carta igual a de Joao
				// como unica suficiente, nesse caso deve-se computar
				// como empate
				if (b > a) scoreM++;
			}
		}

		deckJ.clear();
		deckM.clear();

		if (scoreJ < scoreM)
			res = "Maria";
		else if (scoreJ > scoreM)
			res = "Joao";
		else
			res = "Empate";

		cout << "Caso " << ti << ": " << res << endl;
	}

	return 0;
}
