#include "Cell.h"

Cell::Cell(int xPos, int yPos, int width, int height, const SDL_Color color)
{
    m_rect.x = xPos;
    m_rect.y = yPos;
    m_rect.w = width;
    m_rect.h = height;

    m_color = color;
    m_selectedColor.r = color.r + 20;
    m_selectedColor.g = color.g + 20;
    m_selectedColor.b = color.b + 20;
    m_selectedColor.a = color.a;
}

bool Cell::Hover(MouseState mState)
{
    // This is unexpected behaviour
    if (mState.lBtnDown)
        m_selected = !m_selected; 

    if (mState.x > m_rect.x && mState.x < m_rect.x + m_rect.w &&
        mState.y > m_rect.y && mState.y < m_rect.y + m_rect.h)
        return true;

    return false;
}

void Cell::Draw(SDL_Renderer* renderer)
{
    if (m_selected)
        SDL_SetRenderDrawColor(renderer, m_selectedColor.r, m_selectedColor.g, m_selectedColor.b, m_selectedColor.a);
    else
        SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderDrawRect(renderer, &m_rect);
    SDL_RenderFillRect(renderer, &m_rect);
}

void Cell::ChangeColor(SDL_Color color)
{
    m_color = color;
}
