#include <hzpch.h>
#include "Buffer.h"
#include "glad/glad.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGlBuffer.h"

namespace Hazel {

	
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(Renderer::GetAPI()) 
		{
			
		case RendererAPI::None :
		{
			return nullptr;
		}
		case RendererAPI::OpenGL :
			return new OpenGLVertexBuffer(vertices, size);
		}

		HZ_ASSERT(false, "Unknown Renderer");
		return nullptr;
	}
	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{

		case RendererAPI::None:
		{
			return nullptr;
		}
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, size);
		}

		HZ_ASSERT(false, "Unknown Renderer");
		return nullptr;
	}
}