#include "Cell.h"

Cell::Cell(int xPos, int yPos, int width, int height, const SDL_Color color)
{
    m_rect.x = xPos;
    m_rect.y = yPos;
    m_rect.w = width;
    m_rect.h = height;

    m_color = color;
}

bool Cell::Hover(int mouseX, int mouseY)
{
    if (mouseX > m_rect.x && mouseX < m_rect.x + m_rect.w &&
        mouseY > m_rect.y && mouseY < m_rect.y + m_rect.h)
        return true;
    return false;
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
