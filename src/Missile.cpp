#include "Missile.h"


Missile::Missile(Coordonnees const& p_position, float rotation) : ElementEspace{"ressources/red_laser.png"}
{
    position = p_position;
    sprite.setRotation(rotation);
    vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);
    type = TypeElement::MISSILE;
}


void Missile::reagirCollision(TypeElement typeAutre)
{
    if (typeAutre != TypeElement::VAISSEAU)
    {
        detruit = true;
    }

}
