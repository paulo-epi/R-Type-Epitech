SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREVIOUS_DIR}")
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(include)

# file(GLOB SOURCES "src/*.cpp")
# file(GLOB INCLUDES "include/*.hpp")

set(SOURCES src/main.cpp
            src/instance/Instance.cpp
            src/Server.cpp
            src/Socket.cpp
            ../Error/Error.cpp
            src/instance/Player.cpp
            ../ecs/Entity/EntityPool.cpp
            ../ecs/Entity/Entity.cpp
            ../ecs/Component/Collision/Collision.cpp
            ../ecs/Component/Player/Player.cpp
            ../ecs/Component/Damage/Damage.cpp
            ../ecs/Component/Drawable/Drawable.cpp
            ../ecs/Component/Health/Health.cpp
            ../ecs/Component/Position/Position.cpp
            ../ecs/Component/Speed/Speed.cpp
            ../ecs/System/CollisionSystem/CollisionSystem.cpp
            ../ecs/System/EnemySystem/EnemySystem.cpp
            ../ecs/System/LaserSystem/LaserSystem.cpp
            ../ecs/System/MovementSystem/Movement.cpp
            ../ecs/System/PlayerSystem/PlayerSystem.cpp
            ../ecs/System/DeathSystem/DeathSystem.cpp
            )

set(INCLUDE src/basics.hpp
            Instance/Instance.hpp
            src/Server.hpp
            share/Socket.hpp
            share/ISocket.hpp
            Instance/Player.hpp
            ../Error/Error.hpp
            ../ecs/Entity/EntityPool.hpp
            ../ecs/Entity/Entity.hpp
            ../ecs/Component/IComponent.hpp
            ../ecs/Component/Collision/Collision.hpp
            ../ecs/Component/Damage/Damage.hpp
            ../ecs/Component/Player/Player.hpp
            ../ecs/Component/Drawable/Drawable.hpp
            ../ecs/Component/Health/Health.hpp
            ../ecs/Component/Position/Position.hpp
            ../ecs/Component/Speed/Speed.hpp
            ../ecs/System/ISystem.hpp
            ../ecs/System/CollisionSystem/CollisionSystem.hpp
            ../ecs/System/EnemySystem/EnemySystem.hpp
            ../ecs/System/LaserSystem/LaserSystem.hpp
            ../ecs/System/MovementSystem/Movement.hpp
            ../ecs/System/PlayerSystem/PlayerSystem.hpp
            ../ecs/System/DeathSystem/DeathSystem.hpp
            )

add_executable(r-type_server ${SOURCES} ${INCLUDES})

target_link_libraries (r-type_server -lboost_system -lboost_thread -lpthread)

# add_executable(r-type_server ${SOURCES} ${INCLUDES})
# # target_link_libraries(r-type_server PRIVATE sfml-graphics)
# target_link_libraries (r-type_server PRIVATE -lboost_system -lboost_thread -lpthread)
# target_compile_features(r-type_server PRIVATE cxx_std_17)

# if (WIN32 AND BUILD_SHARED_LIBS)
#     add_custom_command(TARGET r-type_server POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:r-type_server> $<TARGET_FILE_DIR:r-type_server> COMMAND_EXPAND_LISTS)
# endif()

# install(TARGETS r-type_server)