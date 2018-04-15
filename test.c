#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include <stdio.h>


/**
 * -4 -3 -2 -1 _ 1 2 3 4
 *  1  2  3  4 _ 1 2 3 4 
 */
static int testfunc(lua_State *L)
{
  printf("in testfunc\n");

  int l1 = luaL_checkint(L, 1);
  int l2 = luaL_checkint(L, 2);
  int l3 = luaL_checkint(L, 3);
  int l4 = luaL_checkint(L, 4);

  printf("l1:%d, l2:%d, l3:%d, l4:%d\n", l1, l2, l3, l4);

  lua_pushinteger(L, 1);
  lua_pushinteger(L, 2);
  lua_pushinteger(L, 3);
  lua_pushinteger(L, 4);

  printf("ll1:%d, ll2:%d, ll3:%d, ll4:%d\n", 
        luaL_checkint(L, -1), luaL_checkint(L, -2),
        luaL_checkint(L, -3), luaL_checkint(L, -4));

  return 4;
}

static int call(lua_State *L)
{
  //luaL_checkudata(L, );
  printf("in call\n");

  lua_pushvalue(L, 1);
  lua_pushstring(L, "hello world");

  if (lua_pcall(L, 1, 0, 0)) {
    luaL_error(L, "%s", luaL_checkstring(L, -1));
  }

  lua_getglobal(L,"abc");
  lua_getglobal(L,"table1");
  printf("%p\n", lua_topointer(L, -1));

  return 0;
}


static const luaL_Reg reg[] = {
  {"print", testfunc},
  {"call", call}
};


int luaopen_test(lua_State* L){
    luaL_register(L, "test", reg);

    return 1;
}