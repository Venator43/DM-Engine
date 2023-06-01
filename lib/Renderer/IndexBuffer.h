#pragma once

class IndexBuffer
{
	private:
		unsigned int i_bufferId;
		unsigned int i_count;
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void bind();
		void unbind();

		inline unsigned int getCount() const 
		{
			return i_count; 
		}
};