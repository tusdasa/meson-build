project(
  'mesonbuildtest', 
  'c',
  version : '0.1',
  default_options : ['warning_level=3']
)

cc = meson.get_compiler('c')

lua_lib_deps = [cc.find_library('m', required: false)]

lua_lib = static_library(
  'lua',
  [
  'lua-5.4.6/src/lapi.c',
  'lua-5.4.6/src/lauxlib.c',
  'lua-5.4.6/src/lbaselib.c',
  'lua-5.4.6/src/lcode.c',
  'lua-5.4.6/src/lcorolib.c',
  'lua-5.4.6/src/lctype.c',
  'lua-5.4.6/src/ldblib.c',
  'lua-5.4.6/src/ldebug.c',
  'lua-5.4.6/src/ldo.c',
  'lua-5.4.6/src/ldump.c',
  'lua-5.4.6/src/lfunc.c',
  'lua-5.4.6/src/lgc.c',
  'lua-5.4.6/src/linit.c',
  'lua-5.4.6/src/liolib.c',
  'lua-5.4.6/src/llex.c',
  'lua-5.4.6/src/lmathlib.c',
  'lua-5.4.6/src/lmem.c',
  'lua-5.4.6/src/loadlib.c',
  'lua-5.4.6/src/lobject.c',
  'lua-5.4.6/src/lopcodes.c',
  'lua-5.4.6/src/loslib.c',
  'lua-5.4.6/src/lparser.c',
  'lua-5.4.6/src/lstate.c',
  'lua-5.4.6/src/lstring.c',
  'lua-5.4.6/src/lstrlib.c',
  'lua-5.4.6/src/ltable.c',
  'lua-5.4.6/src/ltablib.c',
  'lua-5.4.6/src/ltm.c',
  'lua-5.4.6/src/lundump.c',
  'lua-5.4.6/src/lutf8lib.c',
  'lua-5.4.6/src/lvm.c',
  'lua-5.4.6/src/lzio.c',
  ],
  dependencies: lua_lib_deps,
  implicit_include_directories: false,
)

inc = include_directories('lua-5.4.6/src')
lua_dep = declare_dependency(link_with: lua_lib, include_directories: inc)

exe = executable(
  'mesonbuildtest',
  ['src/main.c'],
#  link_with: lua_lib,
  dependencies: lua_dep,
  implicit_include_directories: false,
  install : true,
#  include_directories:[inc]
)

test('basic', exe)
