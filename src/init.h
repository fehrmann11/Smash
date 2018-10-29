    /*-------------------------------// DEFINICIONES DE MALLAS Y MUNDO //-------------------------------*/

 malla *ball;
 malla *piso;
 malla *grada;
 malla *publicoo;
 btDiscreteDynamicsWorld* dynamicsWorld;

void init(){

    restart_gl_log ();
    start_gl ();
    glEnable (GL_DEPTH_TEST); 
    glDepthFunc (GL_LESS); 
    glEnable (GL_CULL_FACE); 
    glCullFace (GL_BACK); 
    glFrontFace (GL_CCW); 
    glClearColor (0.2, 0.2, 0.2, 1.0); 
    glViewport (0, 0, g_gl_width, g_gl_height);

   /*-------------------------------// CREA LAS MALLAS//-------------------------------*/
    ball = new malla((char*)"mallas/ball.obj");
    piso = new malla((char*)"mallas/pista.obj");
    grada= new malla((char*)"mallas/grada.obj");
    publicoo= new malla((char*)"mallas/publico.obj");

    /*-------------------------------// Configuracion inical del mundo fisico Bullet //-------------------------------*/
    btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
    btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -10, 0));

    /*-------------------------------// Crea cuerpo fisica de los objetos //-------------------------------*/
    pisodef.CrearPiso(dynamicsWorld);
    esferadef.CrearEsfera(dynamicsWorld);
    esferadef1.CrearEsfera(dynamicsWorld);
    esferadef2.CrearEsfera(dynamicsWorld);
    esferadef3.CrearEsfera(dynamicsWorld);
    gradita.CrearGrada(dynamicsWorld);
    gradita2.CrearGrada(dynamicsWorld);
    publi.CrearPublico(dynamicsWorld);
    publi2.CrearPublico(dynamicsWorld);
    publi3.CrearPublico(dynamicsWorld);
}