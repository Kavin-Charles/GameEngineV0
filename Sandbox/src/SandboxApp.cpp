#include <Hazel.h>
#include "imgui.h"
class GameLayer : public Hazel::Layer
{
public: 
	float color[3];

	GameLayer() : Layer("Game Layer")
	{
	}

	void OnUpdate() override
	{
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("TiTLe");
		ImGui::Text("something awesome");
		
		ImGui::End();

		bool show = true;
		ImGui::ShowDemoWindow(&show);

		
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{

	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}