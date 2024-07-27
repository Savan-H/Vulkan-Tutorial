#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

// lve = little vulkan engine

namespace lve {
	class LveWindow {

	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		// this is needed to stop copying the pointer such that 2 lvewindow pointers would point to the same GLFWwindow*
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }; // is user trying to close the window

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
	private:

		void initWindow();
		
		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;

	};
}