#include <iostream>
#include <string>
using namespace std;

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "tolua++.h"

void LuaSimpleStringTest(lua_State* L)
{
	//最简单的使用lua，打印hello world
	std::string str = "print('hello world')";
	luaL_dostring(L, str.c_str());
}

void LuaSimpleFileTest(lua_State* L)
{
	//加载加执行lua文件
	luaL_dofile(L, "../projectMain/lua/test.lua");

// 	char ch;
// 	cin>>ch;
// 
// 	//加载加执行lua文件,测试发现会再次加载，所以修改了lua文件立即生效
// 	luaL_dofile(L, "../projectMain/lua/test.lua");
// 
// 	//这边是方便查看
// 	cin>>ch;
}

void LuaComplexFileTest(lua_State* L)
{
	//加载加执行lua文件
	luaL_dofile(L, "../projectMain/lua/class_test.lua");
}

void LuaInteractiveTest(lua_State* L)
{
	// http://blog.csdn.net/perfect2011/article/details/19200511
	//加载执行lua文件
	luaL_dofile(L, "../projectMain/lua/interactive.lua");

	//当一个C函数返回后，Lua会清理他的栈

	//获取myName变量的值
	lua_getglobal(L, "myName");
	string myName =lua_tostring(L, -1);

	//获取table中变量的值
	lua_getglobal(L, "helloTable");
	//Lua5.1还引入了一个新方法：
	//lua_getfield(L, -1, "name");
	lua_pushstring(L, "name");
	lua_gettable(L, -2);
	string myNameInTable1 =lua_tostring(L, -1);

	lua_getglobal(L, "helloTable");
	string myNameInTable2 =lua_tostring(L, -2);

	lua_pop(L, 1);
	string myNameInTable3 =lua_tostring(L, -1);

	//执行lua的函数，并获取返回值
	lua_getglobal(L, "useforc");
	lua_pushnumber(L, 100);
	lua_pushstring(L, "hello world");
	lua_pcall(L, 2, 2, 0);

	string str =lua_tostring(L, -1);
	int nresult =lua_tonumber(L, -2);
	printf("useforc result = %s, %d\n", str.c_str(), nresult);
}

TOLUA_API int  tolua_test_open (lua_State* tolua_S);
TOLUA_API int  tolua_ClassTest_open (lua_State* tolua_S);

int main()
{
	int a = -1;
	unsigned int b = a;
	lua_State* L = lua_open(); // 创建Lua接口指针
	//luaopen_base(L);   // 加载Lua基本库
	luaL_openlibs(L); // 加载Lua通用扩展库

	//LuaSimpleStringTest(L);

	//生成的过程中，根据包的文件生成的一个函数,这里我们需要在Main中定义一下！
	//调用它，让它把生成的代码内嵌到LUA中.漏了就找不到函数了
	tolua_test_open( L );
	tolua_ClassTest_open( L );

	LuaSimpleFileTest(L);
	LuaComplexFileTest(L);
	LuaInteractiveTest(L);

	lua_close(L);

	char ch;
	cin>>ch;
	return 0;
}