#include <gtest/gtest.h>
#include "fluidSim.hpp"



//--------Black-box unit tests---------

// Testing all valid objects for the fluid simulation
// Checking the name, density, and mass of the object
TEST(FluidMechanics, setObjectType){
    float volume = 0.1; // Default volume for all objects
    {
        object obj("wood");
        ASSERT_EQ("wood",obj.name);
        EXPECT_FLOAT_EQ(500, obj.density);
        EXPECT_FLOAT_EQ(500*volume, obj.mass);
    }

    {
        object obj("aluminium");
        ASSERT_EQ("aluminium",obj.name);
        EXPECT_FLOAT_EQ(2710, obj.density);
        EXPECT_FLOAT_EQ(2710*volume, obj.mass);
    }

    {
        object obj("rock");
        ASSERT_EQ("rock",obj.name);
        EXPECT_FLOAT_EQ(2500, obj.density);
        EXPECT_FLOAT_EQ(2500*volume, obj.mass);
    }
}

// Testing all valid fluids for the fluid simulation
// Checking the name and density of the object
TEST(FluidMechanics, setFluidType){
    {
        fluid liquid("water");
        ASSERT_EQ("water",liquid.name);
        EXPECT_FLOAT_EQ(1000, liquid.getDensity());
    }

    {
        fluid liquid("oil");
        ASSERT_EQ("oil",liquid.name);
        EXPECT_FLOAT_EQ(800, liquid.getDensity());
    }

    {
        fluid liquid("corn syrup");
        ASSERT_EQ("corn syrup",liquid.name);
        EXPECT_FLOAT_EQ(1380, liquid.getDensity());
    }
}


//--------White-box unit tests---------

// Testing the netForce() function by getting a 100% branch coverage
// Testing that the correct equation is used depending on the postion of the object
TEST(FluidMechanics, netForceEquationSelection){
    //Initializing a default object, fluid, and velocity.
    object obj("wood");
    fluid liquid("water");
    float velocity = 0; //removes the drag force, easier to test

    // Expected force values
    float bForce = liquid.getDensity() * obj.volume * 9.80665;
    float weight = obj.mass * 9.80665;
    float drag = 0; // 0 since velocity is 0 (...*0)

    // If object is above the fluid use weight - drag 
    {
        obj.z = 10; // position of the object is above the fluid
        ASSERT_FLOAT_EQ((weight - drag), netForce(obj, liquid, velocity));
    }

    // If object is below the fluid use weight - bForce - drag
    {
        obj.z = -10; // position of the object is below the fluid
        ASSERT_FLOAT_EQ((weight - bForce - drag), netForce(obj, liquid, velocity));
    }

    // If object is at position 0 use weight - drag
    {
        obj.z = 0; // position of the object is below the fluid
        ASSERT_FLOAT_EQ((weight - drag), netForce(obj, liquid, velocity));
    }

}

//---------Integration tests----------

// Testing the unit functions runSimulation() and netForce()
// Making sure they work together correctly 
// runSimulation() calls netForce() within
TEST(FluidSimulation, RunningSimAndCalculatingForces){
    // Initializing the object above the fluid making the 
    {
        object obj("wood", 10); 
        fluid liquid("water");

        // The simulation should finish and return that the object floats
        // The netForce should be down above the fluid making it fall
        // then when in the fluid it would float because the netForce() switched equations
        int result = runSimulation(obj, liquid, false);
    
        // If the object floated it should return 0
        ASSERT_EQ( 0, result);
    }

    {
        object obj("rock", 10); 
        fluid liquid("water");

        // The simulation should finish and return that the object sinks
        // The netForce should be down above the fluid making it fall
        // then when in the fluid it would sink because the weight would
        // be more then the buoyant force
        int result = runSimulation(obj, liquid, false);
    
        // If the object sinks it should return 1
        ASSERT_EQ( 1, result);

    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
