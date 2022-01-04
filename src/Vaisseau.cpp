#include "Vaisseau.h"
#include <iostream>

#include "Missile.h"
 Vaisseau::Vaisseau (Espace& p_espace,sf::Color const& Couleur) : ElementEspace::ElementEspace("ressources/vaisseau1S.png"), espace{p_espace}
{

    sprite.setColor(Couleur);
    type = TypeElement::VAISSEAU;
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

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (dernier_tir.getElapsedTime().asSeconds() > 0.1))
            {
                espace.ajouter(std::make_unique<Missile>(position,sprite.getRotation()));
                dernier_tir.restart();
            }
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

void Vaisseau::reagirCollision(TypeElement typeAutre)
{
    if (typeAutre == TypeElement::ASTEROIDE)
    {
        detruit = true;
//        explosion.demarrer(position);
        espace.ajouter(std::make_unique<Explosion>(position));
    }

}

