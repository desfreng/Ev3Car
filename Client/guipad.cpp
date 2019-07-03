#include "guipad.h"
#include "general.h"

using namespace sf;

GuiPad::GuiPad (Vector2f size)
{
        Transformable();

        if (size.x * PadRapport > size.y) {
                _border.setSize (Vector2f (static_cast<int> (size.y / PadRapport), size.y));
        } else {
                _border.setSize (Vector2f (size.x, static_cast<int> (size.x * PadRapport)));
        }

        _size = _border.getSize().x / 4.0;
        _padding = (_border.getSize().x - 3 * _size) / 4;

        _border.setFillColor (Color::Transparent);
        _border.setOutlineColor (Color::Black);
        _border.setOutlineThickness (1);
        _border.setPosition (0, 0);

        for (int i = 0; i < 5; i++) {
                _pad[i] = RectangleShape (Vector2f (_size, _size));
                _pad[i].setOrigin (_size / 2, _size / 2);
        }

        _pad[0].setPosition (_size + _padding + _size / 2, _size / 2);  //Up
        _pad[1].setPosition (2 * (_size + _padding) + _size / 2, _size + _padding + _size / 2); // Right
        _pad[2].setPosition (_size + _padding + _size / 2 , 2 * (_size + _padding) + _size / 2); //Down
        _pad[3].setPosition (_size / 2, _size + _padding + _size / 2); //Left
        _pad[4].setPosition (_size + _padding + _size / 2, _size + _padding + _size / 2); // Middle

        for (int i = 0; i < 5; i++) {
                _pad[i].move (_padding, _padding);
                deactivate (_pad[i]);
        }


        for (int i = 0; i < 4; ++i) {
                _padShapes[i] = ConvexShape();
                _padShapes[i].setPointCount (4);
                _padShapes[i].setPoint (0, Vector2f ( (_size - _padding / 4.0) / 2.0, 0));
                _padShapes[i].setPoint (1, Vector2f ( (_size - _padding / 4.0), 2 * (_size - _padding / 4.0) / 3.0));
                _padShapes[i].setPoint (2, Vector2f ( (_size - _padding / 4.0) / 2.0, (_size - _padding / 4.0) / 6.0));
                _padShapes[i].setPoint (3, Vector2f (0, 2 * (_size - _padding / 4.0) / 3.0));
                _padShapes[i].setFillColor (Color::Black);
                _padShapes[i].setOrigin ( (_size - _padding / 4.0) / 2.0, (_size - _padding / 4.0) / 3.0);
                _padShapes[i].setPosition (_pad[i].getPosition());
                _padShapes[i].setRotation (i * 90);
        }

        _padShapes[4] = ConvexShape();
        _padShapes[4].setPointCount (8);
        _padShapes[4].setPoint (0, Vector2f ( (_size - _padding / 2.0) / 5.0, 0));
        _padShapes[4].setPoint (1, Vector2f (4 * (_size - _padding / 2.0) / 5.0, 0));
        _padShapes[4].setPoint (2, Vector2f ( (_size - _padding / 2.0), (_size - _padding / 2.0) / 5.0));
        _padShapes[4].setPoint (3, Vector2f ( (_size - _padding / 2.0), 4 * (_size - _padding / 2.0) / 5.0));
        _padShapes[4].setPoint (4, Vector2f (4 * (_size - _padding / 2.0) / 5.0, (_size - _padding / 2.0)));
        _padShapes[4].setPoint (5, Vector2f ( (_size - _padding / 2.0) / 5.0, (_size - _padding / 2.0)));
        _padShapes[4].setPoint (6, Vector2f (0, 4 * (_size - _padding / 2.0) / 5.0));
        _padShapes[4].setPoint (7, Vector2f (0, (_size - _padding / 2.0) / 5.0));
        _padShapes[4].setFillColor (Color::Black);
        _padShapes[4].setOrigin ( (_size - _padding / 2.0) / 2.0, (_size - _padding / 2.0) / 2.0);
        _padShapes[4].setPosition (_pad[4].getPosition());

        _padShapes[5] = _padShapes[4];
        _padShapes[5].setScale (0.9, 0.9);
        _padShapes[5].setFillColor (BackColor);

        _line = VertexArray (Lines, 2);
        _line[0].position = Vector2f (_padding / 2, getSize().x);
        _line[1].position = Vector2f (getSize().x - (_padding / 2), getSize().x);

        _line[0].color = Color::Black;
        _line[1].color = Color::Black;

        _sizeD = (getSize().y - getSize().x) * 2.0 / 3.0;
        _paddingDY = _sizeD / 4.0;
        _paddingDX = (getSize().x - 4 * _sizeD) / 5.0;

        for (int i = 0; i < 4; i++) {
                _downPad[i].setSize (Vector2f (_sizeD, _sizeD));
                _downPad[i].setOrigin (_sizeD / 2, _sizeD / 2);
                _downPad[i].setPosition ( (i + 1) *_paddingDX  + i * _sizeD + _sizeD / 2, getSize().x + _paddingDY + _sizeD / 2);
                deactivate (_downPad[i]);

                _arrow[i] = Arrow (Vector2f (_sizeD - _paddingDY, _sizeD - _paddingDY));
                _arrow[i].setPosition (_downPad[i].getPosition());
        }

        _arrow[0].setRotation (0); //Up
        _arrow[1].setRotation (90); //Right
        _arrow[2].setRotation (180); //Down
        _arrow[3].setRotation (270); //Left
}

GuiPad::~GuiPad() {}

void GuiPad::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
        states.transform *= getTransform();
        target.draw (_border, states);

        for (int i = 0; i < 5; i++) {
                target.draw (_pad[i], states);
                target.draw (_padShapes[i], states);
        }

        target.draw (_padShapes[5], states);

        target.draw (_line, states);

        for (int i = 0; i < 4; i++) {
                target.draw (_downPad[i], states);
                target.draw (_arrow[i], states);
        }
}

void GuiPad::update ()
{

        if (Keyboard::isKeyPressed (Keyboard::Up))  {
                activate (_pad[0]);

        } else {
                deactivate (_pad[0]);
        }

        if (Keyboard::isKeyPressed (Keyboard::Down))  {
                activate (_pad[2]);
        } else {
                deactivate (_pad[2]);
        }

        if (Keyboard::isKeyPressed (Keyboard::Left))  {
                activate (_pad[3]);
        } else {
                deactivate (_pad[3]);
        }

        if (Keyboard::isKeyPressed (Keyboard::Right))  {
                activate (_pad[1]);
        } else {
                deactivate (_pad[1]);
        }

        if (Keyboard::isKeyPressed (Keyboard::Space))  {
                activate (_pad[4]);
                _padShapes[5].setFillColor (_pad[4].getFillColor());
        } else {
                deactivate (_pad[4]);
                _padShapes[5].setFillColor (_pad[4].getFillColor());
        }

        if (Keyboard::isKeyPressed (Keyboard::U))  {
                activate (_downPad[0]);
        } else {
                deactivate (_downPad[0]);
        }

        if (Keyboard::isKeyPressed (Keyboard::R))  {
                activate (_downPad[1]);
        } else {
                deactivate (_downPad[1]);
        }

        if (Keyboard::isKeyPressed (Keyboard::D))  {
                activate (_downPad[2]);
        } else {
                deactivate (_downPad[2]);
        }

        if (Keyboard::isKeyPressed (Keyboard::L))  {
                activate (_downPad[3]);
        } else {
                deactivate (_downPad[3]);
        }
}

void GuiPad::activate (sf::Shape& shape)
{
        shape.setFillColor (Color (255, 210, 210));
        shape.setOutlineColor (Color::Red);
        shape.setOutlineThickness (2);
}

void GuiPad::deactivate (sf::Shape& shape)
{
        shape.setFillColor (BackColor);
        shape.setOutlineColor (Color::Transparent);
        shape.setOutlineThickness (0);
}

sf::Vector2f GuiPad::getSize() const
{
        return _border.getSize();
}
