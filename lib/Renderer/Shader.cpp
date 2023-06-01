#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <sstream>

enum ShaderType 
{
    NONE = -1, VERTEX = 0, FRAGMENT = 1
};

Shader::Shader(const std::string& fileName) : filePath(fileName),rendererID(0)
{
	ShaderSouce source = parseShader(fileName);
    rendererID = createShader(source.sourceVertex, source.sourceFragment);
}
Shader::~Shader()
{
	glDeleteProgram(rendererID);
}

void Shader::bind() const
{
	glUseProgram(rendererID);
}
void Shader::unbind() const
{
	glUseProgram(0);
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    glUniform4f(getUniformLocation(name),v0,v1,v2,v3);
}

unsigned int Shader::getUniformLocation(const std::string& name)
{
	if(uniformLocationCache.find(name) != uniformLocationCache.end())
	{
		return uniformLocationCache[name];
	}
	
	int location = glGetUniformLocation(rendererID, name.c_str());
	if(location == -1)
	{
		std::cout << "Uniform Doesn't Exist";
	}
	else
	{
		uniformLocationCache[name] = location;
	}
	return location;
}

ShaderSouce Shader::parseShader(const std::string &filePath)
{
    std::ifstream stream(filePath);

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while(std::getline(stream, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if(line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::compileShader(unsigned int type, const std::string source)
{
    unsigned int id = glCreateShader(type);
    const char* src = &source[0];
    //Intialize Shader Source
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    //Error Handling
    int result;
    //Get OpenGL Compile Status
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        int leght;
        //Get Compile Error Log
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &leght);
        //Dynamically Allocate Memory To A Char Array
        char* message = (char*)alloca(leght * sizeof(char));
        //Send The Error Log To The Char Array
        glGetShaderInfoLog(id, leght, &leght, message);
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    //Create A Program That Can Be Utached To A Shader
    unsigned int program = glCreateProgram();
    //Create Shadder Object
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    //Attach The Shader Into A Program Object
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    //Link The Prgram To The Specifies Shader
    glLinkProgram(program);
    glValidateProgram(program);

    //Delete Intermidiate Source File
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}