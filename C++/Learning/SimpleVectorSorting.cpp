#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector <int> tab;

int main(){
	srand(time(NULL));
	int rozmiar = 7;
	for (int i = 1; i<=rozmiar; i++){
		tab.push_back(rand()%15);

	}
	cout << "Nieposortowane: " << endl;
	for(int j=0; j<tab.size(); j++){
			cout<<tab[j]<<' ';
	}
	cout << endl;

	sort(tab.begin(), tab.end());
	cout << "Posortowane: " << endl;
		for(int k=0; k<tab.size(); k++){
				cout<<tab[k]<<' ';
	}
return 0;
}
