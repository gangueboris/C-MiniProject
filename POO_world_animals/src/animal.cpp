#include <iostream>
#include "monde.hpp"
#include "animal.hpp"


// 4. Implementation de la function bouge

void Animal::bouge()
{
    int position = rand() % 4;
    switch (position)
    {
        
        case 0: // Top
            y = ((y + 1) % KM_y);
            break;
        case 1: // Bottom
            y = (y - 1) < 0 ? 0 : ((y - 1) % KM_y);
            break;
        case 2: // Left
            x = (x - 1) < 0 ? 0 : ((x - 1) % KM_x);
            break;
        case 3: // Right
            x = ((x + 1) % KM_x);
            break;
        default:
            break;
    }

}
