#ifndef ESPACE_H
#define ESPACE_H

#include <SFML/Graphics.hpp>
#include "vector"
#include "ElementEspace.h"

class Espace
{
    public:
        Espace();
        void ajouter(std::unique_ptr<ElementEspace> element_ajout);
        void actualiser(void);
        void gerer_collision(void);
        void afficher(sf::RenderWindow& fenetre) const;
        void nettoyer(void);
    protected:

    private:
        sf::Clock chrono{};
        std::vector<std::unique_ptr<ElementEspace>> elements{};
};

#endif // ESPACE_H
