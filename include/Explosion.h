#ifndef EXPLOSION_
#define EXPLOSION_

#include <ElementEspace.h>


class Explosion : public ElementEspace
{
    public:
        Explosion(Coordonnees const& p_position);

        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
        virtual void MAJ(float temps) override;

    private:
        float age{};

        static constexpr float DUREE_VIE {0.1f};
};

#endif // EXPLOSION_
