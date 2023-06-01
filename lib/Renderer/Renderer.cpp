#include "Renderer.h"
#include <iostream>

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

void Renderer::draw_line(VertexArray& va, IndexBuffer& ib, Shader& shader) const
{
    shader.bind();
	va.bind();
    ib.bind();
    glDrawElements(GL_LINES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}		

void Renderer::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}