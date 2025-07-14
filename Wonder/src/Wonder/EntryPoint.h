#pragma once

#ifdef WD_PLATFORM_WINDOWS

extern Wonder::Application* Wonder::CreateApplication();

int main(int argc, char** argv) {
	Wonder::Log::Init();
	WD_CORE_WARN("Welcome to Wonder Engine!");
	int a = 5;
	WD_INFO("Hello! Var={0}", a);

	auto app = Wonder::CreateApplication();
	app->Run();
	delete app;
}

#endif