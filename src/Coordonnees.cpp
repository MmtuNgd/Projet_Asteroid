#include "Coordonnees.h"
#include "cmath"
#include <algorithm>
float Coordonnees::hauteur = 0;
float Coordonnees::largeur = 0;


Coordonnees::Coordonnees(): x{largeur/2},y{largeur/2}
{

}

Coordonnees::~Coordonnees()
{

}

Coordonnees::Coordonnees(float px, float py)
{
    x = px;
    y = py;
}

void Coordonnees::InitialiserEspace(float xinit, float yinit)
{
    largeur = xinit;
    hauteur = yinit;
}

void Coordonnees::operator += (Vecteur const& VecAjout)
{
    x += VecAjout.x;
    y += VecAjout.y;

    if (x > largeur)
    {
        x = 0;
    }

    if (y > hauteur)
    {
        y = 0;
    }

    if (x < 0)
    {
        x = largeur;
    }

    if (y < 0)
    {
        y = hauteur;
    }
}


float Coordonnees::getX(void)
{
    return x;
}

float Coordonnees::getY(void)
{
    return y;
}

float Coordonnees::getLargeurEspace(void)
{
    return largeur;
}

float Coordonnees::getHauteurEspace(void)
{
    return hauteur;
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const
{
    auto delta = Vecteur {std::min({abs(x-autre.x),abs(x-autre.x-largeur),abs(x-autre.x+largeur)}),std::min({abs(y-autre.y),abs(y-autre.y-hauteur),abs(y-autre.y+hauteur)})};
    return sqrt(delta.x*delta.x+delta.y*delta.y);
}
