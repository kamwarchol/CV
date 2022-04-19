#include <iostream>
using namespace std;


class knight{
	private:
		int health;
		int strenght;
		string name;
	public:
		knight(){
			health= 2;
			strenght = 1;
			name = "TEST";
		}
		knight(int h, int s, string n): health(h), strenght(s), name(n){ }
		void sayHi(){ cout<<"Hi I'am "<< name << " my health is " << health<<"\n";} //nothing exciting yet
		//a friend function "fight". "&" denotes passing arguments as areference
		friend void fight(knight& k1, knight& k2);

		void Set_health(int);
		void Set_strenght(int);
		void Set_name(string);
		int Get_health();
		int Get_strenght();
		string Get_name();
};

void knight::Set_health(int _health){
health= _health;
}
void knight::Set_strenght(int _strenght ){
strenght = _strenght;
}
void knight::Set_name(string _name){
name = _name;
}
int knight::Get_health(){
return health;
}
int knight::Get_strenght(){
return strenght;
}
string knight::Get_name(){
return name;
}




void fight(knight& k1, knight& k2){
		int hit1, hit2;
		cout<<endl<<"wobodobodoo!"<<endl;
		hit1 = rand() % k1.strenght;
		hit2 = rand() % k2.strenght;
		k1.health = k1.health - hit2;
		k2.health = k2.health - hit1;
	}


int main(){

	knight orks[5] ={
			knight ( 100,100, "Lech Kaczynski"),
			knight ( 100,100, "Edward Gierek"),
			knight (100,100, "Mieszko I"),
			knight ( 100,100,"Boleslaw Chrobry"),
			knight ( 100,100, "Kazimierz Wielki")
	};
	knight dwarfs[5] ={
			knight ( 100,100, "Jadwiga"),
			knight ( 100,100, "Bona"),
			knight (100,100, "Agata Duda"),
			knight ( 100,100,"Anna Jagielonga"),
			knight ( 100,100, "Danuta Walesa")
	};
	srand (time(NULL));

	knight *elfs;
		elfs = new knight[8];
		elfs[1].Set_name("Andrzej Duda");
		elfs[1].Set_health(100);
		elfs[1].Set_strenght(10);

		elfs[2].Set_name("Kamil Warchol");
		elfs[2].Set_health(100);
		elfs[2].Set_strenght(99);
		fight(elfs[1],elfs[2]);
		elfs[1].sayHi(); elfs[2].sayHi();



  for(int i=0; i<sizeof(dwarfs); i++){
	  fight(dwarfs[i],orks[i]);
	  dwarfs[i].sayHi(); 
    orks[i].sayHi();
  } 
return 0;
}
