
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): recup�ration coordon�es                                     */
/*--------------------------------------------------------------------------*/
/* Description:  classe m�re de toutes les entit�es                         */
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