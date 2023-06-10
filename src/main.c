#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#define PROJECT_NAME "mesonbuildtest"

const char * str = "HelloWorld!";

double max(double a, double b){
    return a>b ? a:b;
}

static int l_max (lua_State *L) {
    double num1 = lua_tonumber(L, 1);
    double num2 = lua_tonumber(L, 2);
    lua_pushnumber(L, max(num1, num2));
    return 1;
}

int main(int argc, char **argv) {
    printf("%s\n",LUA_COPYRIGHT);
	
	unsigned int a = 1000;
	

    lua_State *L = luaL_newstate();
	luaL_openlibs(L);

    lua_pushcfunction(L, l_max);
    lua_setglobal(L, "mymax");

    if (luaL_loadstring(L, "print(mymax(100,31))") || lua_pcall(L, 0, 0, 0)) {
        printf("%s", lua_tostring(L, -1));
    }

    lua_close(L);
    return 0;
}
