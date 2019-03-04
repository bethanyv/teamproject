#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Mywindow");
    
    //to call regular window, not darwing window:
    //sf::Window window(sf::VideoMode(800,600), "Mywindow");

    /* Sync app to montiro's refresh rate
    *  to control frame rate and avoid "tearing".*/
    window.setVerticalSyncEnabled(true); //call it once, after creating the window

    /* Game Loop:
    *  run the program as long as the window is open*/
    while (window.isOpen())
    {
        /* Check all the window's events that were triggered 
        *  since the last iteration of the loop */
        sf::Event event;
        while (window.pollEvent(event)) {

            // Check the type of the event
            switch (event.type) {

                // "Close requested" event: we close the window
                case sf::Event::Closed:
                    window.close();
                    break;

                // Window minimized
                case sf::Event::LostFocus:
                    //TODO: Not sure we have a game type named yet
                    myGame.pause();
                
                // Window maximized
                case sf::Event::GainedFocus:
                    //TODO: Not sure we have a game type named yet
                    myGame.resume();

                // Use this to get user input
                case sf::Event::TextEntered:
                    if (event.tet.unicode < 128) {
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                    }
                
                /* WARNING do not use this to get user input!
                *  Use to trigger an action exactly once when
                *  a key is released. */ 

                case sf::Event::KeyPressed:
                    //TODO: FILL IN. Example code just had ...
                    break;
                
                //we don't process other types of events
                default:
                    break;
            }

        }

        /* MANDATORY call to clear before drawing anything
        *  clear the window with black color */
        window.clear(sf::Color::Black);

        //draw everything here ... 
        //window.darw(...);

        // MANDATORY. Need to end the current frame
        window.display();
    }

    return 0;
}
