DetectLoopInLinkedList: DetectLoopInLinkedList.o
	g++ -g -o DetectLoopInLinkedList.exe DetectLoopInLinkedList.o -pthread    

DetectLoopInLinkedList.o: DetectLoopInLinkedList/DetectLoopInLinkedList.cpp
	g++ -g  -c -pthread DetectLoopInLinkedList/DetectLoopInLinkedList.cpp
