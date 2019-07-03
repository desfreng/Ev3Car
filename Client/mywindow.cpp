#include "mywindow.h"
#include "general.h"
#include <iostream>

using namespace sf;

MyWindow::MyWindow (int antialiasing) :
        thread (&MyWindow::updateDrawing, this),
        _radarZone (Vector2f (WidgetSize, WidgetSize)),
        _motorZone (Vector2f (WidgetSize, WidgetSize * 1.4)),
        _gyroZone (Vector2f (WidgetSize, WidgetSize))
{
        _font.loadFromMemory (font_ttf, font_ttf_size);

        create (VideoMode (3 * WidgetSize + 40, 2 * WidgetSize + 30), "Ev3Control", Style::Default, ContextSettings (0, 0, antialiasing));

        _radarZone.setPosition (10, 10);
        _radarZone.setFont (_font);
        addDrawable (&_radarZone);

        _gyroZone.setPosition (10, WidgetSize + 20);
        _gyroZone.setFont (_font);
        addDrawable (&_gyroZone);

        _motorZone.setPosition (2 * WidgetSize + 30, 10);
        addDrawable (&_motorZone);

        _textZone.setSize (Vector2f (2 * WidgetSize + 10, (2 * WidgetSize) - _motorZone.getSize().y));
        _textZone.setPosition (WidgetSize + 20, _motorZone.getSize().y + 20);
        _textZone.setFillColor (Color::Transparent);
        _textZone.setOutlineThickness (1);
        _textZone.setOutlineColor (Color::Black);
        addDrawable (&_textZone);

        _ev3Zone.setSize (Vector2f (WidgetSize,  _motorZone.getSize().y));
        _ev3Zone.setPosition (WidgetSize + 20, 10);
        _ev3Zone.setFillColor (Color::Transparent);
        _ev3Zone.setOutlineThickness (1);
        _ev3Zone.setOutlineColor (Color::Black);
        addDrawable (&_ev3Zone);

        _text =  Text ("", _font);
        _text.setPosition (10, 10);
        addDrawable (&_text);

        setActive (false);

        thread.launch();

}
MyWindow::~MyWindow()
{
        thread.wait();
        clearDrawable();
}

void MyWindow::addDrawable (sf::Drawable* value)
{
        _drawable.push_back (value);
}

void MyWindow::clearDrawable()
{
        for (auto a : _drawable) {
                a = nullptr;
        }

        _drawable.clear();

}

int MyWindow::exec()
{
        while (isOpen()) {
                Event event;

                while (pollEvent (event)) {
                        switch (event.type) {
                                case Event::Closed:
                                        close();
                                        break;

                                default:
                                        break;
                        }
                }

                _motorZone.update();
                _gyroZone.update ();
                _radarZone.update();
        }

        return 0;
}

void MyWindow::updateDrawing ()
{
        setActive (true);
//         int i = 0;

        while (isOpen()) {
                clear (BackColor);

                for (auto a : _drawable) {
                        draw (*a);
                }

//                 if (i > 5) {
//                         i = 0;
//                         _radarZone.update (1);
//                 }
//
//                 _gyroZone.update (1);
//
//                 i++;
                display();
        }
}




