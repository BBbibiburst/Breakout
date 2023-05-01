//
// Created by zmy on 2023/4/27.
//

#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GameResource/resource_manager.h"
#include "Render/SpriteRenderer.h"
#include "GameLevel/GameLevel.h"

// 代表了游戏的当前状态
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

class Game {
public:
    // 游戏状态
    GameState State;
    GLboolean Keys[1024];
    GLuint Width, Height;
    std::vector<GameLevel> Levels;
    GLuint Level;

    // 构造函数/析构函数
    Game(GLuint width, GLuint height);

    ~Game();

    // 初始化游戏状态（加载所有的着色器/纹理/关卡）
    void Init();

    // 游戏循环
    void ProcessInput(GLfloat dt);

    void Update(GLfloat dt);

    void Render();

    void DoCollisions();

    // Reset
    void ResetLevel();

    void ResetPlayer();
};


#endif //BREAKOUT_GAME_H
