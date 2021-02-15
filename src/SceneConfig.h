#ifndef SCENEGEN_SCENECONFIG_H
#define SCENEGEN_SCENECONFIG_H

#include <string>
#include <vector>
#include "raylib.h"

class SceneConfig {
    void parseSceneConfig(const std::vector<std::string> &tokens);

    Model pyramidModel = {0};
    Model cubeModel = {0};

public:
    struct ObjectConfig {
        Model *model = nullptr;

        Color color = GRAY;

        Vector3 position = {0, 0, 0};
        Vector3 orientation = {0, 0, 0};
        float scale = 1;
    };

    std::vector<ObjectConfig> objects;

    SceneConfig() = default; // Empty scene
    explicit SceneConfig(const std::string &filepath);
    ~SceneConfig();
};

#endif //SCENEGEN_SCENECONFIG_H
