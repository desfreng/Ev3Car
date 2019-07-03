#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

#include "guipad.h"
#include "orientationwidget.h"
#include "radarwidget.h"

class MyWindow : sf::RenderWindow
{
    public:
        MyWindow (int antialiasing = 16);
        ~MyWindow();

        int exec();

        void addDrawable (sf::Drawable* value);
        void clearDrawable();

    private:

        void updateDrawing();
        sf::Thread thread;

        std::vector<sf::Drawable*> _drawable;

        RadarWidget _radarZone;
        GuiPad _motorZone;
        OrientationWidget _gyroZone;
        sf::RectangleShape _textZone;
        sf::RectangleShape _ev3Zone;

        sf::Font _font;
        sf::Text _text;
};

#endif // MYWINDOW_H
