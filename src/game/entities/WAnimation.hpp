
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: graphic                                                       */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Une animation                                               */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_WANIMATION
#define H_WANIMATION

#include "Graphic.hpp"
#include "../../misc/Resources.hpp"

class WAnimation : public Graphic
{
	public:
		WAnimation(int x, int y, float z, int w, int h, int r, const std::string& file, int wc, int hc, float fps, bool loop = true);

    virtual void frame(float time);

    void play();
    void stop();

    bool isPlaying(){ return playing; }

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Sprite sprite;
		int wc, hc;
    bool playing, loop;
		float fps;
		float elapsed, frame_time;
    sf::Vector2f size;
		int current;
};

#endif
