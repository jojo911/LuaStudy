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
	//��򵥵�ʹ��lua����ӡhello world
	std::string str = "print('hello world')";
	luaL_dostring(L, str.c_str());
}

void LuaSimpleFileTest(lua_State* L)
{
	//���ؼ�ִ��lua�ļ�
	luaL_dofile(L, "../projectMain/lua/test.lua");

// 	char ch;
// 	cin>>ch;
// 
// 	//���ؼ�ִ��lua�ļ�,���Է��ֻ��ٴμ��أ������޸���lua�ļ�������Ч
// 	luaL_dofile(L, "../projectMain/lua/test.lua");
// 
// 	//����Ƿ���鿴
// 	cin>>ch;
}

void LuaComplexFileTest(lua_State* L)
{
	//���ؼ�ִ��lua�ļ�
	luaL_dofile(L, "../projectMain/lua/class_test.lua");
}

void LuaInteractiveTest(lua_State* L)
{
	// http://blog.csdn.net/perfect2011/article/details/19200511
	//����ִ��lua�ļ�
	luaL_dofile(L, "../projectMain/lua/interactive.lua");

	//��һ��C�������غ�Lua����������ջ

	//��ȡmyName������ֵ
	lua_getglobal(L, "myName");
	string myName =lua_tostring(L, -1);

	//��ȡtable�б�����ֵ
	lua_getglobal(L, "helloTable");
	//Lua5.1��������һ���·�����
	//lua_getfield(L, -1, "name");
	lua_pushstring(L, "name");
	lua_gettable(L, -2);
	string myNameInTable1 =lua_tostring(L, -1);

	lua_getglobal(L, "helloTable");
	string myNameInTable2 =lua_tostring(L, -2);

	lua_pop(L, 1);
	string myNameInTable3 =lua_tostring(L, -1);

	//ִ��lua�ĺ���������ȡ����ֵ
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
	lua_State* L = lua_open(); // ����Lua�ӿ�ָ��
	//luaopen_base(L);   // ����Lua������
	luaL_openlibs(L); // ����Luaͨ����չ��

	//LuaSimpleStringTest(L);

	//���ɵĹ����У����ݰ����ļ����ɵ�һ������,����������Ҫ��Main�ж���һ�£�
	//�����������������ɵĴ�����Ƕ��LUA��.©�˾��Ҳ���������
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