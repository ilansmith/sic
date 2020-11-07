JCC=javac

CLS=Func.class

all: $(CLS)

%.class: %.java
	$(JCC) -g -Werror $<

clean:
	rm -f *.class

cleanall: clean
	rm -f tags

