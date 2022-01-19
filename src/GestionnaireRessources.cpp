#include "GestionnaireRessources.h"
#include "iostream"
#include "ExceptionRessourceIntrouvable.h"

std::unordered_map<std::string,sf::Texture>GestionnaireRessources::ressources{};
sf::Texture const& GestionnaireRessources::getRessource(std::string const& chemin)
{
    auto resultat = ressources.find(chemin);
    if (resultat == std::end(ressources))
        {
            if (!ressources[chemin].loadFromFile(chemin.data()))
            {
                throw ExceptionRessourceIntrouvable{chemin};
            }
            return ressources[chemin];
        }
        return resultat->second;
}
