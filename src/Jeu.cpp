#include "Jeu.h"

#include "memory"
#include "Vaisseau.h"
#include "Asteroide.h"
#include "GestionnaireRessources.h"
#include "font.h"
#include "string"
#include "fstream"

using namespace std::string_literals;


const sf::Color COULEUR_VAISSEAU {sf::Color::Green};

Jeu::Jeu(Espace& p_espace) : espace{p_espace}
{

    if(!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) throw std::runtime_error{"Police introuvable"};
    texteScore.setFont(police);
    texteScore.move(0,30);
    texteMeilleurScore.setFont(police);

    auto fichier = std::ifstream{"meilleurScore.txt"};

    if(fichier.is_open())
    {
        fichier >> meilleurScore;
    }
    fichier.close();
    try
    {
        spriteAccueil.setTexture(GestionnaireRessources::getRessource("ressources/accueil.png"));
    } catch (std::exception const& exception)
    {
        initialiserException(exception);
    }
}

void Jeu::demarrer()
{
    score = 0;
    enCours = true;
    rafraichirText();
    rafraichirMeilleurScore();
    espace.ajouter(std::make_unique<Vaisseau>(*this,espace, COULEUR_VAISSEAU));
    espace.ajouter(std::make_unique<Asteroide>(*this,espace));
    espace.ajouter(std::make_unique<Asteroide>(*this,espace));
    espace.ajouter(std::make_unique<Asteroide>(*this,espace));
}

void Jeu::terminer()
{
    enCours = false;
    espace.vider();

    if (score > meilleurScore)
    {
        meilleurScore = score;
        rafraichirMeilleurScore();
        auto fichier = std ::ofstream{"meilleurScore.txt"};

        if (fichier.is_open())
        {
            fichier << meilleurScore;
        }
        else
        {
            throw std::runtime_error{"Impossible d'ouvrir le fichier meilleur score en ecriture"};
        }
        fichier.close();
    }

}

void Jeu::ajouterPoints(int points)
{
    score += points;
    rafraichirText();
}

void Jeu::afficher(sf::RenderWindow& fenetre) const
{
    if (!enCours)
    {
        fenetre.draw(spriteAccueil);
    }
    else
    {
        fenetre.draw(texteScore);
    }

    fenetre.draw(texteMeilleurScore);

    if (textException)
    {
        fenetre.draw(*textException);
    }
}

void Jeu::initialiserException(std::exception const& exception)
{
        textException = std::make_unique<sf::Text>();
        textException->setFont(police);
        textException->setString(exception.what());
        textException->setFillColor(sf::Color::Red);
}

void Jeu::rafraichirText(void)
{
    texteScore.setString("Score :"s + std::to_string(score));
}

void Jeu::rafraichirMeilleurScore(void)
{
    texteMeilleurScore.setString("Meilleur Score :"s + std::to_string(meilleurScore));

}
