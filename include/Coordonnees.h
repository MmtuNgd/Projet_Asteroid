#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

class Coordonnees
{
    public:
        Coordonnees();
        Coordonnees(float px,float py);
        ~Coordonnees();
        static void InitialiserEspace(float xinit, float yinit);



        void operator += (Vecteur const& VecAjout);

        float getX(void);
        float getY(void);
        static float getLargeurEspace(void);
        static float getHauteurEspace(void);

        float calculerDistance(Coordonnees const& autre) const;

    private:
         float x;
         float y;
         static float largeur;
         static float hauteur;
};

#endif // COORDONNEES_H
