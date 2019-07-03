#ifndef COLORMANAGER_H
#define COLORMANAGER_H

#include <cmath>
#include <SFML/Graphics/Color.hpp>


class ColorManager
{
    public:
        ColorManager (sf::Color couleurDebut = sf::Color::White, sf::Color couleurFin = sf::Color::Black, double max = 100.0);

        sf::Color getColor (double value);

        void setBeginColor (const sf::Color &color);
        void setEndColor (const sf::Color &color);
        void setValue (const double value);

    private:
        sf::Color _debut;
        sf::Color _fin;
        double _max;
};

#endif // COLORMANAGER_H
