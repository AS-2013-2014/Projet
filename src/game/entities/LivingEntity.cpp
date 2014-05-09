
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

Public class LivingEntity : public Entity {
	public:
	float dx,dy;
	
	LivingEntity(float x, float y, float z,float dx, float dy){
		Entity(x,y,z);
		this.dx = dx;
		this.dy = dy;
	}
	
	float getdx(){
		return dx;
	}
	float getdy(){
		return dy;
	}
	void move(float dx , float dy ){
		this.dx = dx;
		this.dy = dy;
		x += dx;
		y += dy;
	}
}