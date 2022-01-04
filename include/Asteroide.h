#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "ElementEspace.h"

constexpr Vecteur VECT_VITESSE_ASTEROIDE {100,20};

class Asteroide : public ElementEspace
{
    public:
         explicit Asteroide();
        ~Asteroide();

        virtual void reagirCollision(TypeElement typeAutre) override;
};

#endif // ASTEROIDE_H
