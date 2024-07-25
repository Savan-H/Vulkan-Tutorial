#include "first_app.h"

namespace lve {
	void FirstApp::run() {
		while (!lveWindow.shouldClose()) {
			glfwPollEvents(); // E.g. window clicks, key strokes etc.
		}
	}
}