#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Cell.h"

#define xSize 17
#define ySize 17

class Grid
{
public:
    Grid(int gridWidth, int gridHeight, int xPos, int yPos);
    void Draw(SDL_Renderer* renderer);
    void Update(double deltaTime, int mouseX, int mouseY);

private:
    void InitGrid();

private:
    int m_gridWidth, m_gridHeight;
    int m_tileWidth, m_tileHeight;
    int m_xBorder, m_yBorder;
    int m_xPos, m_yPos;
    
    Cell *m_grid[xSize][ySize];

    SDL_Color m_tileColor, m_backColor, m_hoverColor, m_borderColor;

    SDL_Rect m_backgroundRect;
    SDL_Rect m_borderRect;
};
