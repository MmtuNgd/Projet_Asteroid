#include "Explosion.h"

Explosion::Explosion(Coordonnees const& p_position) : ElementEspace("ressources/explosion.png")
{
    position = p_position;
}



void Explosion::MAJ(float temps)
{
    age += temps;
    if(age< DUREE_VIE)
    {
        sprite.setScale(age/DUREE_VIE,age/DUREE_VIE);
    }
    else
    {
        detruit = true;
    }
    ElementEspace::MAJ(temps);
}


void Explosion::reagirCollision() {}
