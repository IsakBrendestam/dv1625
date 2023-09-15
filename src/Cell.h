#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_test_font.h>

class Cell
{
public:
    Cell(int xPos, int yPos, int width, int height, SDL_Color color);
    void Draw(SDL_Renderer* renderer);

    bool Hover(int mouseX, int mouseY); 
    void ChangeColor(SDL_Color color);

private:
    SDL_Rect m_rect;
    SDL_Color m_color;
};