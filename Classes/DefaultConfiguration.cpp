//
//  Configuration.cpp
//  ExpJam
//
//  Created by dmytros on 3/18/18.
//
#include "DefaultConfiguration.h"

USING_NS_CC;

Size DefaultConfiguration::frameSize = Size(640, 480);

Size DefaultConfiguration::snakeDefaultSize = Size(10, 10);

float DefaultConfiguration::speed = 40.f;
float DefaultConfiguration::minMovement = 10;//for nof supported only equal to size of cell(simpliest solution)
size_t DefaultConfiguration::snakeMaxSize = 100;
