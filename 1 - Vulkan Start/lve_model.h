#pragma once

#include "lve_device.h"

#define GLM_FORCE_RADIANS // Forces all angles to be in radians
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // Depth buffer values from 0 to 1 rather than -1 to 1.
#include <glm/glm.hpp>

#include <vector>

namespace lve {
	class LveModel {
	public:
		struct Vertex {
			glm::vec2 position;

			static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
			static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
		};

		LveModel(LveDevice& device, const std::vector<Vertex>& vertices);
		~LveModel();

		// Delete copy constructors
		LveModel(const LveModel&) = delete;
		LveModel& operator=(const LveModel&) = delete;

		void bind(VkCommandBuffer commandBuffer);
		void draw(VkCommandBuffer commandBuffer);

	private:
		void createVertexBuffers(const std::vector<Vertex>& vertices);

		LveDevice& lveDevice;
		VkBuffer vertexBuffer;
		VkDeviceMemory vertexBufferMemory;
		uint32_t vertexCount;
	};
}