//
// Created by zmy on 2023/4/27.
//

#ifndef BREAKOUT_RESOURCE_MANAGER_H
#define BREAKOUT_RESOURCE_MANAGER_H


#include <map>
#include <string>

#include "glad/glad.h"

#include "../Render/Texture2D.h"
#include "../Render/Shader.h"


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shaders is also stored for future reference by string
// handles. All functions and resources are static and no
// public constructor is defined.
class ResourceManager
{
public:
    // Resource storage
    static std::map<std::string, Shader>    Shaders;
    static std::map<std::string, Texture2D> Textures;
    // Loads (and generates) a shaders program from file loading vertex, fragment (and geometry) shaders's source code. If gShaderFile is not nullptr, it also loads a geometry shaders
    static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
    // Retrieves a stored sader
    static Shader   GetShader(std::string name);
    // Loads (and generates) a texture from file
    static Texture2D LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
    // Retrieves a stored texture
    static Texture2D GetTexture(std::string name);
    // Properly de-allocates all loaded resources
    static void      Clear();
private:
    // Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() { }
    // Loads and generates a shaders from file
    static Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
    // Loads a single texture from file
    static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};


#endif //BREAKOUT_RESOURCE_MANAGER_H
