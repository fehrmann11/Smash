#include <assimp/cimport.h> // C importer
#include <assimp/scene.h> // collects data
#include <assimp/postprocess.h> // various extra operations
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "gl_utils.h"
#include "tools.h"
#include "malla.h"
#include "GLDebugDrawer.hpp"
#include "esfera.h"
#include "piso.h"
#include "camera.h"
#include "grada.h"
#include "publico.h"
#include <bullet/btBulletDynamicsCommon.h>
#include <stdlib.h>
#include <time.h>
#define GL_LOG_FILE "log/gl.log"
#define VERTEX_SHADER_FILE "shaders/test_vs.glsl"
#define FRAGMENT_SHADER_FILE "shaders/test_fs.glsl"

/*-------------------------------// CREA OBJETOS // -----------------------------*/
 Esfera esferadef(1.0,-6,0.1,0,1.0);
 Esfera esferadef1(1.0,6,0.1,0,1.0);
 Esfera esferadef2(1.0,0,0.1,5,1.0);
 Esfera esferadef3(1.0,0,0.1,-5,1.0);
 Piso pisodef(8,0,6.5,0,0,-2,0);
 Grada gradita(4.0f,0.1f,2.0f,0.0f,6.0f,-5.0f,0.0f);
 Grada gradita2(4.0f,0.1f,2.0f,0.0f,8.0f,-5.0f,0.0f);
 Publico publi(1.0f,1.6f,-2.5f,7.0f,-5.0f,1.0f);
 Publico publi2(1.0f,1.6f,0.0f,7.0f,-5.0f,1.0f);
 Publico publi3(1.0f,1.6f,2.5f,7.0f,-5.0f,1.0f);

 glm::mat4 projection;
 glm::mat4 view;

/*-------------------------------// CREA OBJETO CAMARA //-------------------------------*/
 Camera camarita(glm::vec3(0.0f, 10.0f, 11.0f),glm::vec3(-0.0026795f, -0.714323f, -0.714323f),glm::vec3(0.0f, 10.0f, 0.0f));

 

void processInput(GLFWwindow *window){

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    //PELOTA 1

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        esferadef.body->applyForce(btVector3(0,0,-10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        esferadef.body->applyForce(btVector3(0,0,10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        esferadef.body->applyForce(btVector3(-10,0,0),btVector3(1, 0, 0));

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      	esferadef.body->applyForce(btVector3(10,0,0),btVector3(1, 0, 0));

    //PELOTA 2

    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
        esferadef1.body->applyForce(btVector3(0,0,-10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        esferadef1.body->applyForce(btVector3(0,0,10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        esferadef1.body->applyForce(btVector3(-10,0,0),btVector3(1, 0, 0));

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
        esferadef1.body->applyForce(btVector3(10,0,0),btVector3(1, 0, 0));

    //PELOTA 3

    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        esferadef2.body->applyForce(btVector3(0,0,-10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        esferadef2.body->applyForce(btVector3(0,0,10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        esferadef2.body->applyForce(btVector3(-10,0,0),btVector3(1, 0, 0));

    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        esferadef2.body->applyForce(btVector3(10,0,0),btVector3(1, 0, 0));

    //PELOTA 4

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        esferadef3.body->applyForce(btVector3(0,0,-10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
       esferadef3.body->applyForce(btVector3(0,0,10),btVector3(0, 0, 1));

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        esferadef3.body->applyForce(btVector3(-10,0,0),btVector3(1, 0, 0));

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
       esferadef3.body->applyForce(btVector3(10,0,0),btVector3(1, 0, 0));

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
       esferadef3.body->applyForce(btVector3(10,0,0),btVector3(1, 0, 0));

   	//Diferentes vistas de camara

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
       camarita.CambiarFov(45.0f);
   	   camarita.SetProjection();
   	   projection= camarita.GetProjection();

   	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
       camarita.CambiarFov(55.0f);
   	   camarita.SetProjection();
   	   projection= camarita.GetProjection();


   	if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
   		camarita.Actualizar(glm::vec3(0.0f, 10.0f, 11.0f),glm::vec3(-0.0026795f, -0.714323f, -0.714323f),glm::vec3(0.0f, 10.0f, 0.0f));
        camarita.SetView();
        view=camarita.GetView();

   	if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
   		camarita.Actualizar(glm::vec3(0.0f, 10.0f, 14.0f),glm::vec3(-0.0026795f, -0.514323f, -0.914323f),glm::vec3(0.0f, 10.0f, 0.0f));
        camarita.SetView();
        view=camarita.GetView();


  //para el publico
    srand(time(NULL));
    int x=1;
    int ale=rand()%3;
    int ale2=rand()%2;
    int ale3=rand()%4;
    	if (x==ale)
        	publi.body->applyCentralImpulse(btVector3(0,0.2,0));
        if (x==ale2)
        	publi2.body->applyCentralImpulse(btVector3(0,0.2,0));
        if (x==ale3)
        	publi3.body->applyCentralImpulse(btVector3(0,0.2,0));
}

void DibujaEsfera(malla*ball,GLuint shader_programme, int model_mat_location ){

        esferadef.Dibujar(ball,shader_programme, model_mat_location);
        esferadef1.Dibujar(ball,shader_programme,model_mat_location);
        esferadef2.Dibujar(ball,shader_programme,model_mat_location);
        esferadef3.Dibujar(ball,shader_programme,model_mat_location);
}
void DibujaPiso(malla*piso,GLuint shader_programme, int model_mat_location ){

        pisodef.Dibujar(piso,shader_programme,model_mat_location);

}

void DibujaGrada(malla*grada,GLuint shader_programme, int model_mat_location ){

        gradita.Dibujar(grada,shader_programme,model_mat_location);
        gradita2.Dibujar(grada,shader_programme,model_mat_location);
}


void DibujaPublico(malla*publicoo,GLuint shader_programme, int model_mat_location ){

        publi.Dibujar(publicoo,shader_programme,model_mat_location);
        publi2.Dibujar(publicoo,shader_programme,model_mat_location);
        publi3.Dibujar(publicoo,shader_programme,model_mat_location);

}

