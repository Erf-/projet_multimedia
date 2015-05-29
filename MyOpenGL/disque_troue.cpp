#include "disque_troue.h"

Disque_troue::Disque_troue(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points, radius, x, y, z)

{
    trou_=Trou(nb_points,0.25,x,y,z);
    taille_=0;
//    texture_=loadtgadisplayCDV("C:/Users/Johanna/Desktop/multimedia/MyOpenGL/bois.tga");
}
Disque_troue::~Disque_troue(){
}

/**
 * @brief Disque_troue::calculDistance
 * @param c
 * @param d
 * @return true ou false si la distance entre les centres permet de creer un cercle interieur
 * la valeur calculee sera implementee dans la variable d
 */
bool Disque_troue::calculDistance(Cercle c){
    Vec v_0 = Vec(this->x_-c.x_, this->y_-c.y_, this->z_-c.z_);
    Vec v_1 = Vec(trou_.x_-c.x_, trou_.y_-c.y_, trou_.z_-c.z_);
    if((norm(v_0)+c.radius_<=this->radius_)&&(norm(v_1)>=trou_.radius_+c.radius_)){
        return true;
    }
    return false;
}

/**
 * @brief Disque_troue::is_addPossible
 * @param c
 * @param d
 * @return true ou false si l'ajout du noouveau voisin est possible ou pas
 * ici on va tester si l'ajout d'un voisin de type cercle (trou ou cible) est possible
 */
bool Disque_troue::is_addPossible(Cible &c){
//    c.z_=z_; ?
    if(taille_==0)
        return calculDistance(c);
    if(norm(Vec(c.x_-trou_.x_,c.y_-trou_.y_,0.0))<(c.radius_+trou_.radius_))
        return false;
    for(int i=0;i<taille_;i++){
        if(norm(Vec(c.x_-cibles_[i].x_,c.y_-cibles_[i].y_,0.0))<(c.radius_+cibles_[i].radius_))
            return false;
    }
    return calculDistance(c);
}

/**
 * @brief Disque_troue::add
 * @param c
 * @return true ou false selon la reussite de l'operation
 */
bool Disque_troue::add(Cible &c){
    if (is_addPossible(c)){
        Cible c1 = Cible(nb_points_, c.radius_, c.x_, c.y_, z_);
        cibles_[taille_]=c1;
        taille_++;
        return true;
    }
    return false;
}
/**
 * @brief Disque_troue::add
 * @return true ou false selon la reussite de l'operation
 * ici on va essayer d'ajouter un trou de maniere aleatoire.
 * Pour cela on rempli les parametres du constructeur de manière aleatoire
 */
void Disque_troue::add(int n){
    srand(time(NULL));
    int k=0;
    while(k!=n){
        double val[3];
        val[0]=rand_a_b(radius_/3,0.2)[0];
        val[1]=rand_a_b(radius_-val[0],-radius_+val[0],2)[0];
        val[2]=rand_a_b(radius_-val[0],-radius_+val[0],2)[1];
        Cible c = Cible(nb_points_,val[0],val[1],val[2],z_);
        if (add(c))
            k++;
    }
}

/**
 * @brief Disque_troue::setTrou
 * @param t
 * @return true ou false en fonction de la reussite de l'operation
 * ici on va initialiser le trou si le trou fourni en entree convient
 */
bool Disque_troue::setTrou(Trou &t){
    t.z_=z_;
    if(norm(Vec(t.x_-x_,t.y_-y_,0.0))+t.radius_>(radius_))
        return false;
    trou_=t;
    return true;
}

/**
 * @brief Disque_troue::draw
 * pour realiser le dessin final, on va d'abord dessiner
 * les cibles puis le trou en transparence
 */
void Disque_troue::draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable( GL_CULL_FACE );
//    glEnable(GL_TEXTURE_2D);

    glColor3f(1,1,1);
//    glBindTexture(GL_TEXTURE_2D, texture_);


    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<nb_points_-1;i++){
        glTexCoord2f((trou_.points_[i][0]/radius_)/2+1/2,(trou_.points_[i][1]/radius_)/2+1/2);
        glVertex3f(trou_.points_[i][0],trou_.points_[i][1],trou_.points_[i][2]);
        glTexCoord2f((points_[i][0]/radius_)/2+1/2,(points_[i][1]/radius_)/2+1/2);
        glVertex3f(points_[i][0],points_[i][1],points_[i][2]);
        glTexCoord2f((trou_.points_[i+1][0]/radius_)/2+1/2,(trou_.points_[i+1][1]/radius_)/2+1/2);
        glVertex3f(trou_.points_[i+1][0],trou_.points_[i+1][1],trou_.points_[i+1][2]);
        glTexCoord2f((points_[i+1][0]/radius_)/2+1/2,(points_[i+1][1]/radius_)/2+1/2);
        glVertex3f(points_[i+1][0],points_[i+1][1],points_[i+1][2]);
    }
    glTexCoord2f((trou_.points_[0][0]/radius_)/2+1/2,(trou_.points_[0][1]/radius_)/2+1/2);
    glVertex3f(trou_.points_[0][0],trou_.points_[0][1],trou_.points_[0][2]);
    glTexCoord2f((points_[0][0]/radius_)/2+1/2,(points_[0][1]/radius_)/2+1/2);
    glVertex3f(points_[0][0],points_[0][1],points_[0][2]);
    glEnd();

//    glDisable(GL_TEXTURE_2D);
    glEnable( GL_CULL_FACE );
    for(int i=0;i<taille_;i++)
        cibles_[i].draw();
}
