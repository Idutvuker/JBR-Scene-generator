#ifndef SCENEGEN_COMMON_H
#define SCENEGEN_COMMON_H

#define RAYMATH_HEADER_ONLY
#include "raygui.h"

#define RAYMATH_HEADER_ONLY
#include "raymath.h"

namespace Constants {
    namespace Window {
        const int WIDTH = 800;
        const int HEIGHT = 600;
    }

    namespace Camera {
        const Vector3 POSITION = {0.0f, 10.0f, 10.0f};
        const Vector3 TARGET = {0.f, 0.f, 0.f};
        const Vector3 UP = {0.0f, 1.0f, 0.0f};
        const float FOV = 50.f;
    }

    namespace GUI {
        const int MARGIN = 15;
        const int BOX_SIZE = 20;
        const int SLIDE_WIDTH = 50;

        const float FOV_MIN = 30.f;
        const float FOV_MAX = 90.f;

        const char* FOV_SLIDER_TEXT = "FOV: %.1f";
        const char* SPIN_CHECKBOX_TEXT = "Spin camera";
    }

    namespace App {
        const int TARGET_FPS = 60;

        const int GRID_SLICES = 10;
        const float GRID_SPACING = 1.f;
    }
}

#endif //SCENEGEN_COMMON_H
