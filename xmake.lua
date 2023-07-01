add_rules("mode.debug", "mode.release")

task("configure")
    on_run(function ()
        os.execv("xmake", {"project", "-k", "compile_commands"}, {stdout = outfile, stderr = errfile})
        os.execv("xmake", {"project", "-k", "cmakelists"}, {stdout = outfile, stderr = errfile})
    end)
    set_menu {
        usage = "xmake configure",
        description = "Configure the project and generate CMake files",
        options = {}
    }
task_end()

set_languages("c++17")

add_requires("glfw")
add_requires("spdlog v1.11.0")
add_requires("raylib 4.5.0")
add_requires("entt v3.9.0")
add_requires("imgui v1.89.6-docking")

target("serum-core")
    set_kind("static")
    add_includedirs(
        "core/include",
        "vendor/raylib-cpp/include",
        { public = true }
    )
    add_packages("glfw", "raylib", "entt", "spdlog", { public = true })
    add_files("core/src/*.cpp")

target("serum-editor")
    set_kind("binary")
    add_packages("imgui")
    add_deps("serum-core")
    add_includedirs(
        "vendor/rlImGui",
        "editor/include"
    )
    add_files(
        "vendor/rlImGui/rlImGui.cpp",
        "editor/src/*.cpp"
    )
