#include "SceneConfig.h"

#include "raylib.h"
#include "common.h"

int main() {
    const int screenWidth = Constants::Window::WIDTH;
    const int screenHeight = Constants::Window::HEIGHT;

    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "Scene Generator");

    SceneConfig scene = SceneConfig("resources/scene.txt");

    Camera3D camera = {
            Constants::Camera::POSITION,
            Constants::Camera::TARGET,
            Constants::Camera::UP,
            Constants::Camera::FOV,
            CAMERA_PERSPECTIVE
    };

    bool spinCamera = false;
    SetCameraMode(camera, CAMERA_ORBITAL);
    UpdateCamera(&camera);
    SetTargetFPS(Constants::App::TARGET_FPS);

    while (!WindowShouldClose()) {
        if (spinCamera)
            UpdateCamera(&camera);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        {
            using namespace Constants::GUI;
            camera.fovy = GuiSliderBar({MARGIN, MARGIN, SLIDE_WIDTH, BOX_SIZE}, nullptr,
                                       TextFormat(FOV_SLIDER_TEXT, camera.fovy), camera.fovy, FOV_MIN, FOV_MAX);
            spinCamera = GuiCheckBox({MARGIN + SLIDE_WIDTH - BOX_SIZE, 2 * MARGIN + BOX_SIZE, BOX_SIZE, BOX_SIZE},
                                     SPIN_CHECKBOX_TEXT, spinCamera);
        }

        BeginMode3D(camera);
        for (const auto &object: scene.objects) {
            object.model->transform = MatrixRotateXYZ(Vector3Scale(object.orientation, DEG2RAD));

            DrawModel(*object.model, object.position, object.scale, object.color);
            DrawModelWires(*object.model, object.position, object.scale, BLACK);
        }

        DrawGrid(Constants::App::GRID_SLICES, Constants::App::GRID_SPACING);
        EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}