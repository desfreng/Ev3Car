#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <SFML/Graphics.hpp>

#include "widget/filledarc.h"
#include "widget/arc.h"
#include "widget/colormanager.h"

class RadarWidget : public sf::Transformable,  public sf::Drawable
{
    public:
        RadarWidget (sf::Vector2f size);
        ~RadarWidget();

        void update (int value = 0);

        sf::Vector2f getSize() const;
        int getValue() const;

        void setValue (int value = 0);
        void setFont (sf::Font &font);

    protected:
        const sf::Color Rouge = sf::Color (255, 0, 0);
        const sf::Color Orange = sf::Color (255, 165, 0);
        const sf::Color Jaune = sf::Color (255, 255, 0);
        const sf::Color Vert = sf::Color (0, 140, 0);
        const int maxValue;

        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        sf::RectangleShape _border;
        FilledArc _filledArc;
        Arc _arcs[4];
        ColorManager _degrades[3];

        sf::Font* _font;

	sf::Text _legendes[3];
        int _value;
};

#endif // RADARWIDGET_H
