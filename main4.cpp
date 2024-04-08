#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

const double pi = 3.1415;

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Technicolor Spiral", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);

        float starting_x =0;
        float starting_y= 0;

        for (int deg = 0; deg < 1440; deg++)
        {
            glColor3f(cos(static_cast<float>(deg) * pi / 180), sin(static_cast<float>(deg) * pi / 180), .5); //color modulation
            float x = cos(static_cast<float>(deg)* pi/180)*deg/1440; //basically the amplitude of the sin and cosin keep increasing up to 1
            float y = sin(static_cast<float>(deg) * pi / 180)*deg/1440;
            //std::cout << "x: " << x << "  y: " << y << "   " << deg << std::endl;
            glVertex2f(starting_x, starting_y);
            glVertex2f(x, y);
            starting_x = x;
            starting_y = y;     
        }
          
        glEnd();



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}