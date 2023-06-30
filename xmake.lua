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

add_requires("glfw")
add_requires("raylib 4.5.0")

target("serum-core")
    set_kind("static")
    add_includedirs("core/include")
    add_packages("glfw", "raylib", { public = true })
    add_files("core/src/*.cpp")

target("serum-editor")
    set_kind("binary")
    add_includedirs("editor/include")
    add_deps("serum-core")
    add_files("editor/src/*.cpp")
