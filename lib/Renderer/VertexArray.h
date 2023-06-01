#pragma once

#include "VertexBuffer.h"

class BufferLayout;

class VertexArray
{
	private:
		unsigned int rendererID;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(const VertexBuffer& vb, const BufferLayout& layout);

		void bind() const;
		void unbind() const;
};