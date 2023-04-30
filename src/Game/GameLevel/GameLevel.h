//
// Created by zmy on 2023/4/28.
//

#ifndef BREAKOUT_GAMELEVEL_H
#define BREAKOUT_GAMELEVEL_H

#include "glm/glm.hpp"
#include <vector>
#include "../GameObject/GameObject.h"
#include "../GameResource/resource_manager.h"
#include <fstream>
#include <sstream>

class GameLevel
{
public:
    std::vector<GameObject> Bricks;

    GameLevel() { }
    // 从文件中加载关卡
    void Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight);
    // 渲染关卡
    void Draw(SpriteRenderer &renderer);
    // 检查一个关卡是否已完成 (所有非坚硬的瓷砖均被摧毁)
    GLboolean IsCompleted();
private:
    // 由砖块数据初始化关卡
    void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
};


#endif //BREAKOUT_GAMELEVEL_H
