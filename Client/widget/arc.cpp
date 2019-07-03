#include "arc.h"
#include <iostream>

using namespace sf;

Arc::Arc (double radius, int angle) : _radius (radius), _angle (angle), _thickness (1.0), _color (Color::Black), _quads()
{
        Transformable();
        updateDrawing();
}

void Arc::setAngle (const int angle)
{
        _angle = angle;
        updateDrawing();
}

void Arc::setRadius (const double radius)
{
        _radius = radius;
        updateDrawing();
}

void Arc::setColor (const sf::Color& color)
{
        _color = color;
        updateDrawing();
}

void Arc::setThickness (const double thickness)
{
        _thickness = thickness;
        updateDrawing();
}

const double Arc::getThickness() const
{
        return _thickness;
}

const sf::Color& Arc::getColor() const
{
        return _color;
}

const int Arc::getAngle() const
{
        return _angle;
}

const double Arc::getRadius() const
{
        return _radius;
}

void Arc::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
        states.transform *= getTransform();

        for (double i = 0; i < _angle; i++) {

                Quad temp;
                temp[0] = Vector2f (std::cos (i * M_PI / 180.0) * _radius, std::sin (i * M_PI / 180.0) * _radius);
                temp[1] = Vector2f (std::cos (i * M_PI / 180.0) * (_radius + _thickness), std::sin (i * M_PI / 180.0) * (_radius + _thickness));
                temp[2] = Vector2f (std::cos ( (i + 1) * M_PI / 180.0) * (_radius + _thickness), std::sin ( (i + 1)  * M_PI / 180.0) * (_radius + _thickness));
                temp[3] = Vector2f (std::cos ( (i + 1) * M_PI / 180.0) * _radius, std::sin ( (i + 1)  * M_PI / 180.0) * _radius);

                temp.setColor (_color);

                target.draw (temp, states);
        }
}

void Arc::updateDrawing()
{

}

