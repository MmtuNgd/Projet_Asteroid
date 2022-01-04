#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H


#include "SFML/Graphics.hpp"
#include "Vecteur.h"
#include "Coordonnees.h"
#include "string"
#include "iostream"

enum class TypeElement{ VAISSEAU, ASTEROIDE, MISSILE, AUTRE};

class ElementEspace
{
    public:
        explicit ElementEspace(std::string const& chemin_img);

        virtual ~ElementEspace() = default;
        virtual void afficher(sf::RenderWindow& fenetre) const;
        void actualiser(float temps);

        void TesterCollision (ElementEspace& ElementATester);
        void actualiserEtat(void){};
        float getRayon()const;
        virtual void reagirCollision(TypeElement typeAutre) = 0;

        static inline bool estDetruit(std::unique_ptr<ElementEspace>& element) { return element->detruit;};

    protected:
        virtual void MAJ(float temps);
        TypeElement type{TypeElement::AUTRE};

        sf::Sprite sprite{};
        sf::Texture texture{};
        bool detruit{false};

        Vecteur vitesse{0.f, 0.f};
        Coordonnees position{};
        float vitesseAngulaire{};
    private:
};

#endif // ELEMENTESPACE_H
