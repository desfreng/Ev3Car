#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>

class Arrow :  public sf::Transformable, public sf::Drawable
{
    public:
        Arrow();
        Arrow (sf::Vector2f size);
        ~Arrow();

    protected:
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        int _height;
        int _width;
        sf::ConvexShape _shape1;
        sf::ConvexShape _shape2;
};
#endif // ARROW_H
