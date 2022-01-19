#include <SFML/Graphics.hpp>
#include "Coordonnees.h"
#include "Espace.h"
#include "Jeu.h"
#include "exception"

constexpr int HAUTEUR_MAX {1000};
constexpr int LARGEUR_MAX {800};


using namespace std;

int main()
{

    sf::RenderWindow fenetre {sf::VideoMode(LARGEUR_MAX,HAUTEUR_MAX), "Fenetre de Jeux"};

    Coordonnees::InitialiserEspace(LARGEUR_MAX,HAUTEUR_MAX);
    std::string chemin_asteroide = "ressources/asteroide.png";
    std::string chemin_vaisseau = "ressources/vaisseau1S.png";
    auto espace = Espace{};
    auto jeu = Jeu{espace};
    auto pointeurVaisseau = std::unique_ptr<ElementEspace>{nullptr};



    while (fenetre.isOpen())
    {
        try
        {
            auto evenement = sf::Event();
            while (fenetre.pollEvent(evenement))
            {
                if (evenement.type == sf::Event::Closed)
                {
                    fenetre.close();
                }
                if ((evenement.type == sf::Event::KeyPressed) && (!jeu.EstEnCours()))
                {
                    jeu.demarrer();
                }
            }

            espace.actualiser();
            espace.gerer_collision();

            fenetre.clear();
            espace.afficher(fenetre);
            jeu.afficher(fenetre);
            fenetre.display();
            espace.nettoyer();
        } catch(std::exception const& exception)
        {
            jeu.initialiserException(exception);
        }


    }

    cout<<"Fin du programme"<<endl;
    return 0;
}
