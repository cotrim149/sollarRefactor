#ifndef NAVE_H
#define NAVE_H
#include <GL/glut.h>
#include "SolarUtil.h"

void carregaModeloNave(itemDeJogo *nave){
	nave->posicao.x = 0;
    nave->posicao.y = 0;
    nave->posicao.z = 0;
    nave->rotX = 0;
    nave->rotY = 0;
    nave->rotZ = 0;
    nave->posicaoAnterior.x = 0;
    nave->posicaoAnterior.y = 0;
    nave->posicaoAnterior.z = 0;
    nave->aceleracao = 0.03;
    nave->visivel = TRUE;
    int scala = 0;

    if (!nave->modelo)
    {
            nave->modelo = glmReadOBJ("data/aviao/jato.obj");
            if (!nave->modelo) exit(0);
            glmUnitize(nave->modelo);
            criaCaixaColisao(nave->modelo, &nave->colisao);
            glmFacetNormals(nave->modelo);
            glmVertexNormals(nave->modelo, 90.0);
    }
     for(scala = 0; scala < 8; scala++)
    {
        nave->colisao.pontos[scala].x*=ESCALA_AVIAO;
        nave->colisao.pontos[scala].y*=ESCALA_AVIAO;
        nave->colisao.pontos[scala].z*=ESCALA_AVIAO;
    }

}

void carregaTexturaNave(Texture *texturaNave, char* filePath){
    if(LoadTGA(texturaNave,filePath))
    {
        glGenTextures(1,&texturaNave->texID);
        glBindTexture(GL_TEXTURE_2D, texturaNave->texID);
        glTexImage2D(GL_TEXTURE_2D, 0, texturaNave->bpp / 8, texturaNave->width,
                     texturaNave->height, 0, texturaNave->type, GL_UNSIGNED_BYTE, texturaNave->imageData);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glEnable(GL_TEXTURE_2D);
    }
    else
    {
        printf("\nErro carregando a textura do jato.");
    }

}

#endif
