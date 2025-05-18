/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** RenderingState
*/

#ifndef RENDERING_STATE_HPP
#define RENDERING_STATE_HPP

#include <memory>
#include <iostream>

class RenderingContext;

class IRenderingState {
    public:
        virtual ~IRenderingState() = default;
        virtual void handle(RenderingContext& context) = 0;
};

class InitializationState : public IRenderingState {
    public:
        void handle(RenderingContext& context) override;
};

class RenderingState : public IRenderingState {
    public:
        void handle(RenderingContext& context) override;
};

class FinishedState : public IRenderingState {
    public:
        void handle(RenderingContext& context) override;
};

#endif // RENDERING_STATE_HPP