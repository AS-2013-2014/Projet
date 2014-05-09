
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): récupération et affectation du bool de double jump          */
/*--------------------------------------------------------------------------*/
/* Description:  joueur                                                     */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

public class Player: public LivingEntity{
	bool double_jump;
	
	Player(float x , float y , float z , float dx , float dy){
		LivingEntity(x,y,z,dx,dy);
		double_jump = false;
	}
	
	bool getDoubleJump(){
		return double_jump;
	}
	
	void doubleJump(){
		double_jump = true;
	}
	
	void landing(){
		double_jump = false;
	}
}