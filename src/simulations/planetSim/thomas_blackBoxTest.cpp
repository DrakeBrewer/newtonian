#include <gtest/gtest.h>
#include "planets.hpp"  

//Black Box Test
TEST(ObjectTest, InvalidPosition) {

    object obj = object("Test");
    obj.setX(-100);
    obj.setY(-69);
    obj.setZ(-1000);

    ASSERT_FLOAT_EQ(obj.getX(),0) <<"setX() failed to reject invalid positions";
    ASSERT_FLOAT_EQ(obj.getY(),0) <<"setY() failed to reject invalid positions";
    ASSERT_FLOAT_EQ(obj.getZ(),0) <<"setZ() failed to reject invalid positions";

    
}

