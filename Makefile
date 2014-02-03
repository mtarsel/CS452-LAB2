un: myexample.cpp
	g++ lab2.cpp myexample.cpp -lglut -lGLU -lGL -lGLEW -g
        
clean: 
	rm -f *.out *~ run
