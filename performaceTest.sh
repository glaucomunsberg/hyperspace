#!/bin/bash
run=true
exampleUsed="graphExample.txt"
numberOfThreads=1
function sair()
{
	clear
	cabecalho
	echo " Exit..."
	echo "---------------------------------------------------------"
	sleep 1;
	clear;
	exit;
}

function cabecalho()
{
	echo "---------------------------------------------------------"
	echo "            Hyperspace - Performance Test                "
	echo "---------------------------------------------------------"
}

function howMuch()
{
	echo "---------------------------------------------------------"
	echo "  We will test the original implementation running 30    "
	echo "times the implementation and calculate the average about "
	echo " that."
	echo ""
	sleep 1;
	echo " How much adjacences you want use?"
	echo " 1 - 100"
	echo " 2 - 1.000"
	echo " 3 - 10.000"
	echo " 4 - 100.000"
	echo " 5 - 1.000.000"
	echo "Your Choose:"
	read thefunction
	case $thefunction in
		1) exampleUsed="graphExample1.txt";;
		2) exampleUsed="graphExample2.txt";;
		3) exampleUsed="graphExample3.txt";;
		4) exampleUsed="graphExample4.txt";;
		5) exampleUsed="graphExample5.txt";;
	esac

	echo " How much threads you want use?"
	echo "Your Choose [1-100]:"
	read numberOfThreads

}

function implementation_openmp(){
	clear 
	cabecalho
	howMuch

	cd openmp
	make
	cd ../

	echo " Running tests"
	for i in `seq 0 1 30`; do
		 /usr/bin/time -f "%S" ./openmp/graphOpen $exampleUsed $numberOfThreads > out
	done

	echo "Press ENTER" 
	read something
}

function implementation_c11()
{
	clear 
	cabecalho
	howMuch

	cd c++11
	make
	cd ../

	echo " Running tests"
	for i in `seq 0 1 30`; do
		 /usr/bin/time -f "%S" ./c++11/graphCpp11 $exampleUsed $numberOfThreads > out
	done

	echo "Press ENTER" 
	read something
}

function implementation_cilk()
{
	clear 
	cabecalho
	howMuch

	cd cilk
	make
	cd ../

	echo " Running tests"
	for i in `seq 0 1 30`; do
		 /usr/bin/time -f "%S" ./cilk/graphCilk $exampleUsed $numberOfThreads > out
	done

	echo "Press ENTER" 
	read something
}

function implementation_original()
{
	clear 
	cabecalho
	howMuch

	cd original
	make
	cd ../

	echo " Running tests"
	for i in `seq 0 1 30`; do
		 /usr/bin/time -f "%S" ./original/graphOriginal $exampleUsed $numberOfThreads > out
	done

	echo "Press ENTER" 
	read something
}

function implementation_tbb()
{
	clear 
	cabecalho
	howMuch

	cd tbb
	make
	cd ../

	echo " Running tests"
	for i in `seq 0 1 30`; do
		 /usr/bin/time -f "%S" ./tbb/graphTbb ../$exampleUsed $numberOfThreads
	done

	echo "Press ENTER" 
	read something
}

while [ $run = true ]; do
	clear
	cabecalho
	echo "  Choose the implementation that this program will test"
	echo "to you!"
	echo ""
	echo " 1 - Original"
	echo " 2 - Cilk" 
	echo " 3 - C++11"
	echo " 4 - OpenMP"
	echo " 5 - TBB"
	echo " 0 - Exit"
	echo " Your Choose:"
	leu=false
	read thefunction
	case $thefunction in
		0) sair;;
		1) implementation_original;;
		2) implementation_cilk;;
		3) implementation_c11;;
		4) implementation_openmp;;
		5) implementation_tbb;;
	esac
done

