#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_test_font.h>

#include "MouseState.h"

class Cell
{
public:
    Cell(int xPos, int yPos, int width, int height, SDL_Color color);
    void Draw(SDL_Renderer* renderer);

    bool Hover(MouseState mState);
    void ChangeColor(SDL_Color color);

private:
    SDL_Rect m_rect;
    SDL_Color m_color;
    SDL_Color m_selectedColor;
    bool m_selected;
};