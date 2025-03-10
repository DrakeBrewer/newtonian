add_executable(light_sim 
   LightParticle.cpp
   LightRay.cpp
   LightWave.cpp
   lightScene.cpp
)

target_link_libraries(light_sim
    delta_time
    rigidBody
)

include_directories(${CMAKE_SOURCE_DIR}/src/simulations/collisionSim)

# add_executable(light_sim 
#    LightBase.cpp
#    LightParticle.cpp
#    LightRay.cpp
#    LightWave.cpp
#    LightStuct.hpp
#    lightScene.cpp
#    Medium.hpp
#    Mirror.cpp
# )

# target_link_libraries(light_sim
#     delta_time
#     rigidBody
# )

# include_directories(${CMAKE_SOURCE_DIR}/src/simulations/collisionSim)
