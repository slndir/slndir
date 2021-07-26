#include <header/core/includes.h>
/* Camera*/
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

void processInput(GLFWwindow* window)
{
    const float cameraSpeed = 0.01f; 
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

/* Cube coordinates*/
glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(1.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  0.0f,  0.0f),
    glm::vec3(3.0f,  0.0f,  0.0f),
    glm::vec3(4.0f,  0.0f,  0.0f),
    glm::vec3(5.0f,  0.0f,  0.0f),
    glm::vec3(6.0f,  0.0f,  0.0f),
    glm::vec3(7.0f,  0.0f,  0.0f),
    glm::vec3(8.0f,  0.0f,  0.0f),
    glm::vec3(9.0f,  0.0f,  0.0f),
    glm::vec3(0.0f,  0.0f,  1.0f),
    glm::vec3(1.0f,  0.0f,  1.0f),
    glm::vec3(2.0f,  0.0f,  1.0f),
    glm::vec3(3.0f,  0.0f,  1.0f),
    glm::vec3(4.0f,  0.0f,  1.0f),
    glm::vec3(5.0f,  0.0f,  1.0f),
    glm::vec3(6.0f,  0.0f,  1.0f),
    glm::vec3(7.0f,  0.0f,  1.0f),
    glm::vec3(8.0f,  0.0f,  1.0f),
    glm::vec3(9.0f,  0.0f,  1.0f),
    glm::vec3(0.0f,  0.0f,  2.0f),
    glm::vec3(1.0f,  0.0f,  2.0f),
    glm::vec3(2.0f,  0.0f,  2.0f),
    glm::vec3(3.0f,  0.0f,  2.0f),
    glm::vec3(4.0f,  0.0f,  2.0f),
    glm::vec3(5.0f,  0.0f,  2.0f),
    glm::vec3(6.0f,  0.0f,  2.0f),
    glm::vec3(7.0f,  0.0f,  2.0f),
    glm::vec3(8.0f,  0.0f,  2.0f),
    glm::vec3(9.0f,  0.0f,  2.0f),
    glm::vec3(0.0f,  0.0f,  3.0f),
    glm::vec3(1.0f,  0.0f,  3.0f),
    glm::vec3(2.0f,  0.0f,  3.0f),
    glm::vec3(3.0f,  0.0f,  3.0f),
    glm::vec3(4.0f,  0.0f,  3.0f),
    glm::vec3(5.0f,  0.0f,  3.0f),
    glm::vec3(6.0f,  0.0f,  3.0f),
    glm::vec3(7.0f,  0.0f,  3.0f),
    glm::vec3(8.0f,  0.0f,  3.0f),
    glm::vec3(9.0f,  0.0f,  3.0f),
    glm::vec3(0.0f,  0.0f,  4.0f),
    glm::vec3(1.0f,  0.0f,  4.0f),
    glm::vec3(2.0f,  0.0f,  4.0f),
    glm::vec3(3.0f,  0.0f,  4.0f),
    glm::vec3(4.0f,  0.0f,  4.0f),
    glm::vec3(5.0f,  0.0f,  4.0f),
    glm::vec3(6.0f,  0.0f,  4.0f),
    glm::vec3(7.0f,  0.0f,  4.0f),
    glm::vec3(8.0f,  0.0f,  4.0f),
    glm::vec3(9.0f,  0.0f,  4.0f),
    glm::vec3(0.0f,  0.0f,  5.0f),
    glm::vec3(1.0f,  0.0f,  5.0f),
    glm::vec3(2.0f,  0.0f,  5.0f),
    glm::vec3(3.0f,  0.0f,  5.0f),
    glm::vec3(4.0f,  0.0f,  5.0f),
    glm::vec3(5.0f,  0.0f,  5.0f),
    glm::vec3(6.0f,  0.0f,  5.0f),
    glm::vec3(7.0f,  0.0f,  5.0f),
    glm::vec3(8.0f,  0.0f,  5.0f),
    glm::vec3(9.0f,  0.0f,  5.0f),
    glm::vec3(0.0f,  0.0f,  5.0f),
    glm::vec3(1.0f,  0.0f,  5.0f),
    glm::vec3(2.0f,  0.0f,  5.0f),
    glm::vec3(3.0f,  0.0f,  5.0f),
    glm::vec3(4.0f,  0.0f,  5.0f),
    glm::vec3(5.0f,  0.0f,  5.0f),
    glm::vec3(6.0f,  0.0f,  5.0f),
    glm::vec3(7.0f,  0.0f,  5.0f),
    glm::vec3(8.0f,  0.0f,  5.0f),
    glm::vec3(9.0f,  0.0f,  5.0f),
 
};
float vertices[]
{
    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,   
     0.5f, -0.5f, 0.0f,    1.0f, 0.0f,   
     0.5f,  0.5f, 0.0f,    1.0f, 1.0f,   
    -0.5f,  0.5f, 0.0f,    0.0f, 1.0f,   

    -0.5f, -0.5f, 1.0f,    0.0f, 0.0f,   
     0.5f, -0.5f, 1.0f,    1.0f, 0.0f,   
     0.5f,  0.5f, 1.0f,    1.0f, 1.0f,   
    -0.5f,  0.5f, 1.0f,    0.0f, 1.0f,   

    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
    -0.5f, -0.5f, 1.0f,    1.0f, 0.0f,
    -0.5f,  0.5f, 1.0f,    1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,    0.0f, 1.0f,

     0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
     0.5f, -0.5f, 1.0f,    1.0f, 0.0f,
     0.5f,  0.5f, 1.0f,    1.0f, 1.0f,
     0.5f,  0.5f, 0.0f,    0.0f, 1.0f,

    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,    1.0f, 0.0f,
     0.5f, -0.5f, 1.0f,    1.0f, 1.0f,
    -0.5f, -0.5f, 1.0f,    0.0f, 1.0f,

    -0.5f, 0.5f, 0.0f,     0.0f, 0.0f,
     0.5f, 0.5f, 0.0f,     1.0f, 0.0f,
     0.5f, 0.5f, 1.0f,     1.0f, 1.0f,
    -0.5f, 0.5f, 1.0f,     0.0f, 1.0f,
    
};
unsigned int indices[]
{
    0, 1, 2,
    2, 3, 0,

    4, 5, 6,
    6, 7, 4,

    8, 9, 10,
    10, 11, 8,

    12, 13, 14,
    14, 15, 12,

    16, 17, 18,
    18, 19, 16,

    20, 21, 22,
    22, 23, 20
};
int main(void)
{

    /* Instantiating essential class Obejcts. Header files at header/Window/Window.h, header/Shader/Shader.h, header/data/Texture.h*/
    Window window(800, 600, "OpenGL 3D Application");
    Shader core_shader("shaders/vertex.shader", "shaders/fragment.shader");
    Texture texutre("img/grass.png", true);

    /* Creating MVP matrices for the cubes*/
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)window.window_width / window.window_height, 0.1f, 100.0f);


    /* Essential OpenGL data opjects*/
    VAO VAO;
    VBO VBO(vertices, sizeof(vertices));
    EBO EBO(indices, sizeof(indices));
    VAO.link_layout_VBO(VBO, 0, 3, (void*)0, sizeof(float) * 5);
    VAO.link_layout_VBO(VBO, 1, 2, (void*)(sizeof(float) * 3), sizeof(float) * 5);

    /* openGL proparties*/
    glEnable(GL_DEPTH_TEST);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.window_ID))
    {
        processInput(window.window_ID);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        /* Sending the created matrices to the shader*/
        core_shader.setMat4fv("view", view);
        core_shader.setMat4fv("projection", projection);
        /* Rendering */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f , 0.5f, 0.8f, 1.0f);
        texutre.Bind();
        VAO.Bind();
        /* FOR loop to draw 10 cubes which different model matrices*/
        for (unsigned int i = 0; i < 80; i++)
        {
            
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);

            core_shader.use();
            core_shader.setMat4fv("model", model, false);
               
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
        }
        glfwSwapBuffers(window.window_ID);
        /* Poll for and process events */
        glfwPollEvents();

    }

    /* Program Ending*/
    glfwDestroyWindow(window.window_ID);
    glfwTerminate();
    return 0;
}