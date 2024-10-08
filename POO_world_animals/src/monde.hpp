#ifndef _MONDE_H
#define _MONDE_H
#include "animal.hpp"
#include <vector>

const int KM_x = 30;
const int KM_y = 20;

class Monde
{
    public:
    // Constructor
    Monde(const int& init_nbAnim = 5) : nb_animaux{init_nbAnim}{};

    // Getteurs
    static const int getKmax_x() {return kMax_x;}
    static const int getKmax_y() {return kMax_y;}

    // Others methods
    void peuplement();
    void affiche();

    private:
        // Screen size
        static const int kMax_x{KM_x};
        static const int kMax_y{KM_y};

        // Attributes
        int nb_animaux;
        char tab2D[kMax_y][kMax_x];
        std::vector<Animal> tab_anim;

};

#endif