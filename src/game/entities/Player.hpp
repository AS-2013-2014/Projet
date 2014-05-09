
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

#ifndef PLAYER
#define PLAYER
	class Player: public LivingEntity{
		bool double_jump;
		
		public:
		
		Player(float x=0,float y=0,float z=0, float dx=0, float dy=0);
		void getDoubleJump();
		void doubleJump();
		void landing();
	}
#endif