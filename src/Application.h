#pragma once
#include <SDL2/SDL.h>
#include <ctime>
#include "Debug.h"
#include "Grid.h"
#include "Music.h"
#include "MouseState.h"

#define W_WIDTH 850
#define W_HEIGHT 850

#if defined(_WIN64) || defined(_WIN32)
    #define T_WIDTH W_WIDTH
    #define T_HEIGHT W_HEIGHT
    #define WINDOWS true
#elif __APPLE__
    #define T_WIDTH W_WIDTH*2
    #define T_HEIGHT W_HEIGHT*2
    #define WINDOWS false
#endif

class Application
{
public:
    Application(const char* title);
    ~Application();

    int Run();
    void Initialize();
    void Event(SDL_Event event);
    void Update(double deltaTime);
    void Draw();

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Event m_windowEvent;

    bool m_running;
    double m_deltaTime;
    double m_fps;

    MouseState m_mouseState;

private:
    Grid* grid;
    Music* music;
};