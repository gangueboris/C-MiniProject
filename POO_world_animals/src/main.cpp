#include <iostream>
#include "monde.hpp"
const int nb_anim{30};
int main()
{
    srand(time(NULL)); // Initialisation of the seed

    Monde myMonde(nb_anim);
    std::cout<< myMonde.getKmax_x() <<"\n";

    // Test de la function affiche
    myMonde.peuplement();

    // Simulation
    int a=100;
    while(a--)
    {
       myMonde.passeuntour();
       myMonde.affiche();
    }
 

    return EXIT_SUCCESS;
}