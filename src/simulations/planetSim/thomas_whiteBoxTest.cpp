#include "planets.hpp"
#include <gtest/gtest.h>


//White Box Test -> Branch Coverage
TEST(ObjectTest,NegativeMass){
    object obj = object("Test");

    obj.setMass(-100);

    ASSERT_FLOAT_EQ(obj.getMass(),1);

}

TEST(ObjectTest,LargeMass){
    object obj = object("Test");

    obj.setMass(2000);

    ASSERT_FLOAT_EQ(obj.getMass(),1000);


}

TEST(ObjectTest,ZeroMass){
    object obj = object("Test");

    obj.setMass(0);

    ASSERT_FLOAT_EQ(obj.getMass(),1);

}

TEST(ObjectTest,ValidMass){
    object obj = object("Test");

    obj.setMass(100);

    ASSERT_FLOAT_EQ(obj.getMass(),100);

}

/*TEST(ObjectTest,NullMass){
    object obj = object("Test");

    obj.setMass(NULL);

    ASSERT_FLOAT_EQ(obj.getMass(),1);
}*/
