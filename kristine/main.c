#include <SFML/Window.hpp>

int main() {
    sf::Window window(sf::VideoMode(800,600), "Mywindow");

    /*S ync app to montiro's refresh rate
    * to control frame rate and avoid "tearing".*/
    window.setVerticalSyncEnabled(true); //call it once, after creating the window

    /* Game Loop:
    * run the program as long as the window is open*/
    while (window.isOpen())
    {
        /*check all the window's events that were triggered 
        since the last iteration of the loop */
        sf::Event event;
        while (window.pollEvent(event)) {

            //check the type of the event
            switch (event.type) {

                // "close requested" event: we close the window
                case sf::Event::Closed:
                    window.close();
                    break;
                
                //key pressed
                case sf::Event::KeyPressed:
                    //TODO: FILL IN. Example code just had ...
                    break;
                
                //we don't process other types of events
                default:
                    break;
            }

        }
    }
    return 0;
}