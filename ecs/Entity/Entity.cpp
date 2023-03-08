/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Entity
*/

#include "Entity.hpp"

ecs::entity::Entity::Entity(ecs::entity::EntityType type) : _type(type), _id(0)
{
}

ecs::entity::Entity::Entity(ecs::entity::EntityType type, std::string filename, ecs::component::Position *position) : _type(type), _id(0)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {

        std::string componentType = line.substr(0, line.find('|'));
        std::string componentArgs = line.substr(line.find('|') + 1);

        if (componentType == "DRAWABLECOMPONENT") {
            std::string filename = componentArgs.substr(0, componentArgs.find(","));
            float scale = stof(componentArgs.substr(componentArgs.find(",") + 1));
            _components.emplace_back(new ecs::component::Drawable(filename, scale));
        } else if (componentType == "POSITIONCOMPONENT") {
            if (position == nullptr) {
                float x = stof(componentArgs.substr(0, componentArgs.find(',')));
                float y = stof(componentArgs.substr(componentArgs.find(',') + 1));
                _components.emplace_back(new ecs::component::Position(x, y));
            } else {
                _components.emplace_back(new ecs::component::Position(position->getX() + 100, position->getY() + 10));
            }

        } else if (componentType == "SPEEDCOMPONENT") {
            int speed = stoi(componentArgs);
            _components.emplace_back(new ecs::component::Speed(speed));

        } else if (componentType == "PLAYERCOMPONENT") {

            _components.emplace_back(new ecs::component::Player());
        } else if (componentType == "COLLISIONCOMPONENT") {

            int width = stoi(componentArgs.substr(0, componentArgs.find(',')));
            int heigth = stoi(componentArgs.substr(componentArgs.find(',') + 1));
            _components.emplace_back(new ecs::component::Collision(width, heigth));
        }  else if (componentType == "DAMAGECOMPONENT") {

            int damage = stoi(componentArgs);
            _components.emplace_back(new ecs::component::Damage(damage));
        } else if (componentType == "HEALTHCOMPONENT") {

            int health = stoi(componentArgs);
            _components.emplace_back(new ecs::component::Health(health));

        }
    }
    file.close();
}

ecs::entity::Entity::Entity() : _id(0)
{
}

ecs::entity::Entity::~Entity()
{
}

ecs::entity::EntityType ecs::entity::Entity::getType() const
{
    return _type;
}

void ecs::entity::Entity::setId(size_t id)
{
    _id = id;
}

size_t ecs::entity::Entity::getId(void) const
{
    return _id;
}

bool ecs::entity::Entity::hasComponent(ecs::component::ComponentType type)
{
    for (auto &component : _components) {
        if (component->getComponentType() == type)
            return true;
    }
    return false;
}

void ecs::entity::Entity::addComponent(std::shared_ptr<ecs::component::IComponent> component)
{
    if (hasComponent(component->getComponentType())) {
        throw Error("Entity already has this component");
        return;
    }
    _components.push_back(component);
}

void ecs::entity::Entity::removeComponent(ecs::component::ComponentType type)
{
    if (!hasComponent(type)) {
        throw Error("Error : Component not found.");
        return;
    }
    for (auto it = _components.begin(); it != _components.end(); it++) {
        if ((*it)->getComponentType() == type) {
            _components.erase(it);
            return;
        }
    }
}

std::shared_ptr<ecs::component::IComponent> ecs::entity::Entity::getComponent(ecs::component::ComponentType type)
{
    for (auto &component : _components) {
        if (component->getComponentType() == type)
            return component;
    }
    throw Error("Error : Entity doesn't have this component");
    return nullptr;
}
