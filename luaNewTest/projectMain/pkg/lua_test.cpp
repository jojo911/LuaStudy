/*
** Lua binding: test
** Generated automatically by tolua++-1.0.92 on 07/01/14 16:29:58.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_test_open (lua_State* tolua_S);

#include "test.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: MyAdd */
#ifndef TOLUA_DISABLE_tolua_test_MyAdd00
static int tolua_test_MyAdd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  MyAdd(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MyAdd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_test_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"MyAdd",tolua_test_MyAdd00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_test (lua_State* tolua_S) {
 return tolua_test_open(tolua_S);
};
#endif

