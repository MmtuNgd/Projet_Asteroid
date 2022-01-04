#include "Asteroide.h"

#include "iostream"
#include "random"

Asteroide::Asteroide() : ElementEspace::ElementEspace{"ressources/asteroide.png"}
{

    std::random_device  generateur = {};
    auto distributionPosition = std::uniform_real_distribution<float>{-50,500};
    auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10,30};
    position =  {distributionPosition(generateur),distributionPosition(generateur)};
    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur),distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);

//    std::cout << "Asteroide CREEEE" << std::endl;

}

Asteroide::~Asteroide()
{
    std::cout << "Asteroide detruit" << std::endl;
}


void Asteroide::reagirCollision()
{

}
