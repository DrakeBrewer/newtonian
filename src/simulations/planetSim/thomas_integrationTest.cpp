#include <gtest/gtest.h>
#include "planets.hpp"

/*Integration Test -> The units I am testing
are my object, planet, and plane classes
to verify that they interact correctly
to simulate rudimentary free fall */
TEST(IntegrationTest,ObjectPlaneInteraction){
    planet p = planet("Earth",9.81);
    object obj = object ("Test");
    plane pl = plane ("Test");

    obj.setY(100);
    obj.setInitV(0);
    pl.setX(50);
    
    int i = 0;

    while(i < 10){

        obj.setY((obj.getY())-(p.getGrav()));

        if((obj.getY()) <= (pl.getX())){
            obj.setY(pl.getX());
            break;
        }

        i++;
    }

    ASSERT_FLOAT_EQ(obj.getY(),50)<<"Failed to detect plane collision";
    ASSERT_FLOAT_EQ(pl.getX(),50)<<"Plane x value is incorrect";
    ASSERT_FLOAT_EQ(p.getGrav(),9.81)<<"Planet gravity value is incorrect";
    
}