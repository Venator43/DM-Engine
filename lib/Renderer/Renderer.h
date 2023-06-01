#pragma once

#include "../../include/GL/glew.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define glDebug(x) glClearError();\
        x;\
        ASSERT(glCheckError(#x, __FILE__, __LINE__))

void glClearError(); 
bool glCheckError(char* function, char* file, int line);

class Renderer
{	
	public:
		void draw_line(VertexArray& va, IndexBuffer& ib, Shader& shader) const;
		void clear() const;
};