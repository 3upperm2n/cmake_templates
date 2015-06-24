#include <gtest/gtest.h>

#include "ToDo.h"

TEST(ExampleTest, comparetest) 
{
	int v = compare(1,2);
    EXPECT_EQ(1, v);
}

