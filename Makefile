#Make!

objs = main.cpp player.cpp
cc = g++
obj_name = rpg
compiler_flags = -std=c++11 -o $(obj_name)

all:
	$(cc) $(objs) $(compiler_flags)

run:
	./$(obj_name)
