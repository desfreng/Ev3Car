#include "colormanager.h"
#include <stdexcept>

using namespace sf;

ColorManager::ColorManager (sf::Color couleurDebut, sf::Color couleurFin, double max) : _debut (couleurDebut), _fin (couleurFin), _max (max)
{
}

void ColorManager::setBeginColor (const sf::Color& color)
{
        _debut = color;
}

void ColorManager::setEndColor (const sf::Color& color)
{
        _fin = color;
}

void ColorManager::setValue (const double value)
{
        _max = value;
}

sf::Color ColorManager::getColor (double value)
{
        if (value > _max) {
                throw std::invalid_argument ("Value is out limits");
        } else {
                double deltaRouge = static_cast<double> (_fin.r) - static_cast<double> (_debut.r);
                double deltaVert = static_cast<double> (_fin.g) - static_cast<double> (_debut.g);
                double deltaBleu = static_cast<double> (_fin.b) - static_cast<double> (_debut.b);

                double rouge = static_cast<double> (_debut.r) + (deltaRouge / _max * value);
                double vert = static_cast<double> (_debut.g) + (deltaVert / _max * value);
                double bleu = static_cast<double> (_debut.b) + (deltaBleu / _max * value);

                return Color (rouge, vert, bleu);
        }

}
