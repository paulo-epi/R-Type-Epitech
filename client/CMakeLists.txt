SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREVIOUS_DIR}")
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(include)

set(SOURCES src/main.cpp
            src/Window.cpp
            src/Utilities/Back.cpp
            src/Utilities/Button.cpp
            src/Utilities/Clock.cpp
            src/Utilities/Field.cpp
            src/Utilities/Picture.cpp
            src/Utilities/Text.cpp
            src/Utilities/TextButton.cpp
            src/Game.cpp
            src/Utilities/Moveback.cpp
            ../Error/Error.cpp
            ../server/src/Socket.cpp)

set(INCLUDE src/Window.hpp
            src/Utilities/Back.hpp
            src/Utilities/Button.hpp
            src/Utilities/Clock.hpp
            src/Utilities/Field.hpp
            src/Utilities/FPS.hpp
            src/Utilities/Picture.hpp
            src/Utilities/Text.hpp
            src/Utilities/TextButton.hpp
            src/Game.hpp
            src/Utilities/Moveback.hpp)

add_executable(r-type_client ${SOURCES} ${INCLUDES})

target_link_libraries (r-type_client sfml-window sfml-system sfml-audio sfml-graphics -lboost_system -lboost_thread -lpthread)

# add_executable(r-type_client ${SOURCES} ${INCLUDES})
# target_link_libraries (r-type_client PRIVATE sfml-window sfml-system sfml-audio sfml-graphics -lboost_system -lboost_thread -lpthread)
# # target_link_libraries(r-type_client PRIVATE sfml-graphics )
# target_compile_features(r-type_client PRIVATE cxx_std_17)

# if (WIN32 AND BUILD_SHARED_LIBS)
#     add_custom_command(TARGET r-type_client POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:r-type_client> $<TARGET_FILE_DIR:r-type_client> COMMAND_EXPAND_LISTS)
# endif()

# install(TARGETS r-type_client)