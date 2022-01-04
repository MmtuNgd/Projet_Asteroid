#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H


#include "SFML/Graphics.hpp"
#include "Vecteur.h"
#include "Coordonnees.h"
#include "string"
#include "iostream"
class ElementEspace
{
    public:
        explicit ElementEspace(std::string const& chemin_img);
//        ElementEspace(ElementEspace const& autre) = delete;
//        void operator=(ElementEspace const& autre) = delete;
        virtual ~ElementEspace() = default;
        virtual void afficher(sf::RenderWindow& fenetre) const;
        void actualiser(float temps);

        void TesterCollision (ElementEspace& ElementATester);
        void actualiserEtat(void){};
        float getRayon()const;
        virtual void reagirCollision(void) = 0;

        static inline bool estDetruit(std::unique_ptr<ElementEspace>& element) { return element->detruit;};

    protected:
        virtual void MAJ(float temps);

        sf::Sprite sprite{};
        sf::Texture texture{};
        bool detruit{false};

        Vecteur vitesse{0.f, 0.f};
        Coordonnees position{};
        float vitesseAngulaire{};
    private:
};

#endif // ELEMENTESPACE_H
