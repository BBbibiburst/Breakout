//
// Created by zmy on 2023/4/27.
//

#include "Game.h"


SpriteRenderer *Renderer;
// 初始化挡板的大小
const glm::vec2 PLAYER_SIZE(100, 20);
// 初始化当班的速率
const GLfloat PLAYER_VELOCITY(500.0f);

GameObject      *Player;


Game::Game(GLuint width, GLuint height)
        : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{

}

void Game::Init()
{
    // 加载着色器
    ResourceManager::LoadShader("../src/Render/shaders/sprite.vsh", "../src/Render/shaders/sprite.fsh", nullptr, "sprite");
    // 配置着色器
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
                                      static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // 设置专用于渲染的控制
    Shader spriteShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(spriteShader);
    // 加载纹理
    ResourceManager::LoadTexture("../textures/background.jpg", GL_FALSE, "background");
    ResourceManager::LoadTexture("../textures/face.png", GL_TRUE, "face");
    ResourceManager::LoadTexture("../textures/block.png", GL_FALSE, "block");
    ResourceManager::LoadTexture("../textures/block_solid.png", GL_FALSE, "block_solid");
    ResourceManager::LoadTexture("../textures/paddle.png", true, "paddle");
    // 加载关卡
    GameLevel one; one.Load("../levels/Standard.txt", this->Width, this->Height * 0.5);
    GameLevel two; two.Load("../levels/A_Few_Small_Gaps.txt", this->Width, this->Height * 0.5);
    GameLevel three; three.Load("../levels/Space_Invader", this->Width, this->Height * 0.5);
    GameLevel four; four.Load("../levels/Bounce_Galore.txt", this->Width, this->Height * 0.5);
    this->Levels.push_back(one);
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Levels.push_back(four);
    this->Level = 1;
    // 加载玩家
    glm::vec2 playerPos = glm::vec2(
            this->Width / 2 - PLAYER_SIZE.x / 2,
            this->Height - PLAYER_SIZE.y
    );
    Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("paddle"));
}

void Game::Update(GLfloat dt)
{

}


void Game::ProcessInput(GLfloat dt)
{
    if (this->State == GAME_ACTIVE)
    {
        GLfloat velocity = PLAYER_VELOCITY * dt;
        // 移动挡板
        if (this->Keys[GLFW_KEY_A])
        {
            if (Player->Position.x >= 0)
                Player->Position.x -= velocity;
        }
        if (this->Keys[GLFW_KEY_D])
        {
            if (Player->Position.x <= this->Width - Player->Size.x)
                Player->Position.x += velocity;
        }
    }
}

void Game::Render()
{
    if(this->State == GAME_ACTIVE)
    {
        // 绘制背景
        Texture2D background = ResourceManager::GetTexture("background");
        Renderer->DrawSprite(background,
                             glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f
        );
        // 绘制关卡
        this->Levels[this->Level].Draw(*Renderer);
        // 绘制玩家
        Player->Draw(*Renderer);
    }
}
