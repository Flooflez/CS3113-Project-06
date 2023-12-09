#include "Scene.h"

class LevelA : public Scene {
public:
    // ————— STATIC ATTRIBUTES ————— //
    const int ENEMY_COUNT = 11;
    const int SPAWNPOINT_COUNT = 4;
    const int GOAL_COUNT = 10;

    
    // ————— CONSTRUCTOR ————— //
    ~LevelA();
    
    // ————— METHODS ————— //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram *program) override;
};
