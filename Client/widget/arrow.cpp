#include "arrow.h"
#define Rapport 1.66

using namespace sf;

Arrow::Arrow() {}

Arrow::Arrow (Vector2f size)
{
        if (size.x * Rapport > size.y) {
                _height = size.y ;
                _width = size.y / Rapport;
        } else {
                _height = size.x * Rapport;
                _width = size.x ;
        }

        setOrigin (_width / 2, _height / 2);

        _shape1 =  ConvexShape();
        _shape1.setPointCount (3);
        _shape1.setPoint (0, Vector2f (0, _height / 2.5));
        _shape1.setPoint (1, Vector2f (_width / 2.0, 0));
        _shape1.setPoint (2, Vector2f (_width, _height / 2.5));
        _shape1.setFillColor (Color::Black);

        _shape2 =  ConvexShape();
        _shape2.setPointCount (4);
        _shape2.setPoint (0, Vector2f (_width / 3.0, _height / 2.5));
        _shape2.setPoint (1, Vector2f (_width / 3.0, _height));
        _shape2.setPoint (2, Vector2f (2.0 * _width / 3.0, _height));
        _shape2.setPoint (3, Vector2f (2.0 * _width / 3.0, _height / 2.5));
        _shape2.setFillColor (Color::Black);
}

Arrow::~Arrow()
{
}

void Arrow::draw (RenderTarget& target, RenderStates states) const
{
        states.transform *= getTransform();
        target.draw (_shape1, states);
        target.draw (_shape2, states);
}

