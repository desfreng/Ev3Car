#ifndef QUAD_H
#define QUAD_H

#include <SFML/Graphics.hpp>

class Quad : public sf::Transformable, public sf::Drawable
{
    public:
        Quad (sf::Vector2f point1 = sf::Vector2f (0, 0), sf::Vector2f point2 = sf::Vector2f (0, 0), sf::Vector2f point3 = sf::Vector2f (0, 0), sf::Vector2f point4 = sf::Vector2f (0, 0));

        sf::Vector2f &operator[] (std::size_t index);

        void setColor (const sf::Color &color);
        const sf::Color &getColor() const;

    protected:
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
        sf::Vertex vertex[4];
};

#endif // QUAD_H
