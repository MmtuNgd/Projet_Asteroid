#ifndef GESTIONNAIRERESSOURCES_H
#define GESTIONNAIRERESSOURCES_H

#include <SFML/Graphics.hpp>
#include "string_view"
#include "unordered_map"

class GestionnaireRessources
{
    public:
        GestionnaireRessources() = delete;
        static sf::Texture const& getRessource(std::string const& chemin);

    protected:

    private:
       static std::unordered_map<std::string, sf::Texture> ressources;
};

#endif // GESTIONNAIRERESSOURCES_H
