#Make!

objs = src/main.cpp src/player.cpp
cc = g++
output = build/rpg
compiler_flags = -std=c++14 -o $(output)

all:
	mkdir -p build
	$(cc) $(objs) $(compiler_flags)

g++:
	mkdir -p build
	g++ $(objs) $(compiler_flags)

run:
	$(obj_name)

clean:
	rm -R build
