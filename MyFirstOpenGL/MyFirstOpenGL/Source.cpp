#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>



#define WINDOW_WIDTH 640
#define WINDOW_HEIGH 480


void ResizeWindow(GLFWwindow* window,int iFrameBufferWidth, int iNewFrameBufferHeight)
{
    //definir nuevo tamaño del viewport 


    glViewport(0, 0, iFrameBufferWidth, iNewFrameBufferHeight);
}

void main()
{



    GLFWwindow* window;

    /* Initialize the library */
    glfwInit();
    

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGH, "Hello World", NULL, NULL);
    // PRIMER NULL ES PARA EN Q VENTANA SE RENDERIZA EN FULLSCREEN
                                                                    // EL SEGUNDO NULL ES PARA PASAR INFO DE VENTANA A VENTANA

    glfwSetFramebufferSizeCallback(window, ResizeWindow);




    //definir ventana en la que trabajar 
    glfwMakeContextCurrent(window);

    
    //activo funciones esperimentales para todas las graficas (especialmente antiguas)
    glewExperimental = GL_TRUE;
    


    if (glewInit() == GLEW_OK)
    {

        //definir color buffer 

        glClearColor(1.f, 0.f, 0.f, 1.f);




        GLuint vaoPuntos, vboPuntos;

        //geenra 1 vao y almacena referencia de vaopuntos
        glGenVertexArrays(1, &vaoPuntos);

        //activa vaopntos para trabaajar
        glBindVertexArray(vaoPuntos);

        // genero 1 vbo y alamceno referencia vboPuntos
        glGenBuffers(1, &vboPuntos);

        //indico que vbo es el activo y que este almacena array de datos
        glBindBuffer(GL_ARRAY_BUFFER, vboPuntos);

        //decalro puntoas
        GLfloat punto[] = { 0.f,0.f };



        //vuelve el array en el vbo 
        glBufferData(GL_ARRAY_BUFFER, sizeof(punto), punto, GL_STATIC_DRAW);



        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);




        glEnableVertexAttribArray(0);


        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

        while (!glfwWindowShouldClose(window))
        {
            //pulleamos eventos

            glfwPollEvents();







            //clean buffer 
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            glBindVertexArray(vaoPuntos);

            glDrawArrays(GL_POINTS, 0,1);

            glBindVertexArray(0);



            //CHANGE BUFFER
            glFlush();//comprobar si se ha puintado todo o ready para el cancvio cmo vsync
            glfwSwapBuffers(window);
        }
        std::cout << "Ha furulado" << std::endl;
    }
    else
    {
        std::cout << "hizo pum" << std::endl;
        glfwTerminate();
    }

    glfwTerminate();
}



