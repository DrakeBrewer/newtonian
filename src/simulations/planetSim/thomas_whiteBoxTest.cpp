#include "planets.hpp"
#include <gtest/gtest.h>


/*White Box Test -> Branch Coverage
Method being tested:
 void setMass(float m){
        if(m <= 0){
            mass = 1;
        }
        else if(m > 1000){
            mass = 1000;
        }
        else{mass = m;}
    }*/
TEST(WhiteBox_ObjectTest,InvalidMass){
    object obj = object("Test");

    obj.setMass(-100);

    ASSERT_FLOAT_EQ(obj.getMass(),1)<<"Failed to reject invalid mass";

}

TEST(WhiteBox_ObjectTest,LargeMass){
    object obj = object("Test");

    obj.setMass(2000);

    ASSERT_FLOAT_EQ(obj.getMass(),1000)<<"Failed to reject invalid mass";


}


TEST(WhiteBox_ObjectTest,ValidMass){
    object obj = object("Test");

    obj.setMass(100);

    ASSERT_FLOAT_EQ(obj.getMass(),100)<<"Failed to set mass";

}

/*TEST(WhiteBox_ObjectTest,ZeroMass){
    object obj = object("Test");

    obj.setMass(0);

    ASSERT_FLOAT_EQ(obj.getMass(),1);

}*/

