#include "filledarc.h"

using namespace sf;

FilledArc::FilledArc() : _radius (0), _angle (0)
{
        update();
}

void FilledArc::setRadius (const int radius)
{
        _radius = radius;
        update();
}
const int FilledArc::getRadius() const
{
        return _radius;
}
void FilledArc::setAngle (const int angle)
{
        _angle = angle;
        update();
}
const int FilledArc::getAngle() const
{
        return _angle;
}

std::size_t FilledArc::getPointCount() const
{
        return _points.size();
}
sf::Vector2f FilledArc::getPoint (std::size_t index) const
{
        return _points[index];
}

void FilledArc::update()
{
        _points.clear();
        _points.push_back (Vector2f (0, 0));

        for (double i = 0; i < _angle + 1; i+=1) {
                _points.push_back (Vector2f (std::cos ( (90 - 0.5 * _angle + i) *M_PI / 180.0) *_radius, std::sin ( (90 - 0.5 * _angle + i) *M_PI / 180.0) *-_radius));
        }

        Shape::update();
}



















