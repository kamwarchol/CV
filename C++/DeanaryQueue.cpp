#include <iostream>
#include <queue>

using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}


int main(){
	queue<int> rok1,rok2,rok3,rok4,rok5;

	int warunek = 1;
	while  (warunek == 1){
	int akcja;
	cout << endl << endl;
	cout << "Kolejka dla roku 1 - Wcisnij 1" << endl;
	cout << "Kolejka dla roku 2 - Wcisnij 2" << endl;
	cout << "Kolejka dla roku 3 - Wcisnij 3" << endl;
	cout << "Kolejka dla roku 4 - Wcisnij 4" << endl;
	cout << "Kolejka dla roku 5 - Wcisnij 5" << endl;
	cout << "Osoba weszla rok 1 - Wcisnij 6" << endl;
	cout << "Osoba weszla rok 2 - Wcisnij 7" << endl;
	cout << "Osoba weszla rok 3 - Wcisnij 8" << endl;
	cout << "Osoba weszla rok 4 - wcisnij 9" << endl;
	cout << "Osoba weszla rok 5 - wcisnik 10" << endl;
	cout << "Co chcesz zrobic? " << endl;


	cin >> akcja;
	switch (akcja){
	case 1:
		rok1.push(akcja);
		showq(rok1);
		cout << "Zapisano do kolejki dla roku 1"<< endl;
		cout << "Ilosc osob w kolejce dla tego roku: " << rok1.size()<<endl;
	break;
	case 2:
		rok2.push(akcja);
		showq(rok2);
		cout << "Zapisano do kolejki dla roku 2"<< endl;
		cout << "Ilosc osob w kolejce dla tego roku: " << rok2.size()<<endl;
	break;

	case 3:
		rok3.push(akcja);
		showq(rok3);
		cout << "Zapisano do kolejki dla roku 3"<< endl;
		cout << "Ilosc osob w kolejce dla tego roku: " << rok3.size()<<endl;
	break;
	case 4:
		rok4.push(akcja);
		showq(rok4);
		cout << "Zapisano do kolejki dla roku 4"<< endl;
		cout << "Ilosc osob w kolejce dla tego roku: " << rok4.size()<<endl;
	break;
	case 5:
		rok5.push(akcja);
		showq(rok5);
		cout << "Zapisano do kolejki dla roku 5"<< endl;
		cout << "Ilosc osob w kolejce dla tego roku: " << rok5.size()<<endl;
	break;
	case 6:
		rok1.pop();
		showq(rok1);
		cout << "Zapraszamy osobe z roku 1 "<< endl;
		cout << "Pozostala ilosc osob w kolejce dla roku 1 : " << rok1.size() << endl;

	break;
	case 7:
		rok2.pop();
		showq(rok2);
		cout << "Zapraszamy osobe z roku 2 "<< endl;
		cout << "Pozostala ilosc osob w kolejce dla roku2 : " << rok2.size() << endl;
	break;
	case 8:
		rok3.pop();
		showq(rok3);
		cout << "Zapraszamy osobe z roku 3 "<< endl;
		cout << "Pozostala ilosc osob w kolejce dla roku 3 : " << rok3.size() << endl;
	break;
	case 9:
		rok4.pop();
		showq(rok4);
		cout << "Zapraszamy osobe z roku 4 "<< endl;
		cout << "Pozostala ilosc osob w kolejce dla roku 4: " << rok4.size() << endl;
	break;
	case 10:
		rok5.pop();
		showq(rok5);
		cout << "Zapraszamy osobe z roku 5 "<< endl;
		cout << "Pozostala ilosc osob w kolejce dla roku 5: " << rok5.size() << endl;
	break;
	case 100:
		warunek = 0;
	break;
	default:
		cout << "Niepoprawny znak" << endl;
	break;
	}

	}
return 0;
}
