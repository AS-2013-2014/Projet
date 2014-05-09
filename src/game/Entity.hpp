
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): recupération coordonées                                     */
/*--------------------------------------------------------------------------*/
/* Description:  classe mère de toutes les entitées                         */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifned ENTITY
#define ENTITY
	public class Entity{
		float x; //coordonnées en x
		float y; //coordonnées en y
		float z; //coordonnées en z
		
		public:
			Entity(int x=0; int y=0; int z=0;);
			float getx() const;
			float gety() const;
			float getz() const;
	}
#endif