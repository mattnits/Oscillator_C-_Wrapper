cppsrc = $(wildcard *.cpp)

obj = $(cppsrc:.c=.o)

LDFLAGS = -Wall -Wextra -Werror 

Oscillator: $(obj)
	$(CXX) -o $@ $^ -lcurl