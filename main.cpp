#include <iostream>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <chrono>
#include <unistd.h>

#include "pet.h"
#include "Gato.h"
#include "Perro.h"
#include "Rock.h"

using namespace std;

Animal *vPet = NULL;
int edad = 0;
class Animal tama;

void clrscr(){
  cout<<"\033[2J\033[1;1H";
}

void pixelArt(string nombre){
    ifstream archivo;
    string texto;  
    archivo.open(nombre, ios::in); // el "in" es porque vas a leer un archivo
    if(archivo.fail()){
        cout<<"El archivo no se puede abrir"<<endl;
    }
    while (!archivo.eof()){ //mientras la condicion se cumpla, vamos a leer directamente
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}

void *age_function(void *args){
    for(;;){ 
      this_thread::sleep_for (chrono::seconds(10));
      tama.next_Day();
      cout<<"╰┈➤ "<<tama.getName()<<" has aged a day"<<endl;
      
      bool Vivo = tama.Alive();
      if(!Vivo){ // If dead
          clrscr(); pixelArt("RIP.txt");
          if(tama.getFun()<=0){ cout << "R.I.P. Your Pet died of boredom"<<endl; }
          else if(tama.getHealth()<=0) {cout << "R.I.P. Your Pet died of sickness"<<endl;}
          else if(tama.getHunger()<=0) {cout << "R.I.P. Your Pet died of hunger"<<endl;}
          else cout << "R.I.P. Your Pet died"<<endl;
          cout << tama.getName() <<" lived "<<tama.getAge() <<" days"<<endl;
          cout << "Better luck next time!"<<endl;  
          string x;
          getline(cin,x);
    			return 0;
          break;
    	}
    }

} 

pthread_t thread1;

int main() {
  try{
  int petT,x;
  string petName;
  tama.adoptPet();

  cin >>petT;
  string s;
 
  cout << endl;

    if (petT == 1) {
        cout << "Congratulations, you've adopted a cat!\n" << endl;
        vPet = new vCat(); 
    } else if (petT == 2) {
        cout << "Congratulations, you've adopted a dog!\n" << endl;
        vPet = new vDog();
    } else {
        cout << "Congratulations, you've adopted a rock!\n" << endl;
        vPet = new vRock();
    }
    getline(cin,s);
  cout << "What would you like to name your pet?" << endl;
    getline(cin,petName);

  tama.setName(petName);  
  vPet->MostrartxtPet();
  tama.menuDisplay();

  pthread_create( &thread1, NULL, &age_function, NULL);

    do { 
         bool vivo = tama.Alive();
         if(!vivo){ // If dead
          clrscr(); pixelArt("RIP.txt");
          if(tama.getFun()<=0){ cout << "R.I.P. Your Pet died of boredom"<<endl; }
          else if(tama.getHealth()<=0) {cout << "R.I.P. Your Pet died of sickness"<<endl;}
          else if(tama.getHunger()<=0) {cout << "R.I.P. Your Pet died of hunger"<<endl;}
          else cout << "R.I.P. Your Pet died"<<endl;
          if(tama.getAge()==0){
            cout << tama.getName() <<" didn't get to live much with "<<tama.getAge() <<" days"<<endl;
          } else if(tama.getAge()==1){ cout << tama.getName() <<" lived "<<tama.getAge() <<" day"<<endl;
          } else  cout << tama.getName() <<" lived "<<tama.getAge() <<" days"<<endl;
          cout << "Better luck next time!"<<endl;          
    			return 0;
    		}
        
        cin>>x;
        switch(x) { 
            case 1: clrscr();// cout<<"1.Feed\n\n"; 
              tama.menuFeed(); 
              if(tama.getHunger()>=tama.getMaxStatus()){
                vPet->MostrartxtPet();
              } else { vPet->PrintFood(); }
              tama.feedPet(); 
              tama.lowStatus();
              tama.menuDisplay(); 
              break;
          
            case 2: clrscr(); //cout<<"2.PLay\n"; 
              if(tama.getFun()>=tama.getMaxStatus()){
                    vPet->MostrartxtPet();
                } else vPet->PrintAttention();
              tama.playPet();  
              tama.lowStatus();
              tama.menuDisplay(); 
              break;

            case 3: clrscr(); //cout<<"3. Status\n"; 
              pixelArt("status.txt");
              tama.status();
              tama.lowStatus();
              tama.menuDisplay(); 
              break;

            case 4: clrscr(); cout<<"\n\nExceting Program..."<<endl;
                pixelArt("exit.txt");
                break;

            default: cout << "ERROR: Invalid selection. Try agian." << endl;
                break; 
            }
  
      } while (x != 4 || tama.Alive() == 0);
      
  } catch (exception e){
      cout << "ERROR: Try agian later." << endl;
  }
    
  return 0;
}