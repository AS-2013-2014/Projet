
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s):  récupération vitesse                                       */
/*--------------------------------------------------------------------------*/
/* Description:  classe mère de toutes les entitées pouvant se déplacer     */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef LIVING_ENTITY
#define LIVING_ENTITY
	public class LivingEntity: public Entity{
		
		float dx; // vitesse en x
		float dy; // vitesse en y
		
		public:
			LivingEntity (float x, float y, float z,float dx = 0, float dy = 0);
			float getdx() const;
			float getdy() const;
			void move(float dx, float dy);
	}
#endif