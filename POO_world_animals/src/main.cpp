#include <iostream>
#include "monde.hpp"
const int nb_anim{30};

/*
 ----------------------- TO-DO -------------------------------
   1. Set the paysage to tab2D in monde.hpp (Done)
   2. Modify the affiche by changing if/else if statements to switch case tab2D[y][x] in monde.cpp (Done)
   3. Modify the bouge new_position == 'R' or 'M' stay at is position in animal.cpp

   NOTE: Bug on line 32 in monde.hpp
*/

int main()
{
    srand(time(NULL)); // Initialisation of the seed

    Monde myMonde(nb_anim);
    std::cout<< myMonde.getKmax_x() <<"\n";

    // Test de la function affiche
    myMonde.peuplement();

    // Simulation
    int a = 100;
   while(a--)
    {
       myMonde.passeuntour();
       myMonde.affiche();
    }
    //myMonde.affiche();
 

    return EXIT_SUCCESS;
}