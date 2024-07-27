#pragma once

#include "lve_device.h"

#include <string>
#include <vector>

namespace lve {

	// Contains data specifying how we want to configure our pipeline
	struct PipelineConfigInfo {
		
	};

	class LvePipeline {
	public:
		LvePipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
		~LvePipeline() {};

		// Delete copy constructors. Avoids accidentally duplicating pointers to Vulkan objects.
		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height); // uint32_t is standard, uint32 is not.

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice; // HAS to live more than or equal to an LvePipeline object. Can only use since we are certain this is the case.
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}