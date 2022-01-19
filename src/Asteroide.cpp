#include "Asteroide.h"

#include "iostream"
#include "random"
#include "Explosion.h"
Asteroide::Asteroide(Jeu& p_jeu,Espace& p_espace, Asteroide* parent) : ElementEspace::ElementEspace{"ressources/asteroide.png"}, jeu{p_jeu},espace{p_espace}
{
    type = TypeElement::ASTEROIDE;
    std::random_device  generateur = {};
    auto distributionPosition = std::uniform_real_distribution<float>{-50,500};
    auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10,30};

    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur),distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);

//    std::cout << "Asteroide CREEEE" << std::endl;
    if (parent)
    {
        sprite.setScale(parent->sprite.getScale().x/1.4, parent->sprite.getScale().y/1.4);
        position = parent->position;
    }
    else
    {
        position =  {distributionPosition(generateur),distributionPosition(generateur)};
    }
}

Asteroide::~Asteroide()
{
    std::cout << "Asteroide detruit" << std::endl;
}


void Asteroide::reagirCollision(TypeElement typeAutre)
{
    if (typeAutre == TypeElement::MISSILE)
    {
        detruit = true;
        jeu.ajouterPoints(sprite.getScale().x * 100);
        if (sprite.getScale().x > 0.6)
        {
            espace.ajouter(std::make_unique<Asteroide>(jeu,espace,this));
            espace.ajouter(std::make_unique<Asteroide>(jeu,espace,this));
        }

        espace.ajouter(std::make_unique<Explosion>(position));
    }
}
