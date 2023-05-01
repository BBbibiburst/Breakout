//
// Created by zmy on 2023/4/30.
//

#ifndef BREAKOUT_BALLOBJECT_H
#define BREAKOUT_BALLOBJECT_H


#include "GameObject.h"
#include "../Render/Texture2D.h"

class BallObject : public GameObject
{
public:
    // 球的状态
    GLfloat   Radius;
    GLboolean Stuck;
    GLboolean Sticky, PassThrough;


    BallObject();
    BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture2D sprite);

    glm::vec2 Move(GLfloat dt, GLuint window_width);
    void      Reset(glm::vec2 position, glm::vec2 velocity);
};


#endif //BREAKOUT_BALLOBJECT_H
