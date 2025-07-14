#pragma once

#ifdef WD_PLATFORM_WINDOWS

extern Wonder::Application* Wonder::CreateApplication();

int main(int argc, char** argv) {
	printf("Wonder Engine Starting...\n");
	auto app = Wonder::CreateApplication();
	app->Run();
	delete app;
}

#endif