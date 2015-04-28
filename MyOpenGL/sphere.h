

#define SPH_BOING    5

#include "spheroide.h"

// La sphère est une spécialisation d'un sphéroide.
class sphere:public spheroide
{
	// Equation de la sphère:
	// x = x0 + r sin a cos b
	// y = y0 + r sin a sin b
	// z = z0 + r cos a
	// avec 0<=a<=pi et -pi < b <= pi
	// Dans notre cas, r est toujours = 1, ce qui permet de faire un vecteur normal unitaire pour le cas d'utilisation des lumières
	// Le rayon sera alors utilisé lors d'un transformation de notre sphère par homotéthie.

   	public :
   	sphere(float alpha = 1.0f, float rouge = 1.f, float vert = 1.f, float bleu = 1.f, float rayon = 5.0f, float pas = 0.024f /*0.0925f*/, int pasCarX = 10, int pasCarY = 10) ; // Constructeur, sont indiqués les valeurs à prendre par défaut si l’appel au contructeur se fait sans valeur)
   	~sphere (void) ; // Destructeur
	void genere (int mode = SPH_MAILLEHV);

	protected:
   	void boingBall (void) ;
};
