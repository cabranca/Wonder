#include <Wonder.h>

class Sandbox : public Wonder::Application
{
public:
	Sandbox() {

	}
	
	~Sandbox() {
	
	}
};

Wonder::Application* Wonder::CreateApplication()
{
	return new Sandbox();
}
