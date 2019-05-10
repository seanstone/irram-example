CPPFLAGS += -O2
CXXFLAGS += -std=c++14
LDLIBS += -liRRAM -lmpfr

build/example: main.cpp *.hpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -rf build