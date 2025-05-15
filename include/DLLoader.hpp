/**
 * @file DLLoader.hpp
 * @brief Template pour la DLLoader
 * @author X
 *
 * Ce fichier définit le template pour le DLLoader
 */

#ifndef DLLOADER_HPP_
# define DLLOADER_HPP_

#include <dlfcn.h>
#include <exception>
#include <filesystem>
#include <functional>
#include <iostream>

/**
 * @class DLLoader
 * @brief Classe template pour le chargement dynamique de bibliothèques.
 *
 * Cette classe permet de charger dynamiquement des bibliothèques partagées
 * et d'obtenir des instances de symboles spécifiques.
 */
template <typename T>
class DLLoader {
    public:
        /**
        * @brief Constructeur de la class : Permet d'ouvrir une librarie partagé
        * @param path : Le chemin vers la librarie partagé
        */ 
        DLLoader(const std::string &path);

        /**
        * @brief Destructeur de la class : Permet de fermer la librarie partagé ouverte
        */ 
        ~DLLoader();

        /**
        * @brief Permet de recupérer un poiteur sur le symbol souhaité dans la librarie partagé
        * @param symbol : Nom du symbol à récupérer
        */ 
        T *getInstance (const std::string &symbol) const;
    private:
        void *handler;
};
#endif /* !DLLOADER_HPP_ */