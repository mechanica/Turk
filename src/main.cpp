//
//  main.cpp
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#include <iostream>
#include <GL/glfw3.h>
#include "GlfwHost.h"

void initializeGLFW ();

void initializeGLFW ()
{
	if( !glfwInit() )
	{
		exit(EXIT_FAILURE);
	}
}

int main (int argc, const char * argv[])
{
	initializeGLFW();
	GlfwHost(argc, argv);
	
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}
