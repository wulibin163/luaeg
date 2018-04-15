LUA_SRC_DIR=lua-5_1_1

all: build

build:
	gcc -o test.so -shared  -I$(LUA_SRC_DIR) *.c $(LUA_SRC_DIR)/liblua.a

buildlua:
	cd $(LUA_SRC_DIR) && make

mytest: build
	lua my.lua
