#include "Renderer.h"
#include "BufferLayout.h"
#include <iostream>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &rendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &rendererID);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const BufferLayout& layout)
{
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for(unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
    	glVertexAttribPointer(i, element.count, element.type, element.normalize, layout.getStride(), (const void*)offset);
    	offset += element.count * LayoutElement::getTypeSize(element.type);
    }
}

void VertexArray::bind() const 
{
	glBindVertexArray(rendererID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
