build/example: main.cpp vec4.hpp
	mkdir -p $(@D)
	$(CXX) $< -liRRAM -lmpfr -o $@

.PHONY: clean
clean:
	rm -rf build