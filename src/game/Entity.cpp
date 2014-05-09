
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

public class Entity(
	private:
	float x,y,z;
	public:
	Entity(float x,float y,float z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
	float getx (){
		return x;
	}
	float gety (){
		return y;
	}
	float getz (){
		return z;
	}
)