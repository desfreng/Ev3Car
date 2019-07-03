#include "radarwidget.h"

#define thickness 2

using namespace sf;

RadarWidget::RadarWidget (Vector2f size) : maxValue (size.x * 0.72)
{
        Transformable();

        if (size.x > size.y) {
                _border.setSize (Vector2f (size.y, size.y));
        } else {
                _border.setSize (Vector2f (size.x, size.x));
        }

        _degrades[0] = ColorManager (Rouge, Orange, 34);
        _degrades[1] = ColorManager (Orange, Jaune, 33);
        _degrades[2] = ColorManager (Jaune, Vert, 33);

        _border.setFillColor (Color::Transparent);
        _border.setOutlineColor (Color::Black);
        _border.setOutlineThickness (1);
        _border.setPosition (0, 0);

        _filledArc.setAngle (85);
        _filledArc.setPosition (_border.getSize().x / 2, (_border.getSize().y + maxValue) / 2.0);
        _filledArc.setOutlineThickness (0);
        _filledArc.setOutlineColor (Color::Transparent);
        setValue (100);

        for (int i = 0; i < 4; i++) {
                _arcs[i].setRadius (maxValue * (i + 1) * 0.25);
                _arcs[i].setAngle (_filledArc.getAngle());
                _arcs[i].setPosition (_filledArc.getPosition());
                _arcs[i].setRotation (227.5);
                _arcs[i].setColor (Color::Black);
                _arcs[i].setThickness (2);
        }
}

RadarWidget::~RadarWidget()
{
}

sf::Vector2f RadarWidget::getSize() const
{
        return _border.getSize();
}

int RadarWidget::getValue() const
{
        return _value;
}

void RadarWidget::setValue (int value)
{
        _value = value % 101;

        int radius =  _value * 0.0095 * maxValue + maxValue * 0.05;

        _filledArc.setRadius (radius);

        if (_value <= 34) {
                _filledArc.setFillColor (_degrades[0].getColor (_value));
        } else if (_value <= 67) {
                _filledArc.setFillColor (_degrades[1].getColor (_value - 34));
        } else if (_value <= 100) {
                _filledArc.setFillColor (_degrades[2].getColor (_value - 67));
        }

}
void RadarWidget::update (int value)
{
        setValue (value + _value);
}


void RadarWidget::setFont (sf::Font& font)
{
        _font = &font;

        for (int i = 0; i < 3; i++) {
                _legendes[i].setFont (*_font);
                _legendes[i].setOutlineThickness (0);
                _legendes[i].setFillColor (Color::Black);
                _legendes[i].setCharacterSize (25);
                _legendes[i].setString (std::to_string ( (i + 1) * 25) + L"%");
                _legendes[i].setOrigin (_legendes[i].getGlobalBounds().width / 2.0, 0);
                _legendes[i].setRotation (312.5);
                _legendes[i].setPosition (_border.getSize().x / 2 + maxValue * (i + 1) * 0.17, (_border.getSize().y + maxValue) / 2.0 + -maxValue * (i + 1) * 0.185);
        }
}

void RadarWidget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
        states.transform *= getTransform();
        target.draw (_border, states);
        target.draw (_filledArc, states);

        for (int i = 0 ; i < 4 ; i++) {
                target.draw (_arcs[i], states);
        }

        target.draw (_legendes[0], states);
        target.draw (_legendes[1], states);
        target.draw (_legendes[2], states);

}
