#include "Espace.h"

Espace::Espace()
{
    //ctor
}

void Espace::ajouter(std::unique_ptr<ElementEspace> element_ajout)
{
    elements.push_back(std::move(element_ajout));
}


void Espace::actualiser(void)
{
    auto TempsRafraichissement = chrono.restart().asSeconds();
//    vaisseau.actualiserEtat();

    for (auto& element : elements)
    {
        element->actualiser(TempsRafraichissement);
    }

}

void Espace::gerer_collision(void)
{
    for (auto i{0u}; i<elements.size();i++)
    {
        for ( auto j{0u}; j<elements.size();j++)
        {
            if (i != j)
            {
                elements[i]->TesterCollision(*elements[j]);
            }
        }
    }
}

void Espace::afficher(sf::RenderWindow& fenetre) const
{
    for (auto& element : elements)
        {
            element->afficher(fenetre);
        }
}

void Espace::nettoyer(void)
{
    auto finTableau = std::remove_if(std::begin(elements), std::end(elements),ElementEspace::estDetruit);
    elements.erase(finTableau,std::end(elements));
}
