#include "Vecteur.h"
#include "cmath"


void Vecteur::operator+=(Vecteur const& autre)
{
    x = x + autre.x;
    y = y + autre.y;
}

void Vecteur::operator-=(Vecteur const& autre)
{
    x = x - autre.x;
    y = y - autre.y;
}

Vecteur Vecteur::operator*(float coefficient) const
{
    return Vecteur{x*coefficient, y*coefficient};
}


Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegree)
{
    return {taille*cos(angleEnDegree/180.f*M_PI),taille * sin(angleEnDegree/180.f * M_PI)};
}
