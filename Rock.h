#include "pet.h"

class vRock: public Animal {
public:
	vRock();
};
vRock::vRock() {
  setName("Rock");
  setFilename("Rock.txt"); //(string _fileName) 
  setfileFeed("rock1.txt");
  setfileFood("rock11.txt");
  setfileAttention("rock2.txt");
}
