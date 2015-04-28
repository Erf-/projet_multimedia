

#define SPH_BOING    5

#include "spheroide.h"

// La sph�re est une sp�cialisation d'un sph�roide.
class sphere:public spheroide
{
	// Equation de la sph�re:
	// x = x0 + r sin a cos b
	// y = y0 + r sin a sin b
	// z = z0 + r cos a
	// avec 0<=a<=pi et -pi < b <= pi
	// Dans notre cas, r est toujours = 1, ce qui permet de faire un vecteur normal unitaire pour le cas d'utilisation des lumi�res
	// Le rayon sera alors utilis� lors d'un transformation de notre sph�re par homot�thie.

   	public :
   	sphere(float alpha = 1.0f, float rouge = 1.f, float vert = 1.f, float bleu = 1.f, float rayon = 5.0f, float pas = 0.024f /*0.0925f*/, int pasCarX = 10, int pasCarY = 10) ; // Constructeur, sont indiqu�s les valeurs � prendre par d�faut si l�appel au contructeur se fait sans valeur)
   	~sphere (void) ; // Destructeur
	void genere (int mode = SPH_MAILLEHV);

	protected:
   	void boingBall (void) ;
};
