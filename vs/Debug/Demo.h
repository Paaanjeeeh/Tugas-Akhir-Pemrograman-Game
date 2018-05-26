#ifndef DEMO_H
#define DEMO_H

#include <SOIL/SOIL.h>


#include <SDL/SDL_mixer.h>
#include <SDL/SDL_thread.h>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <map>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "Game.h"
using namespace glm;

#define NUM_FRAMES 8
#define FRAME_DUR 80
#define FONTNAME "Calibri.ttf"
#define FONTSIZE 40


struct Character {
	GLuint TextureID; // ID handle of the glyph texture
	ivec2 Size; // Size of glyph
	ivec2 Bearing; // Offset from baseline to left/top of glyph
	GLuint Advance; // Offset to advance to next glyph
};


class Demo :
	public Engine::Game
{
public:
	Demo();
	~Demo();
	virtual void Init();
	virtual void DeInit();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void GameStart();
	float frame_width = 0, frame_height = 0, frame_width2 = 0, frame_height2 = 0, frame_width3 = 0, frame_height3 = 0;
	void InitAudio();
	void AddInputs();
private:
	float frame_dur = 0, oldxpos = 0, oldypos=0, xpos = 0, ypos = 0, xpos2 = 0, ypos2 = 0, xpos3 = 0, ypos3 = 0, gravity = 0, xVelocity = 0, yVelocity = 0, yposGround = 0;
	int point = 0;
	GLuint VBO, VAO, EBO, texture, program, VBO2, VAO2, EBO2, texture2, program2, texture3, program3,program4, VBO3, VAO3, EBO3, VBO4, VAO4 ;
	bool walk_anim = false, onGround = true, idle = false, collide = false;
	unsigned int frame_idx = 0, flip = 0;
	void BuildPlayerSprite();
	void BuildCrateSprite();
	void DrawCrateSprite();
	void BuildCrateSprite2();
	void DrawCrateSprite2();
	bool IsCollided(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
	void DrawPlayerSprite();
	void UpdatePlayerSpriteAnim(float deltaTime);
	void ControlPlayerSprite(float deltaTime);
	void InitText();
	void RenderText(string text, GLfloat x, GLfloat y, GLfloat scale, vec3 color);
	map<GLchar, Character> Characters;
	Mix_Chunk *sound = NULL;
	Mix_Music *music = NULL;
	int sfx_channel = -1;
};
#endif

