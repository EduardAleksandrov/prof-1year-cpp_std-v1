run_one:
	g++ -std=c++23 ./1.program.cpp -o ./build/1.program && ./build/1.program

run_2:
	g++ -std=c++23 ./2.async.cpp -o ./build/2.async && ./build/2.async

run_3:
	g++ -std=c++23 ./3.async.cpp -o ./build/3.async && ./build/3.async

run_4:
	g++ -std=c++23 ./4.async.cpp -o ./build/4.async && ./build/4.async

run_5:
	g++ -std=c++23 ./5.async.cpp -o ./build/5.async && ./build/5.async

run_6:
	g++ -std=c++23 ./6.async.cpp -o ./build/6.async && ./build/6.async

run_7:
	g++ -std=c++23 ./7.thread.cpp -o ./build/7.thread && ./build/7.thread

run_8:
	g++ -std=c++23 ./8.pthread.cpp -o ./build/8.pthread -lpthread && ./build/8.pthread