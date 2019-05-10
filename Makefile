build/example: main.cpp
	mkdir -p $(@D)
	$(CXX) $^ -liRRAM -lmpfr -o $@