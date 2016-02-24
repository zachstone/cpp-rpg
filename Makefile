#Make!

objs = src/main.cpp src/player.cpp
cc = clang++
output = build/rpg
compiler_flags = -std=c++11 -o $(output)

all:
	mkdir build
	$(cc) $(objs) $(compiler_flags)

g++:
	mkdir build
	g++ $(objs) $(compiler_flags)

run:
	$(obj_name)

clean:
	rm -R build
