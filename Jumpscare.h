#pragma once

#include "DummyEntity.h"

class Jumpscare{
private:
	DummyEntity* jump;
	DummyEntity* stalk;
	DummyEntity* follow;

	float m_timer = 0.0f;
	float m_playing = false;
	float m_finished_playing = false;
public:
	void play_jump(glm::vec3 player_pos);
	void play_stalk(glm::vec3 player_pos);
	void play_follow(glm::vec3 player_pos);

	void initialise();
	void update(float delta_time);
	void render(ShaderProgram* program);

	bool started_playing() { return m_playing; }
	bool finished_playing() { return m_finished_playing; }
	void reset() {  m_finished_playing = false; }
};
