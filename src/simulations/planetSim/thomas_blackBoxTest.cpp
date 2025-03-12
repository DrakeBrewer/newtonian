#include <gtest/gtest.h>
#include "planets.hpp"  

//Black Box Tests
TEST(ObjectTest, BlackBox_InvalidPosition) {

    object obj = object("Test");
    obj.setX(-100);
    obj.setY(-69);
    obj.setZ(-1000);

    ASSERT_FLOAT_EQ(obj.getX(),0) <<"setX() failed to reject invalid positions";
    ASSERT_FLOAT_EQ(obj.getY(),0) <<"setY() failed to reject invalid positions";
    ASSERT_FLOAT_EQ(obj.getZ(),0) <<"setZ() failed to reject invalid positions";

    
}

TEST(PlaneTest,BlackBox_CheckPositions){

    plane pl = plane("Test");
    pl.setX(100);
    pl.setY(-100);
    pl.setZ(200);

    ASSERT_FLOAT_EQ(pl.getX(),100)<<"setX() failed to set positions";
    ASSERT_FLOAT_EQ(pl.getY(),-100)<<"setY() failed to set positions";
    ASSERT_FLOAT_EQ(pl.getZ(),200)<<"setZ() failed to set positions";
}

TEST(PlanetTest,BlackBox_CheckValues){

    planet p = planet("Earth",9.81);
    planet p2 = planet("Moon",1.62);

    ASSERT_FLOAT_EQ(p.getGrav(),9.81)<<"Gravity value incorrect";
    ASSERT_FLOAT_EQ(p2.getGrav(),1.62)<<"Gravity value incorrect";
}

