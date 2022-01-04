#include "ElementEspace.h"
#include "iostream"


ElementEspace::ElementEspace(std::string const& chemin_img )
{
     if(!texture.loadFromFile(chemin_img))
        {

            std::cerr<< "L image  n a pas ete chargee"<<std::endl;
        }

    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(position.getX(),position.getY());
}





void ElementEspace::actualiser(float temps)
{
    MAJ(temps);
    auto deplacement = vitesse * temps;
    position += deplacement;
    sprite.setPosition(position.getX(),position.getY());
    sprite.rotate(vitesseAngulaire*temps);
}

void ElementEspace::MAJ(float temps)
{

}

void ElementEspace::afficher(sf::RenderWindow& fenetre) const
{
    auto affichage = std::array<Vecteur, 9>{Vecteur{-1,-1}, Vecteur{0,-1}, Vecteur{1,-1},
                                            Vecteur{-1, 0}, Vecteur{0,0}, Vecteur{1,0},
                                            Vecteur{-1, 1}, Vecteur{0,1}, Vecteur{1,1}};

    for (auto& affichage : affichage) {
        auto transformation = sf::Transform{};
        transformation.translate(affichage.x*Coordonnees::getLargeurEspace(), affichage.y*Coordonnees::getHauteurEspace());
        fenetre.draw(sprite,transformation);
    }
}

float ElementEspace::getRayon()const
{
    return sprite.getLocalBounds().height/2;
}

void ElementEspace::TesterCollision (ElementEspace& ElementATester)
{
    auto distance = position.calculerDistance(ElementATester.position);
    if (distance < getRayon() + ElementATester.getRayon())
    {
        reagirCollision();

    }

}

