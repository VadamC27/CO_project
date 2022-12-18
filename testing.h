#ifndef TEST_H
#define TEST_H

#include <vector>
#include <fstream>
#include "graphs.h"

enum testTypes {EXIST,LONGEST,EXACT};
enum graphTypes {RANDOM_HALF, RANDOM_ONE_THIRD, RANDOM_TWO_THIRDS, ACYCLIC,RING};

struct GraphTest{
    GraphTest(int type, int graphType, int start_v, int end_v, int g);
};

#endif