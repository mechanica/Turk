Mechanical Turk
===============
GLFW 3.0 OS X host for MOAI.

Project consist of two targets: MOAI-GLFW, which is binary executable, and Turk.app, which is app bundle.

MOAI-GLFW behaves like default MOAI host, while Turk.app provides you a way to bundle your lua scripts inside Resource folder, change info.plist settings, icon and ship it as full-featured application. I doubt it is suitable for production use, but it's all i can do for now.

Feel free to fork, hack, post an issues and suggestions. Do not hesitate to contact me personally if something goes wrong. I'm avaliable at [Twitter](twitter.com/enykeev), Skype (enykeev), and IRC both ```#moai@freenode``` and ```#glfw@freenode``` or you can contact me personally by ```/query enykeev```. I'm also avaliable at github@mechanica.io.

Pre-Build
---------

Only thing you need to do before building Mechanical Turk using Xcode is CMake GLFW.xcodeproj file.  
```
cmake -G Xcode -DGLFW_USE_CHDIR=OFF 3rdparty/glfw3/CMakeLists.txt
```  
Hope some day i'll find a way to make it even easier.

Bundle features
---------------

For now the only thing you can change in Info.plist (except for default apple keys) is a filename of initial script to run.
```xml
<key>MTMainScript</key>
<string>main</string>
```
You should omit .lua in here.

Additional API (subject to change in the near future)
-----------------------------------------------------

### MOAIHostMgr
A singleton that interfaces GLFW.

### MOAIHostMgr.setWindowSize( width, height )
Sets the size of the window.

### MOAIHostMgr.getTime()
Returns the value of the high precision timer. The time is measured in seconds, and is
returned as a double precision ﬂoating point value.

### MOAIHostMgr.getVideoModes()
Returns a table of available video modes. Each video modes is represented as a table with the following keys:
```lua
{
  blueBits = 8,
  greenBits = 8,
  height = 1440,
  redBits = 8,
  width = 2560
}
```

### MOAIHostMgr.getDesktopVideoMode()
Returns the current video mode of the desktop, see above.

### MOAIHostMgr:setOnWindowCloseCallback( callbackFunction )
Set a callback that is called when a user requests that the window should be
closed, typically by clicking the window close icon (e.g. the cross in the upper right corner of a
window under Microsoft Windows), and on Mac OS X also when selecting Quit from the
application menu.
```lua
function callbackFunction()
  -- ...
  return true -- or false if you want to prevent window from closing  
end
```
If callback function returns false, window won't be closed.

### MOAIHostMgr.minimiseWindow()
Minimizes window to dock.

### MOAIHostMgr.restoreWindow()
Restores window from dock.

### MOAIHostMgr.setInputMode( mode, value )
Enable and disable input modes. Mode can be one of the followin constants:
* ```MOAIHostMgr.HOST_CURSOR_MODE```   
Sets the cursor mode. Acceptable values are:
  * ```MOAIHostMgr.HOST_CURSOR_NORMAL```  
  The cursor is visible and behaves normally.
  * ```MOAIHostMgr.HOST_CURSOR_HIDDEN```  
  The cursor is hidden when over the client area of the window.
  * ```MOAIHostMgr.HOST_CURSOR_CAPTURED```  
  The cursor is disabled and cursor movement is unbounded.
* ```MOAIHostMgr.HOST_STICKY_KEYS```   
Sets whether sticky keys are enabled.
* ```MOAIHostMgr.HOST_STICKY_MOUSE_BUTTONS```  
Sets whether sticky mouse buttons are enabled.

See http://www.glfw.org/GLFWReference30.pdf for information on this.

### Keyboard keys
```MOAIHostMgr.HOST_KEY_SPACE```, ```MOAIHostMgr.HOST_KEY_ESCAPE```, ```MOAIHostMgr.HOST_KEY_F[1-25]```,
```MOAIHostMgr.HOST_KEY_TAB```, ```MOAIHostMgr.HOST_KEY_ENTER```, ```MOAIHostMgr.HOST_KEY_BACKSPACE```,  

```MOAIHostMgr.HOST_KEY_UP```, ```MOAIHostMgr.HOST_KEY_DOWN```, ```MOAIHostMgr.HOST_KEY_LEFT```, ```MOAIHostMgr.HOST_KEY_RIGHT```,

```MOAIHostMgr.HOST_KEY_LEFT_SHIFT```, ```MOAIHostMgr.HOST_KEY_RIGHT_SHIFT```,
```MOAIHostMgr.HOST_KEY_LEFT_CONTROL```, ```MOAIHostMgr.HOST_KEY_RIGHT_CTRL```,
```MOAIHostMgr.HOST_KEY_LEFT_ALT```, ```MOAIHostMgr.HOST_KEY_RIGHT_ALT```,
```MOAIHostMgr.HOST_KEY_LEFT_SUPER```, ```MOAIHostMgr.HOST_KEY_RIGHT_SUPER```,

```MOAIHostMgr.HOST_KEY_INSERT```, ```MOAIHostMgr.HOST_KEY_HOME```, ```MOAIHostMgr.HOST_KEY_PAGE_UP```, 
```MOAIHostMgr.HOST_KEY_DELETE```, ```MOAIHostMgr.HOST_KEY_END```, ```MOAIHostMgr.HOST_KEY_PAGE_DOWN```,  

```MOAIHostMgr.HOST_KEY_KP_[0-9]```, ```MOAIHostMgr.HOST_KEY_KP_DIVIDE```, ```MOAIHostMgr.HOST_KEY_KP_MULTIPLY```, ```MOAIHostMgr.HOST_KEY_KP_SUBTRACT```, ```MOAIHostMgr.HOST_KEY_KP_ADD```, ```MOAIHostMgr.HOST_KEY_KP_DECIMAL```, ```MOAIHostMgr.HOST_KEY_KP_EQUAL```, ```MOAIHostMgr.HOST_KEY_KP_ENTER```,

```MOAIHostMgr.HOST_KEY_NUM_LOCK```, ```MOAIHostMgr.HOST_KEY_CAPS_LOCK```, ```MOAIHostMgr.HOST_KEY_SCROLL_LOCK```, ```MOAIHostMgr.HOST_KEY_PAUSE```, ```MOAIHostMgr.HOST_KEY_MENU```