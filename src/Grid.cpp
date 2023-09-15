#include "Grid.h"

Grid::Grid(int gridWidth, int gridHeight, int xPos, int yPos)
{
    m_xBorder = gridWidth*0.05f;
    m_yBorder = gridHeight*0.05f;

    m_gridWidth = gridWidth;
    m_gridHeight = gridHeight;

    m_xPos = xPos;
    m_yPos = yPos;

    m_tileColor = {212, 199, 156, 0};
    m_hoverColor = {170, 157, 114, 0};
    m_backColor = {255, 249, 246, 0};
    m_borderColor = {1, 2, 10, 0};
   
    InitGrid();
}

void Grid::InitGrid()
{
    int tileGridWidth = m_gridWidth - m_xBorder*2;
    int tileGridHeight = m_gridHeight - m_yBorder*2;
    
    int tileOffsetX = tileGridHeight*0.01f;
    int tileOffsetY = tileGridHeight*0.01f;

    int tileGridPosX = m_xPos + m_xBorder;
    int tileGridPosY = m_yPos + m_yBorder;

    m_tileWidth = tileGridWidth/xSize;
    m_tileHeight = tileGridHeight/ySize;

    for (int x = 0; x < xSize; x++)
        for (int y = 0; y < ySize; y++)
            m_grid[x][y] = new Cell(tileGridPosX + x*m_tileWidth,
                                    tileGridPosX + y*m_tileHeight,
                                    m_tileWidth - tileOffsetX/2,
                                    m_tileHeight - tileOffsetY/2, 
                                    m_tileColor);
                    
    m_borderRect.x = m_xPos;
    m_borderRect.y = m_yPos;
    m_borderRect.w = m_gridWidth;
    m_borderRect.h = m_gridHeight;

    int bgOffsetX = m_gridWidth*0.01f;
    int bgOffsetY = m_gridWidth*0.01f;

    m_backgroundRect.x = tileGridPosX - bgOffsetX;
    m_backgroundRect.y = tileGridPosY - bgOffsetX;
    m_backgroundRect.w = tileGridWidth + bgOffsetX + tileOffsetX/2;
    m_backgroundRect.h = tileGridHeight + bgOffsetY + tileOffsetY/2;
}

void Grid::Update(double deltaTime, MouseState mState)
{
    for (int x = 0; x < xSize; x++)
        for (int y = 0; y < ySize; y++)
            if (m_grid[x][y]->Hover(mState))
                m_grid[x][y]->ChangeColor(m_hoverColor);
            else    
                m_grid[x][y]->ChangeColor(m_tileColor); 
    }

void Grid::Draw(SDL_Renderer* renderer)
{
    // Drawing Border
    SDL_SetRenderDrawColor(renderer, m_borderColor.r, m_borderColor.g, m_borderColor.b, m_borderColor.a);
    SDL_RenderDrawRect(renderer, &m_borderRect);
    SDL_RenderFillRect(renderer, &m_borderRect);

    // Drawing Background
    SDL_SetRenderDrawColor(renderer, m_backColor.r, m_backColor.g, m_backColor.b, m_backColor.a);
    SDL_RenderDrawRect(renderer, &m_backgroundRect);
    SDL_RenderFillRect(renderer, &m_backgroundRect);

    // Drawing Tiles
    for (int x = 0; x < xSize; x++)
        for (int y = 0; y < ySize; y++)
            m_grid[x][y]->Draw(renderer);
}