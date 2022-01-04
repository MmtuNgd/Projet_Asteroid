#ifndef EXPLOSION_
#define EXPLOSION_

#include <ElementEspace.h>


class Explosion : public ElementEspace
{
    public:
        Explosion(Coordonnees const& p_position);

        //void demarrer(Coordonnees const& p_position);
        virtual void reagirCollision() override;
        //virtual void afficher(sf::RenderWindow& fenetre) const override;

    protected:
        virtual void MAJ(float temps) override;

    private:
        //bool demarree = false;
        float age{};

        static constexpr float DUREE_VIE {0.1f};
};

#endif // EXPLOSION_
