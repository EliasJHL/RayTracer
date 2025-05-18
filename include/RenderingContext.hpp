/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** RenderingContext
*/

#ifndef RENDERING_CONTEXT_HPP
#define RENDERING_CONTEXT_HPP

#include <memory>
#include "RenderingState.hpp"

class RenderingContext {
    public:
        RenderingContext(std::unique_ptr<IRenderingState> initialState)
            : currentState(std::move(initialState)) {}

        void setState(std::unique_ptr<IRenderingState> newState) {
            currentState = std::move(newState);
        }

        void execute() {
            if (currentState) {
                currentState->handle(*this);
            }
        }
    private:
        std::unique_ptr<IRenderingState> currentState;
};

#endif // RENDERING_CONTEXT_HPP