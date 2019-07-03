#include "orientationwidget.h"
#include "general.h"

using namespace sf;

OrientationWidget::OrientationWidget (Vector2f size)
{
        Transformable();

        if (size.x > size.y) {
                _border.setSize (Vector2f (size.y, size.y));
        } else {
                _border.setSize (Vector2f (size.x, size.x));
        }

        _border.setFillColor (Color::Transparent);
        _border.setOutlineColor (Color::Black);
        _border.setOutlineThickness (1);
        _border.setPosition (0, 0);

        _circle.setRadius (_border.getSize().x * 0.4);
        _circle.setPointCount (40);
        _circle.setOrigin (_circle.getRadius(), _circle.getRadius());
        _circle.setPosition (_border.getSize().x / 2, _border.getSize().y / 2);
        _circle.setFillColor (Color::Transparent);
        _circle.setOutlineThickness (5);
        _circle.setOutlineColor (Color::Black);

        _middle.setRadius (_border.getSize().x * 0.025);
        _middle.setOrigin (_middle.getRadius(), _middle.getRadius());
        _middle.setPosition (_border.getSize().x / 2, _border.getSize().y / 2);
        _middle.setFillColor (Color::Black);
        _middle.setOutlineThickness (0);

        int height = _border.getSize().x * 0.33;
        int width = _border.getSize().x * 0.108;

        _up.setPointCount (3);
        _up.setPoint (0, Vector2f (width / 2, 0));
        _up.setPoint (1, Vector2f (width, height));
        _up.setPoint (2, Vector2f (0, height));
        _up.setFillColor (Color (200, 40, 40));
        _up.setOutlineThickness (0);
        _up.setOrigin (width / 2, height);
        _up.setPosition (_circle.getPosition());

        _down = _up;
        _down.setRotation (180);
        _down.setFillColor (Color (205, 205, 205));

}

OrientationWidget::~OrientationWidget()
{

}

void OrientationWidget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
        states.transform *= getTransform();
        target.draw (_border, states);
        target.draw (_circle, states);
        target.draw (_up, states);
        target.draw (_down, states);

        for (int i = 0; i < 8; i++) {
                target.draw (_lines[i], states);
                target.draw (_texts[i], states);
        }

        target.draw (_middle, states);

}

void OrientationWidget::update (int rotation)
{
        setRotation (rotation + getRotation());
}

int OrientationWidget::getRotation() const
{
        return _up.getRotation();
}

void OrientationWidget::setRotation (int value)
{
        _up.setRotation (value % 360);
        _down.setRotation ( (value + 180) % 360);
}

sf::Vector2f OrientationWidget::getSize() const
{
        return _border.getSize();
}

void OrientationWidget::setFont (sf::Font& font)
{
        _font = &font;

        for (int i = 0; i < 8; i++) {
                _lines[i].setSize (Vector2f (4, _circle.getRadius() * 0.14));
                _lines[i].setFillColor (Color::Black);
                _lines[i].setOutlineThickness (0);
                _lines[i].setOutlineColor (Color::Black);
                _lines[i].setOrigin (_lines[i].getSize().x / 2, 0);
                _lines[i].setRotation (i * 45);
                _lines[i].setPosition (_circle.getPoint (i * _circle.getPointCount() / 8));
                _lines[i].move (_border.getSize().x * 0.5 - _circle.getRadius(), _border.getSize().y * 0.5 - _circle.getRadius());

                _texts[i].setFont (*_font);
                _texts[i].setFillColor (Color::Black);
                _texts[i].setCharacterSize (25);
                _texts[i].setOutlineThickness (0);
                _texts[i].setString (std::to_string (i * 45) + L"°");

                if (i >= 3 && i <= 5) {
                        _texts[i].setOrigin (_texts[i].getGlobalBounds().width / 2, -5);
                        _texts[0].setRotation (0);
                } else {
                        _texts[i].setOrigin (_texts[i].getGlobalBounds().width / 2, _texts[i].getGlobalBounds().height + 15);
                        _texts[i].setRotation (i * 45);
                }

                _texts[i].setPosition (_lines[i].getPosition());


        }

        _texts[3].setRotation (315);
        _texts[4].setRotation (0);
        _texts[5].setRotation (45);

}
