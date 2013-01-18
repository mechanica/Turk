// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIHOSTMGR_H
#define MOAIHOSTMGR_H

#include <moaicore/pch.h>

#include <moaicore/MOAILua.h>
#include <GL/glfw3.h>

//================================================================//
// MOAIHostMgr
//================================================================//
/**	@name	MOAIHostMgr
*/
class MOAIHostMgr :
	public MOAIGlobalClass < MOAIHostMgr, MOAILuaObject > {
private:

    MOAILuaRef      mOnWindowClosed;
	static int		_setWindowSize		( lua_State* L );
	static int		_getTime			( lua_State* L );
	static int		_getVideoModes		( lua_State* L );
	static int		_getDesktopVideoMode ( lua_State* L );
    static int		_setOnWindowCloseCalback ( lua_State* L );
    static int		_minimiseWindow		( lua_State* L );
    static int		_restoreWindow		( lua_State* L );
    static int		_setInputMode		( lua_State* L );
	
public:
	
	DECL_LUA_SINGLETON ( MOAIHostMgr )

	//----------------------------------------------------------------//
					MOAIHostMgr			();
					~MOAIHostMgr		();
	void			RegisterLuaClass	( MOAILuaState& state );
    MOAILuaRef*		GetOnWindowClosedLuaFunction ();
};

#endif
