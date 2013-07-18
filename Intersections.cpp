#include "Intersections.h"

Intersections::Intersections(void)
{
}

Intersections::~Intersections(void)
{
}

bool Intersections::intersectPixel(const sf::Sprite& s1, const sf::Sprite& s2, const int AlphaMax)
{
	// Définition deux objets représentant les dimensions de s1 et s2.
    sf::Vector2f pos = s1.GetPosition() - s1.GetCenter();
    const sf::FloatRect r1(pos.x, pos.y, pos.x + s1.GetSize().x, pos.y + s1.GetSize().y);
    pos = s2.GetPosition() - s2.GetCenter();
    const sf::FloatRect r2(pos.x, pos.y, pos.x + s2.GetSize().x, pos.y + s2.GetSize().y);
 
    // Espace de collision potentiel.
    sf::FloatRect zone;
 
    // Testons si les Sprites se superposent.
    if (r1.Intersects(r2, &zone))
    {
        if (AlphaMax >= 0)
        {
            int left1 = (int)(zone.Left - r1.Left);
            int top1 = (int)(zone.Top - r1.Top);
 
            int left2 = (int)(zone.Left - r2.Left);
            int top2 = (int)(zone.Top - r2.Top);
 
            int width = (int)(zone.GetWidth());
            int height = (int)(zone.GetHeight());
 
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (s1.GetPixel(x+left1, y+top1).a > AlphaMax && s2.GetPixel(x+left2, y+top2).a > AlphaMax)
                        return true;
                }
            }
 
            return false;
        }
 
        return true;
    }
 
    return false;

}
