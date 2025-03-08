add_executable(light_sim 
   LightBase.cpp
   LightParticle.cpp
   LightRay.cpp
   LightWave.cpp
   LightStuct.hpp
   Scene.cpp
   Medium.hpp
   Mirror.cpp
)

target_link_libraries(light_sim
    delta_time
    rigidBody
)

include_directories(${CMAKE_SOURCE_DIR}/src/simulations/collisionSim)
