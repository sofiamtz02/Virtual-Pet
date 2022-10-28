# Virtual-Pet

`Link to video:` https://drive.google.com/file/d/1mmcfB4XZbHUJRKeWrTSPZ8wqSp_8HP52/view?usp=sharing

This program consists of a Tamagotchi, or virtual pet. Just like in the tamagotchi game, the user must take care of their pet, in order for it to live. Therefore, it's a must to look after it by giving it attention, checking it's health and feeding it food. It's important to pay atention to the porcentage of each one, as it ages, the porcentages will reduce. 
It is worth mentioning that threads are used to increasing the age every 60 seconds, and at the same time it reduces the porcentage of health, hunger and attention. There is a class Animal, which is inhereted to the class dog, cat and rock. OOP, vector, text files for images and among other things were used for the creation of this project. 

---
## Using Program
The user will be given 3 options of the pet they want:
1) Cat
2) Dog
3) Rock

After choosing, it will be possible to name the new pet.

After, the login menu will appear, giving the user 4 options: to feed it, play, check status or exit the game. Just as it's shown next: 
1. Feed 
2. Play  
3. Check Status
4. Exit Game

If decided to feed the pet, 4 options will be available. Such as giving it treats, kibbles, icecream or medicine. Depending on the option chosen by the user, it will be reflected on the percentage of its status, whether it increases or reduces. 
If the play option is chosen, it will increase the porcentage of fun, but make the pet hungry. Finaly, when checking its status, you'd be able to see the age of the pet, and the porcentages of the other variables. 

---
# Run Project
> g++  Main.cpp  -o main -pthread;

> ./main    


**Note: 6 warnings may appear, but they can be ignored while compiling.**

