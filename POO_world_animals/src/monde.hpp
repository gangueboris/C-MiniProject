#ifndef _MONDE_H
#define _MONDE_H
#include "animal.hpp"
#include <vector>
#include <fstream>
#include <string>

const int KM_x = 40;
const int KM_y = 16;
class Animal;

class Monde
{
    public:
    // Constructor
    Monde(const int& init_nbAnim = 5)
    {
        nb_animaux = init_nbAnim;

        // Lecture de fichier
        const char* file_name{"paysage.txt"}; 
        std::ifstream finput(file_name);
        if(!finput)
        { // si erreur
            std::cout << "Erreur d'ouverture fichier " << file_name << "\n";
            exit(1);
        }
        std::string ligne;
        int r = 0;
        while(r < kMax_y && std::getline(finput, ligne)){ //lecture de la ligne
           for(int c = 0; c < kMax_x; ++c)
           {
             tab2D[r][c] = ligne[c]; // Bug
           }
           r++;
        }
        // For the verification
        /*std::cout << "verif\n";
        for(int r = 0; r < kMax_y; ++r)
        {
            for (int c = 0; c < kMax_x; ++c)
            {
                std::cout << tab2D[r][c];
            }
            std::cout << "\n";
        }*/
     finput.close();
    }
    ~Monde(){} // fermeture (pas strictement nécessaire : automatique quand finput est détruit)

    // Getteurs
    static const int getKmax_x() {return kMax_x;}
    static const int getKmax_y() {return kMax_y;}

    // Others methods
    void peuplement();
    void affiche();
    void  passeuntour();
    bool isFree(int y,int x){return tab2D[y][x] == ' ' ? true : false;}

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