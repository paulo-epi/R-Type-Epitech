/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Collision
*/

#include "CollisionSystem.hpp"

ecs::system::SystemType ecs::system::CollisionSystem::getSystemType() const
{
    return ecs::system::COLLISIONSYSTEM;
}

void ecs::system::CollisionSystem::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{
    for (auto entity : entities) {
        if (entity.get()->hasComponent(ecs::component::COLLISIONCOMPONENT) && entity.get()->hasComponent(ecs::component::POSITIONCOMPONENT) && entity.get()->hasComponent(ecs::component::HEALTHCOMPONENT) && entity.get()->hasComponent(ecs::component::DAMAGECOMPONENT)) {
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            ecs::component::Collision *collision = dynamic_cast<ecs::component::Collision *>(entity.get()->getComponent(ecs::component::COLLISIONCOMPONENT).get());
            ecs::component::Health *health = static_cast<ecs::component::Health *>(entity.get()->getComponent(ecs::component::HEALTHCOMPONENT).get());
            ecs::component::Damage *damage = static_cast<ecs::component::Damage *>(entity.get()->getComponent(ecs::component::DAMAGECOMPONENT).get());

            std::cout << "Entity Type :" << entity.get()->getType() << std::endl;
            //Depassement TOP
            if (position->getY() < 0) {
                position->setY(0);
            }

            //Depassement BOT
            if (position->getY() + collision->getHitbox().second > 1080) {
                position->setY(1080 -  collision->getHitbox().second);
            }

            if (entity.get()->getType() == ecs::entity::PLAYER1 || entity.get()->getType() == ecs::entity::PLAYER2 
            || entity.get()->getType() == ecs::entity::PLAYER3 || entity.get()->getType() == ecs::entity::PLAYER4) {

                //Depassement LEFT
                if (position->getX() < 0) {
                    position->setX(0);
                }

                //Depassement RIGHT
                if (position->getX() + collision->getHitbox().first  > 1920) {
                    position->setX(1920 - collision->getHitbox().first);
                }
            }
            for (auto entity2 : entities) {
                if (entity2.get()->hasComponent(ecs::component::COLLISIONCOMPONENT) && entity2.get()->hasComponent(ecs::component::POSITIONCOMPONENT) && entity2.get()->hasComponent(ecs::component::HEALTHCOMPONENT)&& entity2.get()->hasComponent(ecs::component::DAMAGECOMPONENT)) {
                    ecs::component::Position *position2 = dynamic_cast<ecs::component::Position *>(entity2.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
                    ecs::component::Collision *collision2 = dynamic_cast<ecs::component::Collision *>(entity2.get()->getComponent(ecs::component::COLLISIONCOMPONENT).get());
                    ecs::component::Health *health2 = static_cast<ecs::component::Health *>(entity2.get()->getComponent(ecs::component::HEALTHCOMPONENT).get());
                    ecs::component::Damage *damage2 = static_cast<ecs::component::Damage *>(entity2.get()->getComponent(ecs::component::DAMAGECOMPONENT).get());
                    rect_t rect1 = { position->getX(), position->getY(), collision->getHitbox().first, collision->getHitbox().second };
                    rect_t rect2 = { position2->getX(), position2->getY(), collision2->getHitbox().first, collision2->getHitbox().second };
                    if (rect1.x < rect2.x + rect2.width && rect1.x + rect1.width > rect2.x && rect1.y < rect2.y + rect2.height && rect1.height + rect1.y > rect2.y) {
                         if (entity.get()->getType() == entity2.get()->getType()){
                            continue;
                        }
                        else if ((entity.get()->getType() == ecs::entity::PLAYER1 || entity.get()->getType() == ecs::entity::PLAYER2 || entity.get()->getType() == ecs::entity::PLAYER3 || entity.get()->getType() == ecs::entity::PLAYER4) && (entity2.get()->getType() == ecs::entity::PLAYER1 || entity2.get()->getType() == ecs::entity::PLAYER2 || entity2.get()->getType() == ecs::entity::PLAYER3 || entity2.get()->getType() == ecs::entity::PLAYER4)) {
                            std::cout << "meme race \n";
                        } else {
                            health->setHealth(health->getHealth() - damage2->getDamage());
                            health2->setHealth(health2->getHealth() - damage->getDamage());
                        }
                    }
                }
            }
        }

    }
}