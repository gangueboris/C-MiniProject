#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <unistd.h>
#include "monde.hpp"
#include "animal.hpp"


const int MAX_LIFE{100}; 
const int tempo{100000};

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
        //tab_anim[i].affiche(); // Display information of each animal
        int x = tab_anim[i].getX();
        int y = tab_anim[i].getY();

        tab_anim[i].getEnergy() > 0 ? tab2D[y][x] = 'A' : tab2D[y][x] = 'X';
    }
    // Code to display the screen
    for(int r = 0;  r < getKmax_y(); ++r)
    {
        for(int c = 0; c < getKmax_x(); ++c)
        {
            if (tab2D[r][c] == 'A') std::cout << " A ";
            else if (tab2D[r][c] == 'X') std::cout << " X ";
            else std::cout << " . ";
        }
        std::cout << "\n\n";
    }

    usleep(tempo); // Temporisation in microseconds
}

// 4. Implementation de la fonction passer un tour
void Monde::passeuntour()
{
    for (auto &anim : tab_anim)
    {   
        // Set the old position to '.' before moving
        int curr_x = anim.getX();
        int curr_y = anim.getY();
        
        if (tab2D[curr_y][curr_x] == 'A') tab2D[curr_y][curr_x] = '.';
    
        if(anim.getEnergy() > 0)
        {
            anim.bouge();
            anim.setEnergy(anim.getEnergy() -1);
        }
        // Baisse de vie
        if (anim.getEnergy() == 0)
        {
            int curr_x = anim.getX();
            int curr_y = anim.getY();
            tab2D[curr_y][curr_x] = 'X'; // Simulation d'une mort
        }

    }
}