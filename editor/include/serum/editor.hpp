#pragma once

#include "raylib-cpp.hpp"

namespace Serum::Editor {
class Editor {
public:
    explicit Editor(raylib::RenderTexture& renderTexture);
    void update() const;
    void run();

private:
    static void startDockSpace();

    // std::vector<std::unique_ptr<EditorPanel>> panels;
    raylib::RenderTexture& renderTexture;
    // sf::Clock deltaTime;
};
}