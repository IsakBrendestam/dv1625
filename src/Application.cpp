#include "Application.h"

Application::Application(const char* title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow(title, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED,
                                W_WIDTH,
                                W_HEIGHT,
                                SDL_WINDOW_ALLOW_HIGHDPI);

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    m_running = true;
    m_deltaTime = 0;
    m_fps = 0;
}

Application::~Application()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

int Application::Run()
{
    clock_t time1 = std::clock();
    clock_t time2 = std::clock();

    Initialize();

    while (m_running)
    {
        time2 = std::clock();

        m_deltaTime = (double)(time2-time1)/CLOCKS_PER_SEC;
        m_fps = 1/m_deltaTime;

        while (SDL_PollEvent(&m_windowEvent))
        {
            switch (m_windowEvent.type)
            {
                case SDL_QUIT:
                    m_running = false;
                    break;

                case SDL_KEYDOWN:
                    // Quitting if Esc is pressed
                    if (m_windowEvent.key.keysym.sym == SDLK_ESCAPE)
                        m_running = false;
                    break;
            }

            Event(m_windowEvent);
        }

        SDL_GetMouseState(&m_mouseX, &m_mouseY); 
        if (!WINDOWS)
        {
            m_mouseX *= 2;
            m_mouseY *= 2;   
        }

        Update(m_deltaTime);

        Draw();

        std::cout << "FPS:" << m_fps << "\r";
        fflush(stdout);

        time1 = time2;
    }

    return EXIT_SUCCESS;
}

void Application::Initialize()
{
    int w = T_WIDTH*0.9;
    int h = T_HEIGHT*0.9;
    grid = new Grid(w, h, (T_WIDTH-w)/2, (T_HEIGHT-h)/2);
}

void Application::Event(SDL_Event event)
{

}

void Application::Update(double deltaTime)
{
    grid->Update(deltaTime, m_mouseX, m_mouseY);
}

void Application::Draw()
{
    SDL_RenderClear(m_renderer);

    // Draw Calls
    grid->Draw(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 238, 86, 24, 0);
    SDL_RenderPresent(m_renderer);
}
