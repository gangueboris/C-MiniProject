#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <unistd.h>
#include "monde.hpp"
#include "animal.hpp"


const int MAX_LIFE{100}; 
const int tempo{10000};

// 2. Implemantation of peuplement function
void Monde::peuplement()
{
    for(int i = 0; i < nb_animaux; i++)
    {
        
        int x = rand() % getKmax_x();
        int y = rand() % getKmax_y();
        int life = rand() % MAX_LIFE;
        Animal temp{x, y, life};
        tab_anim.push_back(temp);
    }
}

// 3. Implemantation of affiche function
void Monde::affiche()
{
    system("clear"); // Clean std output

    for(int i = 0; i < nb_animaux; ++i)
    {
        tab_anim[i].affiche(); // Display information of each animal
        int x = tab_anim[i].getX();
        int y = tab_anim[i].getY();
        tab2D[y][x] = 'A';
    }
    // Code to display the screen
    for(int r = 0;  r < getKmax_y(); ++r)
    {
        for(int c = 0; c < getKmax_x(); ++c)
        {
            tab2D[r][c] == 'A' ? std::cout << " A " : std:: cout << " . ";
        }
        std::cout << "\n\n";
    }

    usleep(tempo); // Temporisation in microseconds
}

// 4. 