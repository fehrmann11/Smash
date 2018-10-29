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
#include "grada.h"
#include <bullet/btBulletDynamicsCommon.h>
#include "crear_y_mover.h"
#include "camera.h"
#include "publico.h"
#include "init.h"
// #include "logicas.h"

#define GL_LOG_FILE "log/gl.log"
#define VERTEX_SHADER_FILE "shaders/test_vs.glsl"
#define FRAGMENT_SHADER_FILE "shaders/test_fs.glsl"

int g_gl_width = 800;
int g_gl_height = 600;
GLFWwindow* g_window = NULL;

// timing
float deltaTime = 0.0f; 
float lastFrame = 0.0f;

int main(){

    init();

    //*-------------------------------LOGICA-------------------------------*/
    						//... por implementar



     /*-------------------------------CREATE SHADERS-----------------------*/
    GLuint shader_programme = create_programme_from_files (VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE);
    int model_mat_location = glGetUniformLocation (shader_programme, "model");


     /*-------------------------------CAMARA-------------------------------*/
    projection = camarita.GetProjection();
    view = camarita.GetView();

    camarita.viewmat(shader_programme);
    camarita.promat(shader_programme);


    while (!glfwWindowShouldClose(g_window)){
        
        // Se aumenta en un paso la simulacion (calculo del dt)
        dynamicsWorld->stepSimulation(1.f / 60.f, 10);
        float currentFrame = glfwGetTime();
        
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(g_window);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram (shader_programme);

    /*-------------------------------DIBUJA OBJETOS-------------------------------*/
        DibujaEsfera(ball,shader_programme,model_mat_location);
        DibujaGrada(grada,shader_programme,model_mat_location);
        DibujaPiso(piso,shader_programme,model_mat_location);
        DibujaPublico(publicoo,shader_programme,model_mat_location);

        camarita.viewmat(shader_programme);
    	camarita.promat(shader_programme);

        glfwSwapBuffers(g_window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


