#ifndef JEU_H
#define JEU_H

#include "Espace.h"
#include "memory"
#include "exception"
class Jeu
{
    public:
        Jeu(Espace& p_espace);
        void demarrer(void);
        void terminer(void);
        void ajouterPoints(int points);
        void afficher(sf::RenderWindow& fenetre) const;
        inline bool EstEnCours(void) { return enCours;};
        void initialiserException(std::exception const& exception);
    protected:

    private:
        void rafraichirText(void);
        void rafraichirMeilleurScore(void);
        Espace& espace;
        bool enCours{false};
        int score{};
        int meilleurScore{};

        sf::Text texteMeilleurScore{};
        sf::Text texteScore{};
        sf::Font police;
        sf::Sprite spriteAccueil{};
        std::unique_ptr<sf::Text> textException{nullptr};
};

#endif // JEU_H
