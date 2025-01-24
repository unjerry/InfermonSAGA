#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window;
    window = glfwCreateWindow(800, 600, "depsTestWindow", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::invalid_argument("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    GladGLContext *gl;
    gl = (GladGLContext *)calloc(1, sizeof(GladGLContext));
    if (!gl)
    {
        throw std::invalid_argument("Failed to create context");
    }

    int version = gladLoadGLContext(gl, glfwGetProcAddress);
    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    // if ()
    // {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     throw std::invalid_argument("Failed to initialize GLAD");
    // }
    // framebuffer_size_callback = default_framebuffer_size_callback;
    // key_callback = processInput;
    // glfwSetFramebufferSizeCallback(window, this->framebuffer_size_callback);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwMakeContextCurrent(window);
        // input
        // -----
        glfwPollEvents();
        // render
        // ------
        gl->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        gl->Clear(GL_COLOR_BUFFER_BIT);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
    }

    return 0;
}
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    // if (key >= 0 && key < 1024)
    // {
    //     if (action == GLFW_PRESS)
    //         Breakout.Keys[key] = true;
    //     else if (action == GLFW_RELEASE)
    //         Breakout.Keys[key] = false;
    // }
}
