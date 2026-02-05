# java flags and compiler call
JFLAGS = -g
JC = javac
JV = java

# compile the Java file to a class file.
Hello.class: javaPractice.java
	@ $(JC) javaPractice.java

# set target to build javaPractice class
run: Hello.class
	@ $(JV) javaPractice

# make it run, not a file
.PHONY: run

# RM remove the created class when done
clean:
	rm -f *.class