#include "lve_window.h"

namespace lve {

	LveWindow::LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(name) {
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // originally designed to create an OpenGL context, so we need to NOT call it
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // make resizing not possible because later this will be handled

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}