#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : i_count(count)
{
    glGenBuffers(1, &i_bufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &i_bufferId);
}
void IndexBuffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_bufferId);
}
void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}