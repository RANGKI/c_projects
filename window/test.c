#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
// gpt code ahh
int main(void)
{
    if (!glfwInit()) {
        printf("Failed to init GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(
        640, 480, "My Title", NULL, NULL
    );

    if (!window) {
        printf("Failed to create window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

