#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "ElementEspace.h"
#include "Espace.h"
#include "Jeu.h"
constexpr Vecteur VECT_VITESSE_ASTEROIDE {100,20};

class Asteroide : public ElementEspace
{
    public:
         explicit Asteroide(Jeu& p_jeu,Espace& p_espace, Asteroide* parent = nullptr);
        ~Asteroide();

        virtual void reagirCollision(TypeElement typeAutre) override;

    private :
        Jeu& jeu;
        Espace& espace;
};

#endif // ASTEROIDE_H
