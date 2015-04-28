
#include "sphere.h"

sphere::sphere (float alpha, float rouge, float vert, float bleu, float rayon, float pas, int pasCarX, int pasCarY)
{
	// Inutile de selancer dans des calculs compliqués pour rendre unitaire notre vecteur normal.
	bNormalize = true;

	// Initiliser les pas
	definirPas (pas, pasCarX, pasCarY);

	// Initialiser les rayons
	definirRayons (rayon, rayon, rayon);

	// Définition des couleurs
	couleurF (alpha, rouge, vert, bleu);

}

void sphere::genere (int mode)
{
	if (mode != SPH_BOING)
		spheroide::genere(mode);
	else
	{
		if (uiDispLst != GL_INVALID_VALUE && uiDispLst != GL_INVALID_OPERATION && glIsList(uiDispLst))
		{
			glNewList(uiDispLst, GL_COMPILE);

			boingBall ();
			gereCouleur(false);;

			glEndList();
		}
	}
}

void sphere::boingBall (void)
{
	  BOOL bDessineV=false;
	  int iCpt1 = 0, iCpt = 0;

      glBegin(GL_QUADS);

	  for (a =0.f; a <= PI; a+=pas)
	  {
		  z = cosf(a);
		  z1 = cosf(a + pas);
		  z2=z;

		  BOOL bDessineH=bDessineV;

		  iCpt1++;
		  if (iCpt1 >= pasCarreY)
		  {
			  if (bDessineV)
					bDessineV = false;
			  else
					bDessineV = true;
			  iCpt1=0;
		  }

		  iCpt = pasCarreX;

		  for (b=-PI; b <= PI; b+=pas)
		  {
			
			  iCpt++;
	  		  if (iCpt >= pasCarreX)
			  {
				  if (bDessineH)
				  {
						glColor3f (1.f,0.f,0.f);
						bDessineH = false;
				  }
				  else
				  {
						glColor3f (1.f,1.f,1.f);
						bDessineH = true;
				  }
				  iCpt = 0;
			  }

			  x = sinf (a) * cosf(b);			  
			  y = sinf (a) * sinf(b);

			  x1 = sinf (a + pas) * cosf(b);
			  y1 = sinf (a + pas) * sinf(b);

			  glNormal3f(x, y, z);
			  glVertex3f(rx*x,ry*y,rz*z);

			  if (b + pas >= PI) // Fin de la boucle, on va tracer un trait entre les derniers points calculés et les tous premiers points tracés
			  {
				  glVertex3f(rx*x1,ry*y1,rz*z1) ;

				  x = sinf (a+ pas) * cosf(-PI);
			  
				  y = sinf (a+ pas) * sinf(-PI);	  
				  glVertex3f(rx*x,ry*y,rz*z1) ;

 				  x2 = sinf (a) * cosf(-PI);		  

				  y2 = sinf (a) * sinf(-PI);
				  glVertex3f(rx*x2,ry*y2,rz*z2) ;
			  }
			  else
			  {			
				  glVertex3f(rx*x1,ry*y1,rz*z1);

				  x = sinf (a + pas) * cosf(b + pas);
			  
				  y = sinf (a + pas) * sinf(b + pas);
				  glVertex3f(rx*x,ry*y,rz*z1) ;

 				  x2 =sinf (a) * cosf(b + pas);		  

				  y2 =sinf (a) * sinf(b + pas);
				  glVertex3f(rx*x2,ry*y2,rz*z2) ;
			  }
		  }	  
	}
	glEnd ();
}