#include <iostream>
#include "monde.hpp"
const int nb_anim{5};
int main()
{
    srand(time(NULL)); // Initialisation of the seed

    Monde myMonde(nb_anim);
    std::cout<< myMonde.getKmax_x() <<"\n";

    // Test de la function affiche
    myMonde.peuplement();
    myMonde.affiche();

    return EXIT_SUCCESS;
}