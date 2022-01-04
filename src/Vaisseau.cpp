#include "Vaisseau.h"
#include <iostream>

 Vaisseau::Vaisseau (Espace& p_espace,sf::Color const& Couleur) : ElementEspace::ElementEspace("ressources/vaisseau1S.png"), espace{p_espace}
{

    sprite.setColor(Couleur);
}

Vaisseau::~Vaisseau()
{
    std::cout << "Vaisseau detruit" << std::endl;
}

void Vaisseau::actualiserEtat(void)
{
        accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::MAJ(float temps)
{
    actualiserEtat();
    if (!detruit)
    {
        if (accelerationEnCours)
        {
            vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
        }
        vitesse -= vitesse * COEF_FROTTEMENT *temps;

        if (tourneAGauche)
        {
            vitesseAngulaire = - VITESSE_ANGULAIRE;
            //sprite.rotate(- VITESSE_ANGULAIRE * temps);

        }else if (tourneADroite)
        {
            vitesseAngulaire = VITESSE_ANGULAIRE;
        }
        else
        {
            vitesseAngulaire = 0;

        }

    }
   // ElementEspace::MAJ(temps);


}

void Vaisseau::reagirCollision()
{
    if (!detruit)
    {
        detruit = true;
//        explosion.demarrer(position);
        espace.ajouter(std::make_unique<Explosion>(position));
    }

}

