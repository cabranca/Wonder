#pragma once

#include "Core.h"

namespace Wonder {
	
	class WONDER_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
		void Update();
		void Exit();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


