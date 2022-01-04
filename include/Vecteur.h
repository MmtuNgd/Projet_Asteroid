#ifndef VECTEUR_H
#define VECTEUR_H


struct Vecteur
{

        void operator += (Vecteur const& autre);
        void operator -= (Vecteur const& autre);
        Vecteur operator * (float coefficient) const;


        static Vecteur creerDepuisAngle(float taille, float angleEnDegree);

        float x = {0.f};
        float y = {0.f};

};



#endif // VECTEUR_H
