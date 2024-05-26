#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Window.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Renderer/Shader.h"


namespace Hazel {

	class HAZEL_API Application
	{
	public:

		Application();
		virtual ~Application();
		inline static Application& Get() { return *s_Instance; }
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		void Run();
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		bool KeyLog(KeyPressedEvent& e);

		static Application* s_Instance;

		LayerStack m_LayerStack;

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		float color[3] = { 0, 0, 0 };
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}