#include "quad.h"

using namespace sf;

Quad::Quad (Vector2f point1, Vector2f point2, Vector2f point3, Vector2f point4)
{
        vertex[0].position = point1;
        vertex[1].position = point2;
        vertex[2].position = point3;
        vertex[3].position = point4;

        setColor (Color::Black);
}

void Quad::setColor (const sf::Color& color)
{
        vertex[0].color = color;
        vertex[1].color = color;
        vertex[2].color = color;
        vertex[3].color = color;
}

const sf::Color& Quad::getColor() const
{
        return vertex[0].color;
}

sf::Vector2f& Quad::operator[] (std::size_t index)
{
        return vertex[index].position;
}

void Quad::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
        states.transform *= getTransform();
        VertexArray tri (sf::TriangleStrip, 4);

        tri[0] = vertex[1];
        tri[1] = vertex[0];
        tri[2] = vertex[2];
        tri[3] = vertex[3];

        target.draw (tri, states);
}
