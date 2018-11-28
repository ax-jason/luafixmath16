
#if __cplusplus
extern "C" {
#endif

#include <lua.h>
#include <lauxlib.h>
#include "fixmath.h"

#define __METATABLE_NAME "___FIX16_MATATABLE___"

static void create_meta(lua_State *L);

static fix16_t lua_tofix16(lua_State *L, int idx)
{
	fix16_t* p = luaL_testudata(L, idx, __METATABLE_NAME);
	if(p)
	{
		return *p;
	}
	else
	{
		return fix16_from_dbl(luaL_checknumber(L, idx));
	}
}

static void push_fix16(lua_State *L, fix16_t v)
{
	fix16_t* p = lua_newuserdata(L, sizeof(v));
	*p = v;
	create_meta(L);
	lua_setmetatable(L, -2);
}

static int fix_tostring(lua_State *L)
{
	lua_pushnumber(L, fix16_to_dbl(lua_tofix16(L, 1)));
	return 1;
}

static int fix_rawvalue(lua_State *L)
{
	lua_pushinteger(L, lua_tofix16(L, 1));
	return 1;
}

static int fix_add(lua_State *L)
{
	push_fix16(L, lua_tofix16(L, 1) + lua_tofix16(L, 2));
	return 1;
}

static int fix_sub(lua_State *L)
{
	push_fix16(L, lua_tofix16(L, 1) - lua_tofix16(L, 2));
	return 1;
}

static int fix_mul(lua_State *L)
{
	push_fix16(L, fix16_mul(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;
}

static int fix_div(lua_State *L)
{
	push_fix16(L, fix16_div(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;
}

static int fix_mod(lua_State *L)
{
	push_fix16(L, fix16_mod(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;
}

static int fix_pow(lua_State *L)
{
	return luaL_error(L, "pow ( ^ ) operator is not valid for fix16 type value");
}

static int fix_unm(lua_State *L)
{
	push_fix16(L, -lua_tofix16(L, 1));
	return 1;
}

static int fix_idiv(lua_State *L)
{
	push_fix16(L, fix16_floor(fix16_div(lua_tofix16(L, 1), lua_tofix16(L, 2))));
	return 1;
}

static int fix_lt(lua_State *L)
{
	lua_pushboolean(L, lua_tofix16(L, 1) < lua_tofix16(L, 2));
	return 1;
}

static int fix_le(lua_State *L)
{
	lua_pushboolean(L, lua_tofix16(L, 1) <= lua_tofix16(L, 2));
	return 1;
}
static int fix_eq(lua_State *L)
{
	lua_pushboolean(L, lua_tofix16(L, 1) == lua_tofix16(L, 2));
	return 1;
}

static int l_tofix16(lua_State *L)
{
	if(lua_isnumber(L, 1))
	{
		push_fix16(L, fix16_from_dbl(lua_tonumber(L, 1)));
		return 1;
	}
	else
	{
		return 0;
	}
}

static int fix_abs(lua_State *L)
{
	push_fix16(L, fix16_abs(lua_tofix16(L, 1)));
	return 1;
}
static int fix_floor(lua_State *L)
{
	push_fix16(L, fix16_floor(lua_tofix16(L, 1)));
	return 1;
}
static int fix_ceil(lua_State *L)
{
	push_fix16(L, fix16_ceil(lua_tofix16(L, 1)));
	return 1;
}
static int fix_min(lua_State *L)
{
	push_fix16(L, fix16_min(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;	
}
static int fix_max(lua_State *L)
{
	push_fix16(L, fix16_max(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;
}
static int fix_sin(lua_State *L)
{
	push_fix16(L, fix16_sin(lua_tofix16(L, 1)));
	return 1;
}
static int fix_cos(lua_State *L)
{
	push_fix16(L, fix16_cos(lua_tofix16(L, 1)));
	return 1;
}
static int fix_tan(lua_State *L)
{
	push_fix16(L, fix16_tan(lua_tofix16(L, 1)));
	return 1;
}
static int fix_asin(lua_State *L)
{
	push_fix16(L, fix16_asin(lua_tofix16(L, 1)));
	return 1;	
}
static int fix_acos(lua_State *L)
{
	push_fix16(L, fix16_acos(lua_tofix16(L, 1)));
	return 1;
}
static int fix_atan(lua_State *L)
{
	if(lua_isnoneornil(L, 2))
	{
		push_fix16(L, fix16_atan(lua_tofix16(L, 1)));
	}
	else
	{
		push_fix16(L, fix16_atan2(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	}
	
	return 1;
}
static int fix_atan2(lua_State *L)
{
	push_fix16(L, fix16_atan2(lua_tofix16(L, 1), lua_tofix16(L, 2)));
	return 1;
}
static int fix_deg(lua_State *L)
{
	push_fix16(L, fix16_rad_to_deg(lua_tofix16(L, 1)));
	return 1;
}
static int fix_rad(lua_State *L)
{
	push_fix16(L, fix16_deg_to_rad(lua_tofix16(L, 1)));
	return 1;
}
static int fix_sqrt(lua_State *L)
{
	push_fix16(L, fix16_sqrt(lua_tofix16(L, 1)));
	return 1;
}
static int fix_sq(lua_State *L)
{
	push_fix16(L, fix16_sq(lua_tofix16(L, 1)));
	return 1;
}
static int fix_exp(lua_State *L)
{
	push_fix16(L, fix16_exp(lua_tofix16(L, 1)));
	return 1;	
}
static int fix_log(lua_State *L)
{
	if(lua_isnoneornil(L, 2))
	{
		push_fix16(L, fix16_log(lua_tofix16(L, 1)));
	}
	else
	{
		push_fix16(L, fix16_div(fix16_log(lua_tofix16(L, 1)), fix16_log(lua_tofix16(L, 2))));
	}
	
	return 1;
}

#ifdef WIN32
#define LUA_LIB_API __declspec(dllexport)
#else
#define LUA_LIB_API
#endif

const luaL_Reg lua_fixmath16_meta_methods[] = {
	{"__add",   fix_add},
	{"__sub",   fix_sub},
	{"__mul",   fix_mul},
	{"__div",   fix_div},
	{"__mod",   fix_mod},
	{"__pow",   fix_pow},
	{"__unm",   fix_unm},
	{"__idiv",   fix_idiv},
	{"__lt",   fix_lt},
	{"__le",   fix_le},
	{"__eq",   fix_eq},
	{"__tostring",   fix_tostring},
	{NULL, NULL}
};

const luaL_Reg lua_fixmath16_modules[] = {
	{"tofix16",   l_tofix16},
	{"tostring",   fix_tostring},
	{"tonumber",   fix_tostring},
	{"rawvalue",   fix_rawvalue},
	{"abs",   fix_abs},
	{"floor",   fix_floor},
	{"ceil",   fix_ceil},
	{"min",   fix_min},
	{"max",   fix_max},
	{"sin",   fix_sin},
	{"cos",   fix_cos},
	{"tan",   fix_tan},
	{"asin",   fix_asin},
	{"acos",   fix_acos},
	{"atan",   fix_atan},
	{"atan2",   fix_atan2},
	{"deg",   fix_deg},
	{"rad",   fix_rad},
	{"sqrt",   fix_sqrt},
	{"sq",   fix_sq},
	{"exp",   fix_exp},
	{"log",   fix_log},
	{NULL, NULL}
};


static void fill_meta(lua_State *L)
{
	luaL_setfuncs(L, lua_fixmath16_meta_methods, 0);

	luaL_newlib(L, lua_fixmath16_modules);
  	lua_setfield(L, -2, "__index");
}

static void create_meta(lua_State *L)
{
	if(luaL_newmetatable (L, __METATABLE_NAME) != 0)
	{
		fill_meta(L);
	}
}

LUA_LIB_API int luaopen_fixmath16(lua_State* L)
{
    	luaL_newlib(L, lua_fixmath16_modules);
    	push_fix16(L, fix16_pi);
  	lua_setfield(L, -2, "pi");
      	push_fix16(L, fix16_maximum);
  	lua_setfield(L, -2, "maxvalue");
      	push_fix16(L, fix16_minimum);
  	lua_setfield(L, -2, "minvalue");
	return 1;
}

#if __cplusplus
}
#endif