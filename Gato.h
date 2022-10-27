
#include "pet.h"

class vCat: public Animal {
public:
	vCat();
};
vCat::vCat() {
	setName("Cat");
	setFilename("Cat.txt"); //(string _fileName) 
  setfileFeed("cat1.txt");
  setfileFood("cat11.txt");
  setfileAttention("cat2.txt");
}