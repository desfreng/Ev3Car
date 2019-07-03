#ifndef ARC_H
#define ARC_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "quad.h"

class Arc : public sf::Drawable, public sf::Transformable
{
    public :

        Arc (double radius = 90, int angle = 100);

        void setRadius (const double radius);
        const double getRadius() const;

        void setAngle (const int angle);
        const int getAngle() const;

        void setColor (const sf::Color &color);
        const sf::Color &getColor() const;

        void setThickness (const double thickness);
        const double getThickness() const;

    protected:
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

    private :
        void updateDrawing();

        double _radius;
        int _angle;
        double _thickness;
        sf::Color _color;
        std::vector<Quad> _quads;
};


#endif // ARC_H
