#ifndef FILLEDARC_H
#define FILLEDARC_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class FilledArc : public sf::Shape
{
    public :
        FilledArc();

        void setRadius (const int radius);
        const int getRadius() const;

        void setAngle (const int angle);
        const int getAngle() const;

        std::size_t getPointCount() const;
        sf::Vector2f getPoint (std::size_t index) const;

    protected:
        void update();

    private :
        int _radius;
        int _angle;

        std::vector<sf::Vector2f> _points;

};

#endif // FILLEDARC_H
