#pragma once

#include <Vector>
#include "Renderer.h"

struct LayoutElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalize;

	static unsigned int getTypeSize(unsigned int type)
	{
		switch(type)
		{
			case GL_FLOAT:
				return 4;
			case GL_UNSIGNED_INT:
				return 4;
			case GL_UNSIGNED_BYTE:
				return 1;
		}
		return 0;
	}
};

class BufferLayout
{
	private:
		std::vector<LayoutElement> m_Elements;
		unsigned int m_Stride;
	public:
		BufferLayout() 
			:m_Stride(0){};

		inline unsigned int getStride() const
		{
			return m_Stride;
		}

		inline const std::vector<LayoutElement> getElements() const&
		{
			return m_Elements;
		}

		template<typename T> void Push(unsigned int count)
		{
		}
};

template<> inline void BufferLayout::Push<float>(unsigned int count)
{
	m_Elements.push_back({GL_FLOAT,count,GL_FALSE});
	m_Stride += LayoutElement::getTypeSize(GL_FLOAT) * count;
}

template<> inline void BufferLayout::Push<unsigned int>(unsigned int count)
{
	m_Elements.push_back({GL_UNSIGNED_INT,count,GL_FALSE});
	m_Stride += LayoutElement::getTypeSize(GL_UNSIGNED_INT) * count;
}

template<> inline void BufferLayout::Push<unsigned char>(unsigned int count)
{
	m_Elements.push_back({GL_UNSIGNED_BYTE,count,GL_TRUE});
	m_Stride += LayoutElement::getTypeSize(GL_UNSIGNED_BYTE) * count;
}
