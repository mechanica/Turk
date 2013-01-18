//
//  GlfwHost.h
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#ifndef MOAI_GLFW_GlfwHost_h
#define MOAI_GLFW_GlfwHost_h

GLFWwindow getWindow            ();

int		GlfwHost				( int argc, const char * argv[] );
void    LoadAKUModules          ();
void    RefreshAKUContext       ();
void    SetupInputCallbacks     ();
void    SetupInputMapping       ();
void    SetupWindowMapping      ();
void    SetupErrorMapping       ();
void    GlfwEventLoop           ();

static void onKeyboardKey   ( GLFWwindow window, int key, int action );
static void onKeyboardChar  ( GLFWwindow window, int unicode, int action);
static void onMouseButton   ( GLFWwindow window, int button, int action );
static void onMouseMove     ( GLFWwindow window, int x, int y );
static void onMouseWheel    ( GLFWwindow window, double x, double y );
static void onWindowSize    ( GLFWwindow window, int width, int height );
static int  onWindowClose   ( GLFWwindow window );

void	_AKUEnterFullscreenFunc ();
void	_AKUExitFullscreenFunc	();
void	_AKUOpenWindowFunc		( const char* title, int width, int height );

#endif
