#include "hzpch.h"
#include "OpenGlBuffer.h"
#include "glad/glad.h"

namespace Hazel {

	//VERTEX BUFFER
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
 
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(GL_ARRAY_BUFFER, &m_RendererID);
	}
	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}
	void OpenGLVertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	//INDEX BUFFEr

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
		: m_Count(count)
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);

	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RendererID);
	}
	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);

	}
	void OpenGLIndexBuffer::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
