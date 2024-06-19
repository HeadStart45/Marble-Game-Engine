#include <Marble.h>

class SandBox : public Marble::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

Marble::Application* Marble::CreateApplication()
{
	return new SandBox();
}

