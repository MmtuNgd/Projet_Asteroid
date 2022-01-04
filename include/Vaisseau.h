#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include "ElementEspace.h"
#include "Explosion.h"
#include "Espace.h"

class Vaisseau : public ElementEspace
{
    public:

        explicit Vaisseau(Espace& p_espace,sf::Color const& Couleur);
        ~Vaisseau();


        virtual void reagirCollision() override;

    protected:
        virtual void MAJ(float temps) override;


    private:


//        Explosion explosion {};
        void actualiserEtat(void);

        Espace& espace;
        bool accelerationEnCours{false};
        bool tourneAGauche{false};
        bool tourneADroite{false};
        static constexpr float ACCELERATION {4500.f};
        static constexpr float COEF_FROTTEMENT{2.f};
        static constexpr float VITESSE_ANGULAIRE {50};
};


#endif // VAISSEAU_H_INCLUDED
