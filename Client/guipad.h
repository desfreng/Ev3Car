#ifndef GUIPAD_H
#define GUIPAD_H

#include <SFML/Graphics.hpp>
#include "widget/arrow.h"

class GuiPad :  public sf::Transformable,  public sf::Drawable
{
    public:

        GuiPad (sf::Vector2f size);
        ~GuiPad();

        void update();

        sf::Vector2f getSize() const;

    protected:
        int _padding;
        int _size;

        int _paddingDY;
        int _paddingDX;
        int _sizeD;

        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        void activate (sf::Shape &shape);
        void deactivate (sf::Shape &shape);

        sf::RectangleShape _border;

        sf::ConvexShape _padShapes[6];
        sf::RectangleShape _pad[5];

        sf::VertexArray _line;

        sf::RectangleShape _downPad[4];

        Arrow _arrow[4];
};

#endif // GUIPAD_H

