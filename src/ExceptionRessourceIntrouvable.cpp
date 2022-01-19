#include "ExceptionRessourceIntrouvable.h"

ExceptionRessourceIntrouvable::ExceptionRessourceIntrouvable(std::string const& chemin) : messageErreur("Erreur, ressource introuvable : " + chemin)
{
    //ctor
}


const char* ExceptionRessourceIntrouvable::what() const noexcept
{
    return messageErreur.c_str();
}
