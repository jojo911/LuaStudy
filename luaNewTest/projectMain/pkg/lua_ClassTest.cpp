/*
** Lua binding: ClassTest
** Generated automatically by tolua++-1.0.92 on 07/01/14 16:29:58.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ClassTest_open (lua_State* tolua_S);

#include "ClassTest.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CClassTest (lua_State* tolua_S)
{
 CClassTest* self = (CClassTest*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CClassTest");
}

/* method: new of class  CClassTest */
#ifndef TOLUA_DISABLE_tolua_ClassTest_CClassTest_new00
static int tolua_ClassTest_CClassTest_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CClassTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CClassTest* tolua_ret = (CClassTest*)  Mtolua_new((CClassTest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CClassTest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CClassTest */
#ifndef TOLUA_DISABLE_tolua_ClassTest_CClassTest_new00_local
static int tolua_ClassTest_CClassTest_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CClassTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CClassTest* tolua_ret = (CClassTest*)  Mtolua_new((CClassTest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CClassTest");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CClassTest */
#ifndef TOLUA_DISABLE_tolua_ClassTest_CClassTest_delete00
static int tolua_ClassTest_CClassTest_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CClassTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CClassTest* self = (CClassTest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sum of class  CClassTest */
#ifndef TOLUA_DISABLE_tolua_ClassTest_CClassTest_sum00
static int tolua_ClassTest_CClassTest_sum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CClassTest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CClassTest* self = (CClassTest*)  tolua_tousertype(tolua_S,1,0);
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sum'", NULL);
#endif
  {
   int tolua_ret = (int)  self->sum(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ClassTest_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CClassTest","CClassTest","",tolua_collect_CClassTest);
  #else
  tolua_cclass(tolua_S,"CClassTest","CClassTest","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CClassTest");
   tolua_function(tolua_S,"new",tolua_ClassTest_CClassTest_new00);
   tolua_function(tolua_S,"new_local",tolua_ClassTest_CClassTest_new00_local);
   tolua_function(tolua_S,".call",tolua_ClassTest_CClassTest_new00_local);
   tolua_function(tolua_S,"delete",tolua_ClassTest_CClassTest_delete00);
   tolua_function(tolua_S,"sum",tolua_ClassTest_CClassTest_sum00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ClassTest (lua_State* tolua_S) {
 return tolua_ClassTest_open(tolua_S);
};
#endif

