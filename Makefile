build/example: main.cpp *.hpp
	mkdir -p $(@D)
	$(CXX) $< -liRRAM -lmpfr -o $@

.PHONY: clean
clean:
	rm -rf build