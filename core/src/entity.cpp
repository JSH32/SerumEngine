#include "serum/entity.hpp"

namespace Serum::Core {
Entity::Entity(const entt::entity handle, Scene* scene)
    : entityHandle(handle), scene(scene) { }
}