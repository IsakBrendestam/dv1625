#include "Cell.h"

Cell::Cell(int xPos, int yPos, int width, int height, const SDL_Color color)
{
    m_rect.x = xPos;
    m_rect.y = yPos;
    m_rect.w = width;
    m_rect.h = height;

    m_color = color;
}

void Cell::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderDrawRect(renderer, &m_rect);
    SDL_RenderFillRect(renderer, &m_rect);
}

void Cell::ChangeColor(SDL_Color color)
{
    m_color = color;
}
