# Compiler Command
CC = clang++

# Find all .cpp source files
SRCS = $(shell find . -name '*.cpp')

# For each source file, add a .PHONY rule
.PHONY: $(SRCS)

# Executabel files (remove the .cpp extension for each source file)
EXES = $(SRCS:.cpp=)  

OUTPUTDIR = bin

mkdir: 
	mkdir -p $(OUTPUTDIR)

# Compile source files into excutable|object files
%: %.cpp mkdir
	$(CC) $< -o $(OUTPUTDIR)/$@
	./$(OUTPUTDIR)/$(@:.cpp=)

$(SRCS): mkdir
	$(CC) $@ -o $(OUTPUTDIR)/$(@:.cpp=) 
	./$(OUTPUTDIR)/$(@:.cpp=)

%.o: %.cpp
	$(CC) -c $< -o $(OUTPUTDIR)/$@

# Clean the generated files
clean:
	rm -f $(EXES)