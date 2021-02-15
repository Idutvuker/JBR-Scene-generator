#include <fstream>
#include <sstream>

#include "SceneConfig.h"

Vector3 parseVector3(std::vector<std::string>::const_iterator &iter, const std::vector<std::string>::const_iterator &end) {
    if (std::distance(iter, end) < 3)
        throw std::invalid_argument("Unexpected EOF");

    float x = std::stof(*iter);
    iter++;
    float y = std::stof(*iter);
    iter++;
    float z = std::stof(*iter);
    iter++;

    return Vector3{x, y, z};
}

void SceneConfig::parseSceneConfig(const std::vector<std::string> &tokens) {
    auto iter = tokens.cbegin();

    while (iter != tokens.cend()) {
        if (*iter == "cube") {
            objects.push_back({&cubeModel, YELLOW});
            iter++;
        } else if (*iter == "pyramid") {
            objects.push_back({&pyramidModel, RED});
            iter++;
        }

        else if (*iter == "position") {
            iter++;
            objects.back().position = parseVector3(iter, tokens.cend());
        } else if (*iter == "orientation") {
            iter++;
            objects.back().orientation = parseVector3(iter, tokens.cend());
        } else if (*iter == "scale") {
            iter++;
            objects.back().scale = std::stof(*iter);
            iter++;
        }

        else {
            std::stringstream strSteam;
            strSteam << "Invalid token \"" << *iter << "\"";
            throw std::invalid_argument(strSteam.str());
        }
    }
}

SceneConfig::SceneConfig(const std::string &filepath) {
    cubeModel = LoadModel("resources/cube.obj");
    pyramidModel = LoadModel("resources/pyramid.obj");

    std::ifstream fileStream(filepath);

    if (!fileStream.good())
        throw std::invalid_argument("Scene file can't be opened");

    std::vector<std::string> tokens;
    std::string token;
    while (fileStream >> token) {
        tokens.push_back(token);
    }

    parseSceneConfig(tokens);
}

SceneConfig::~SceneConfig() {
    UnloadModelKeepMeshes(cubeModel);
    UnloadModelKeepMeshes(pyramidModel);
}



