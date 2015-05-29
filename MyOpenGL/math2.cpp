#include "math2.h"

Vec::Vec(double x, double y, double z){
    x_=x;
    y_=y;
    z_=z;
}
/**
 * @brief Vec::angle
 * @param v
 * @return
 * ici on retourne la valeur orintee de l'angle de u vers v
 */
GLdouble Vec::angle(Vec v){
    Vec a = Vec(x_,y_,z_)*(1/normV());
    Vec b = v*(1/v.normV());
    if(a.pscalV(b.orth())*a.pscalV(b.orth())!=1.0){
        return acos(a.pscalV(b))*int(a.pscalV(b.orth())>0)-acos(a.pscalV(b))*int(a.pscalV(b.orth())<0)+M_PI*int(a.pscalV(b)==0);
    }
    return M_PI/2;
}

namespace math2
{
    GLdouble pscal(Vec a, Vec b){
        return Math2::pscal(a, b);
    }
    GLdouble norm(Vec a){
        return Math2::norm(a);
    }
    /*GLdouble dist(Vec a, Vec b){
        return Math2::dist(a, b);
    }*/
    /**
     * @brief rand_a_b
     * @param b
     * @param a
     * @param n
     * @param save
     * @return un tableau de valeurs
     * fonction de generation aleatoire
     * lorsque save est a true on sauvegarde
     * le tableau de valeur cad que lorsque
     * l'on rappelle la fonction il renvoie
     * les memes valeurs
     */
    double * rand_a_b(double b, double a, const int n, bool save){
        if(save)
            srand(time(NULL));
        double res[n];
        for(int i=0; i<n; i++){
            res[i]=(rand()/(double)RAND_MAX)*(b-a) +a;
        }
        return res;
    }
    GLdouble angle(Vec u, Vec v){
        return u.angle(v);
    }
    GLuint loadtgadisplayCDV ( const char* filename )
    {
        FILE* fp;
        char magic[12];
        unsigned char header[6];
        int imageSize;
        GLenum type;
        char temp;
        int i;
        int bpp,width,height;
        GLuint textureId;
        int globalWidth = 1;
        int globalHeight = 1;
        char* imageData;
        char* imageTmp;
        if(!(fp = fopen(filename, "rb"))) return 0;
        if(!fread(&magic, 12, 1, fp)) return 0;
        if(!fread(&header, 6, 1, fp)) return 0;
        bpp = header[4];
        width  = header[1] * 256 + header[0];
        height = header[3] * 256 + header[2];
        if(width <= 0 || height <= 0) return 0;
        if(bpp != 24 && bpp != 32) return 0;
        imageSize = width * height * (bpp / 8);
        imageData = (char *)malloc(sizeof(char) * imageSize);
        if(imageData == NULL) return 0;
        if(!fread(imageData, imageSize, 1, fp)) { free(imageData); return 0; }
        for(i = 0; i < imageSize; i += bpp / 8) {
        temp = imageData[i];
        imageData[i] = imageData[i + 2];
        imageData[i + 2] = temp; }
        if(bpp == 32) for(i=0;i<imageSize;i+=4) imageData[i+3]=255-imageData[i+3];
        fclose(fp);
        while (width>globalWidth) globalWidth*=2;
        while (height>globalHeight) globalHeight*=2;
        glEnable( GL_TEXTURE_2D );
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glPixelStorei(GL_UNPACK_ROW_LENGTH,globalWidth);
        glPixelStorei(GL_UNPACK_ALIGNMENT,1);
        if(bpp == 24) type=GL_RGB; else type=GL_RGBA;
        imageTmp = (char *)malloc(sizeof(char)*globalWidth*globalHeight*4);
        if (imageTmp==NULL) return 0;
        glTexImage2D(GL_TEXTURE_2D,0,type,globalWidth,globalHeight,0,
        type,GL_UNSIGNED_BYTE,imageTmp);
        free (imageTmp );
        glPixelStorei(GL_UNPACK_ROW_LENGTH,width);
        glTexSubImage2D(GL_TEXTURE_2D,0, 0,0, width, height,
        type ,GL_UNSIGNED_BYTE, imageData );
        free(imageData);
        return textureId;
    }


}
