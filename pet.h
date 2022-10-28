#include <pthread.h>
#ifndef __pet_H__
#define __pet_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "time.h"


using namespace std;

class Animal {
  private:
    string Name; //obtener nombre
    int age; //obtener edad 
    int hunger;
    int maxHunger;
    int health;
    int maxHealth;
    int attention;
    int maxStatus;
    int petT;
    string filename;
    string fileFeed;
    string fileFood;
    string fileAttention;
    string fileExit;
    
public:
  Animal();
  Animal(int, string);
  void setName(string Name) { this -> Name = Name; }
  string getName() { return Name; }

  void setAge(int age) {  this -> age = age; return; } 
  int getAge() { return age; } //obtener edad

	void setFilename(string filename) { this->filename = filename; return;}
	void setfileFeed(string fileFeed) { this->fileFeed = fileFeed; }
	void setfileFood(string fileFood) { this->fileFood = fileFood; }
	void setfileAttention(string fileAttention) { this->fileAttention = fileAttention; }
	void setfileExit(string fileExit) { this->fileExit = fileExit; }

  void MostrartxtPet();
  void PrintFeed();
  void PrintFood();
  void PrintAttention();
  void RIP();
  void exit();
  bool Alive();
  void lowStatus();
  void next_Day();

  int getHunger() { return hunger;}
  int getHealth() { return health; }
  int getFun() { return attention; }
  int getMaxStatus() { return maxStatus; }

  void setHunger(int x) {
    if (x <= 20)  hunger = x;
    return;
  } 
  void setHealth(int x) {
    if (x <= maxStatus)  health = x;
    return;
  }
  void setFun(int x) {
    if (x <= maxStatus)  attention = x;
    return;
  }

  void feedPet();
  void playPet();
  void agePet(); //agregar la funcion 
  void status();
  void adoptPet();
  void menuDisplay();
  void menuFeed();
};

Animal::Animal() {
  Name = "";
  age = 0; //empezar desde 0
  hunger = 10;
  health= 10;
  attention = 10;
  maxStatus = 20;
}

Animal::Animal(int edad, string nombre) {
  age = edad;
  Name = nombre;
}

void Animal::MostrartxtPet() {
  vector<string> renglon;
	char line[256];
	ifstream archivo(this->filename);
	while (archivo.getline(line, 256)) {
		renglon.push_back(line);
	}
	for (const auto& i:renglon)
		cout<<i<< endl;
	archivo.close();  
} 
void Animal::PrintFeed() { 
  ifstream archivo(this->fileFeed);
    string texto;
    archivo.open(fileFeed, ios::in);  
    if(archivo.fail()){ cout<<"El archivo no se puede abrir"<<endl; } //exception
    while (!archivo.eof()){ 
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close(); 
} 
void Animal::PrintFood() { 
  vector<string> renglon;
	char line[256];
	ifstream archivo(this->fileFood);
	while (archivo.getline(line, 256)) {
		renglon.push_back(line);
	}
	for (const auto& i:renglon)
		cout<<i<< endl;
	archivo.close(); 
} 
void Animal::PrintAttention() { 
  vector<string> renglon;
	char line[256];
	ifstream archivo(this->fileAttention);
	while (archivo.getline(line, 256)) {
		renglon.push_back(line);
	}
	for (const auto& i:renglon)
		cout<<i<< endl;
	archivo.close(); 
} 
void Animal::RIP() {
  string x= "RIP.txt";
  ifstream archivo(x);
    string texto;
    archivo.open(fileFeed, ios::in);  
    if(archivo.fail()){ cout<<"El archivo no se puede abrir"<<endl; }
    while (!archivo.eof()){ 
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
} 
void Animal::exit() {
  ifstream archivo("exit.txt");
    string texto;
    archivo.open(fileFeed, ios::in);  
    if(archivo.fail()){ cout<<"El archivo no se puede abrir"<<endl; }
    while (!archivo.eof()){ 
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
} 

void Animal::status(){
  cout<<endl;
  cout<<"-| Age: "<<age<<endl;
  cout<<"-| Hunger: "<<hunger<<"/20"<<endl;
  cout<<"-| Health: "<<health<<"/20"<<endl;
  cout<<"-| Fun: "<<attention<<"/20"<<endl;
}
void Animal::adoptPet(){ 
  cout << "Insert the number of the pet you'd like to adopt: " << endl;
  cout << "[1] Cat \n[2] Dog \n[3] Rock" << endl;
}
void Animal::feedPet(){
  if(hunger>=maxStatus){
    hunger = maxStatus; 
    cout<<"╔═.♥.════════════════╗"<<endl;
    cout<<"  "<<this->Name<<" is full"<<endl;
    cout<<"╚════════════════.♥.═╝"<<endl;
  } else if (hunger < maxStatus && hunger > 0){
    cout<<"╔═.♥.══════════════════════╗"<<endl;
    cout<<"  "<<this->Name<<" has been fed"<<endl;
    cout<<"╚══════════════════════.♥.═╝";

  } else {
    cout<<"not possible to feed pet"<<endl;
  }
}
void Animal::playPet(){
  attention +=1;
  hunger -=1;
  if(attention>=maxStatus){
    attention = maxStatus;
    cout<<"\n╔. ■ .═══════════════════════════════════════╗"<<endl;
    cout<<"   "<<this->Name<<" is tired, come play later. "<<endl;
    cout<<"╚══════════════════════════════════════. ■ .═╝";

  } else if (attention < maxStatus && attention > 0){
    cout<<"╔. ■ .════════════════════════════╗"<<endl;
    cout<<"   "<<this->Name<<" is happy to play."<<endl;
    cout<<"╚═══════════════════════════. ■ .═╝";
  } else {
    cout<<this-> Name<< " has died"<<endl;
  }
}

void Animal::lowStatus(){
    if(getHunger()<=3) cout <<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" << "\n[ Carefull, " << this->Name << " is hungry! ] \n[ Feed pet before it starves]"<<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" <<endl;
    if(getHealth()<=3) cout <<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" <<  "\n[ Carefull, " << this->Name << " is low on health! ] \n[ Feed medicine before it dies  ]"<<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" <<endl;
    if(getFun()<=3) cout <<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" <<  "\n[ Carefull, " << this->Name << " is bored! ] \n[ Play with pet before it dies of boredom ]"<<"\n◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤◢◤" <<endl;
}
bool Animal::Alive(){
  if(attention<=0 || hunger <=0 || health<=0 ){ return 0;}
  else return 1;
} 

void Animal::menuDisplay(){
  cout << "\n--------------- | Menu | ---------------" << endl;
  cout << "Choose one of the following options: " << endl;
  cout << " [1] Feed " << Name << endl;
  cout << " [2] Play with " << Name << endl;
  cout << " [3] Check " << Name << "'s Status"<< endl;
  cout << " [4] Exit Game\n" << endl;
} 
void Animal::menuFeed(){
  cout<<"---------------| Feed Pet |---------------"<<endl;
  cout<<"\t-> Choose one of the follwoing options to feed pet <-"<<endl;
  cout<<"\t-> (1) Treats"<<endl;
  cout<<"\t-> (2) Kibbles"<<endl;
  cout<<"\t-> (3) Ice cream [- health]"<<endl;
  cout<<"\t-> (4) Medicin [+ health]"<<endl;
  int x; cin>>x; 

  switch(x){
    case 1: 
      cout<<"ˏˋ°•*⁀➷ ["<<Name<<" loved the treats]\n"<<endl; 
      hunger += 1;
      
      break;
    case 2: 
      cout<<"ˏˋ°•*⁀➷ ["<<Name<<" loved the kibbles]\n"<<endl; 
       hunger += 2;

      break;
    case 3:
      cout<<"ˏˋ°•*⁀➷ ["<<Name<<" loved the desert]\n"<<endl; 
      hunger += 1;
      health -=1;
      break;
    case 4:
      cout<<"ˏˋ°•*⁀➷ ["<<Name<<" thought the medicin tasted bitter]\n"<<endl; 
      health +=1;
      break;
  }
      cout<<"--------------------------------------------"<<endl;

}

void Animal::next_Day(){
  srand(time(0));
	setAge(getAge() + 1); //increment age
	setHunger(getHunger() - (rand() % 3)-1 ); 
	setHealth(getHealth() - (rand() % 1)-1 ); 
  setFun(getFun() - (rand() % 3)-1 ); 
} 

#endif 
