/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** RenderingState implementation
*/

#include <iostream>
#include "RenderingState.hpp"
#include "RenderingContext.hpp"

void InitializationState::handle(RenderingContext& context) {
    std::clog << "Initialisation du rendu...\n";
    context.setState(std::make_unique<RenderingState>());
}

void RenderingState::handle(RenderingContext& context) {
    std::clog << "Rendu en cours...\n";
    context.setState(std::make_unique<FinishedState>());
}

void FinishedState::handle(RenderingContext& context) {
    std::clog << "Rendu terminé.\n";
}