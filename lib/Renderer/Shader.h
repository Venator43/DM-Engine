#pragma once

#include <string>
#include <unordered_map>

struct ShaderSouce
{
    std::string sourceVertex;
    std::string sourceFragment;
};

class Shader
{
	private:
		std::string filePath;
		unsigned int rendererID;
		std::unordered_map<std::string, int> uniformLocationCache;
	public:
		Shader(const std::string& fileName);
		~Shader();

		void bind() const;
		void unbind() const;

		void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	private:
		unsigned int getUniformLocation(const std::string& name);
		ShaderSouce parseShader(const std::string &filePath);
		unsigned int compileShader(unsigned int type, const std::string source);
		unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
};