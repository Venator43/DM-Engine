#include "GL/glew.h"
#include <iostream>

#pragma once

#define ASSERT(x) if (!(x)) __debugbreak();
#define glDebug(x) glClearError();\
        x;\
        ASSERT(glCheckError(#x, __FILE__, __LINE__))

void glClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

bool glCheckError(char* function, char* file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout << file << ":" << line << " on " << function << " : " << "Error Code:" << error << "\n";
        return false;
    }
    return true;
}