#ifndef _ANIMAL_H
#define _ANIMAL_H

class Animal
{
   public:
   // Constructeur
    Animal(int x_ = 0, int y_ = 0, int energy_ = 0):x{x_}, y{y_}, energy{energy_}{}
   
    // Getteurs
    int getX() const {return x;}
    int getY() const {return y;}
    int getEnergy() const {return energy;}
     
     // Setteurs
    void setX(const int x_){x = x_;}
    void setY(const int x_){x = x_;}
    void setEnergy(const int x_){x = x_;}

    // Autres fonctions
    void affiche() const { std::cout << "x: " << x <<" "<< "y: " << y << " " << "Energy: " << energy <<"\n\n";}
   
    ~Animal()
    {
      //std::cout << "Appel destructeur !" << "\n";
    }

      
  private:
     int x, y, energy;
     //static inline int nbAnimaux{0};
};

#endif