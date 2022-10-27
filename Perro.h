#include "pet.h"

class vDog: public Animal {
public:
	vDog();
};
vDog::vDog() {
	setName("Dog");
	setFilename("Dog.txt"); //(string _fileName) 
  setfileFeed("dog1.txt");
  setfileFood("dog11.txt");
  setfileAttention("dog2.txt");
}