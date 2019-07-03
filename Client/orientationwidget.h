#ifndef ORIENTATIONWIDGET_H
#define ORIENTATIONWIDGET_H

#include <SFML/Graphics.hpp>

class OrientationWidget :  public sf::Drawable, public sf::Transformable
{
    public:
        OrientationWidget (sf::Vector2f size);
        ~OrientationWidget();

        void update (int rotation = 0);

        sf::Vector2f getSize() const;
        int getRotation() const;

        void setRotation (int value = 0);
        void setFont (sf::Font &font);


    protected:
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        sf::RectangleShape _border;

        sf::ConvexShape _up;
        sf::ConvexShape _down;
        sf::CircleShape _middle;
        sf::CircleShape _circle;

        sf::Font* _font;

        sf::Text _texts[8];
        sf::RectangleShape _lines[8];
};

#endif // ORIENTATIONWIDGET_H
