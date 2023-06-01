#include <iostream>
#include <string>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

#include "lib/Renderer/VertexBuffer.h"
#include "lib/Renderer/IndexBuffer.h"
#include "lib/Renderer/BufferLayout.h"
#include "lib/Renderer/VertexArray.h"
#include "lib/Renderer/Shader.h"
#include "lib/Renderer/Renderer.h"

#include "include/glm/glm/glm.hpp"
#include "include/glm/glm/trigonometric.hpp"

using namespace std;

float degToRad(float deg)
{
    return deg/(180/3.141592);
}

struct vec3d
{
    float x, y, z;
};

struct triangle
{
    vec3d p[3];

    float* get2DVec()
    {
        float* vec2D = new float[6];
        int ii = 0;
        for(int i = 0;i < 3; i++)
        {
            vec2D[0+ii] = p[i].x;
            vec2D[1+ii] = p[i].y;
            ii += 2;
        }

        return vec2D;
    } 
};

struct mesh
{
    vector<triangle> tris;

    int getTris2DVecSize()
    {
        return 6*tris.size();
    } 

    float* get2DVec()
    {
        float* vec2D = new float[6*tris.size()];
        int ii = 0;
        for(triangle tria : tris) 
        {
            for(int i = 0;i < 3; i++)
            {
                vec2D[0+ii] = tria.p[i].x;
                vec2D[1+ii] = tria.p[i].y;
                ii += 2;
            }
        }
        return vec2D;
    }
};

struct mat4x4
{
    float m[4][4] = { {0} };
};

void MatrixCrossProduct(vec3d &i, vec3d &o, mat4x4 &m)
    {
        o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
        o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
        o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
        float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

        if (w != 0.0f)
        {
            o.x /= w; o.y /= w; o.z /= w;
        }
    }


int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        cout << "Failed To Initialize Library" << endl;
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        cout << "Faile To Create Window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (GLEW_OK != glewInit())
    {
      cout << stderr << "Error" ;
    }
    
    mesh meshCube;

    meshCube.tris = {

        // SOUTH
        { 0.0f, 0.0f, 0.0f,    0.0f, 0.5f, 0.0f,    0.5f, 0.5f, 0.0f },
        { 0.0f, 0.0f, 0.0f,    0.5f, 0.5f, 0.0f,    0.5f, 0.0f, 0.0f },

        // EAST                                                      
        { 0.5f, 0.0f, 0.0f,    0.5f, 0.5f, 0.0f,    0.5f, 0.5f, 0.5f },
        { 0.5f, 0.0f, 0.0f,    0.5f, 0.5f, 0.5f,    0.5f, 0.0f, 0.5f },

        // NORTH                                                     
        { 0.5f, 0.0f, 0.5f,    0.5f, 0.5f, 0.5f,    0.0f, 0.5f, 0.5f },
        { 0.5f, 0.0f, 0.5f,    0.0f, 0.5f, 0.5f,    0.0f, 0.0f, 0.5f },

        // WEST                                                      
        { 0.0f, 0.0f, 0.5f,    0.0f, 0.5f, 0.5f,    0.0f, 0.5f, 0.0f },
        { 0.0f, 0.0f, 0.5f,    0.0f, 0.5f, 0.0f,    0.0f, 0.0f, 0.0f },

        // TOP                                                       
        { 0.0f, 0.5f, 0.0f,    0.0f, 0.5f, 0.5f,    0.5f, 0.5f, 0.5f },
        { 0.0f, 0.5f, 0.0f,    0.5f, 0.5f, 0.5f,    0.5f, 0.5f, 0.0f },

        // BOTTOM                                                    
        { 0.5f, 0.0f, 0.5f,    0.0f, 0.0f, 0.5f,    0.0f, 0.0f, 0.0f },
        { 0.5f, 0.0f, 0.5f,    0.0f, 0.0f, 0.0f,    0.5f, 0.0f, 0.0f },

    };
    // cout << meshCube.tris.size() << endl;
    float* coor = meshCube.get2DVec();

    int indexToRender = 36;
    unsigned int* indexBuffer = new unsigned int[(indexToRender * 2)];
    int ii = 0;
    cout << indexToRender << endl;
    for(int i = 0;i < indexToRender; i++)
    {
       indexBuffer[0+ii] = i;
       indexBuffer[1+ii] = i+1;
       ii += 2;
    }
    for(int i = 0;i < indexToRender * 2; i++)
    {
       cout << indexBuffer[i] << endl;
    }
    //Vertex array object are used in order to save the binding oh the vertex buffer layout into a single object
    VertexArray va;
    VertexBuffer vb(coor, (indexToRender * 2) * sizeof(float));
    
    BufferLayout layout;
    layout.Push<float>(2);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indexBuffer, (indexToRender * 2));

    Shader shader("basic.shader");

    shader.setUniform4f("uniformColor",0.0, 0.0, 0.0, 1.0);
    double r = 1, g = 0, b = 0;

    Renderer renderer;

    float fTheta;
    mat4x4 matProj;

    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = 640.0f / 480.0f;
    float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

    matProj.m[0][0] = fAspectRatio * fFovRad;
    matProj.m[1][1] = fFovRad;
    matProj.m[2][2] = fFar / (fFar - fNear);
    matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    matProj.m[2][3] = 1.0f;
    matProj.m[3][3] = 0.0f;

    float fElapsedTime = 0;

    while (!glfwWindowShouldClose(window))
    {
        fElapsedTime += 0.01;

        mat4x4 matRotZ, matRotX;
        fTheta += 0.0166666667f;

        // Rotation Z
        matRotZ.m[0][0] = cosf(fTheta);
        matRotZ.m[0][1] = sinf(fTheta);
        matRotZ.m[1][0] = -sinf(fTheta);
        matRotZ.m[1][1] = cosf(fTheta);
        matRotZ.m[2][2] = 1;
        matRotZ.m[3][3] = 1;
    
        // Rotation X
        matRotX.m[0][0] = 1;
        matRotX.m[1][1] = cosf(fTheta * 0.5f);
        matRotX.m[1][2] = sinf(fTheta * 0.5f);
        matRotX.m[2][1] = -sinf(fTheta * 0.5f);
        matRotX.m[2][2] = cosf(fTheta * 0.5f);
        matRotX.m[3][3] = 1;

        renderer.clear();
        int ii = 0;
        for (auto tri : meshCube.tris)
        {
            triangle triProjected, triTranslated, triRotatedZ, triRotatedZX;
    
            // Rotate in Z-Axis
            MatrixCrossProduct(tri.p[0], triRotatedZ.p[0], matRotZ);
            MatrixCrossProduct(tri.p[1], triRotatedZ.p[1], matRotZ);
            MatrixCrossProduct(tri.p[2], triRotatedZ.p[2], matRotZ);
        
            // Rotate in X-Axis
            MatrixCrossProduct(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
            MatrixCrossProduct(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
            MatrixCrossProduct(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);
        
            // Offset into the screen
            triTranslated = triRotatedZX;
            triTranslated.p[0].z = triRotatedZX.p[0].z + 3.0f;
            triTranslated.p[1].z = triRotatedZX.p[1].z + 3.0f;
            triTranslated.p[2].z = triRotatedZX.p[2].z + 3.0f;
        
            // Project triangles from 3D --> 2D
            MatrixCrossProduct(triTranslated.p[0], triProjected.p[0], matProj);
            MatrixCrossProduct(triTranslated.p[1], triProjected.p[1], matProj);
            MatrixCrossProduct(triTranslated.p[2], triProjected.p[2], matProj);
        
            // Scale into view
            // triProjected.p[0].x += 0.5f; triProjected.p[0].y += 0.5f;
            // triProjected.p[1].x += 0.5f; triProjected.p[1].y += 0.5f;
            // triProjected.p[2].x += 0.5f; triProjected.p[2].y += 0.5f;
            // triProjected.p[0].x *= 0.25f * 640.0f;
            // triProjected.p[0].y *= 0.25f * 480.0f;
            // triProjected.p[1].x *= 0.25f * 640.0f;
            // triProjected.p[1].y *= 0.25f * 480.0f;
            // triProjected.p[2].x *= 0.25f * 640.0f;
            // triProjected.p[2].y *= 0.25f * 480.0f;

            coor[0 + ii] = triProjected.p[0].x;
            coor[1 + ii] = triProjected.p[0].y;
            coor[2 + ii] = triProjected.p[1].x;
            coor[3 + ii] = triProjected.p[1].y;
            coor[4 + ii] = triProjected.p[2].x;
            coor[5 + ii] = triProjected.p[2].y; 
            ii += 6;
        }

        // coor = meshCube.get2DVec();
        glBufferData(GL_ARRAY_BUFFER, (indexToRender * 2) * sizeof(float), coor, GL_DYNAMIC_DRAW);

        shader.setUniform4f("uniformColor", r, g, b, 1.0);

        renderer.draw_line(va,ib,shader);

        // if((int)r != 1)
        // {
        //     r += 0.15;
        // }
        // else if((int)g != 1)
        // {
        //     r -= 0.1;
        //     g += 0.15;
        // }
        // else if((int)b != 1)
        // {
        //     g -= 0.1;
        //     b += 0.15;
        // }
        // else
        // {
        //     r = 0.1;
        //     g = 0.1;
        //     b = 0.1;
        // }

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}