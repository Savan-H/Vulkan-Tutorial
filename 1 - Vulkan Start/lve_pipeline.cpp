#include "lve_pipeline.h"

#include <fstream> // for input file stream object
#include <stdexcept>
#include <iostream>

namespace lve {
	LvePipeline::LvePipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) : lveDevice(device)
	{
		createGraphicsPipeline(vertFilePath, fragFilepath, configInfo);
	}
	PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo;
		return configInfo;
	}
	std::vector<char> lve::LvePipeline::readFile(const std::string& filepath)
	{
		std::ifstream file(filepath, std::ios::ate | std::ios::binary); // ate means when file is open, seeks the end immediately. binary means read in binary to avoid any text transformations.
		
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg()); // ate lets us get the file size right away since we are at the end
		std::vector<char> buffer(fileSize);

		file.seekg(0); // seek to start
		file.read(buffer.data(), fileSize); // read into buffer

		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		// common pattern, configure a struct, then call a function to it.
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module.");
		}
	}

}
