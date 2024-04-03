#pragma once
#include "stdio.h"
#include <string>
namespace Hazel {
	class Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		unsigned int m_RendererID;
	};
}