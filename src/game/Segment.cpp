#include "Segment.hpp"


float Segment::getSlope() const { return slope; }
float Segment::getOrigin() const { return origin; }
sf::Vector2f Segment::getP1() const { return p1; }
sf::Vector2f Segment::getP2() const { return p2; }
bool Segment::isVertical() const { return vertical; }

Segment::Segment() {}

Segment::Segment(sf::Vector2f a, sf::Vector2f b) {
    if(a.x == b.x) {
        vertical = true;
        // agencement selon y
        p1 = (a.y <= b.y) ? a : b;
        p2 = (a.y <= b.y) ? b : a;
    }
    else {
        vertical = false;
        // agencement selon x
        p1 = (a.x <= b.x) ? a : b;
        p2 = (a.x <= b.x) ? b : a;
        // paramètres de la droite
        slope = (p2.y-p1.y)/(p2.x-p1.x);
        origin = p1.y - slope*p1.x;
    }
}

bool Segment::intersect(Segment s) const {
    if(vertical) {
        if(s.isVertical()) return false; // cas de 2 segments verticaux
        float inter = s.getSlope()*p1.x + s.getOrigin(); // intersection en y
        return inter >= p1.y && inter <= p2.y && s.getP1().x <= p1.x && s.getP2().x >= p1.x;
    }
    if(s.isVertical()) {
        float inter = slope*s.getP1().x + origin; // intersection en y
        return inter >= s.getP1().y && inter <= s.getP2().y && p1.x <= s.getP1().x && p2.x >= s.getP1().x;
    }
    float inter = (s.getOrigin()-origin)/(slope-s.getSlope()); // intersection en x
    return inter >= p1.x && inter <= p2.x && inter >= s.getP1().x && inter <= s.getP2().x;
}

void Segment::draw(sf::RenderWindow &w) const {
    sf::Vertex vertices[] = {
        sf::Vertex(p1, sf::Color::Black),
        sf::Vertex(p2, sf::Color::Black)
    }; w.draw(vertices, 2, sf::Lines);
}

