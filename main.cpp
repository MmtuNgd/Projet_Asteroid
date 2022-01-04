#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include "Coordonnees.h"
#include "Asteroide.h"
#include "Espace.h"

#include "memory"
constexpr int HAUTEUR_MAX {1000};
constexpr int LARGEUR_MAX {800};

const sf::Color COULEUR_VAISSEAU {sf::Color::Green};

using namespace std;

int main()
{

    sf::RenderWindow fenetre {sf::VideoMode(LARGEUR_MAX,HAUTEUR_MAX), "Fenetre de Jeux"};

    Coordonnees::InitialiserEspace(LARGEUR_MAX,HAUTEUR_MAX);
    std::string chemin_asteroide = "ressources/asteroide.png";
    std::string chemin_vaisseau = "ressources/vaisseau1S.png";
    auto espace = Espace{};

    auto pointeurVaisseau = std::unique_ptr<ElementEspace>{nullptr};
    bool partie_started = false;


    while (fenetre.isOpen())
    {
        auto evenement = sf::Event();
        while (fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::Closed)
            {
                fenetre.close();
            }
            if ((evenement.type == sf::Event::KeyPressed) && (partie_started == false))
            {
                partie_started = true;

                espace.ajouter(std::make_unique<Vaisseau>(espace, COULEUR_VAISSEAU));
                espace.ajouter(std::make_unique<Asteroide>());
                espace.ajouter(std::make_unique<Asteroide>());
                espace.ajouter(std::make_unique<Asteroide>());



            }
        }

        espace.actualiser();
        espace.gerer_collision();
        espace.nettoyer();
        fenetre.clear();
        espace.afficher(fenetre);

        fenetre.display();
    }

    cout<<"Fin du programme"<<endl;
    return 0;
}
