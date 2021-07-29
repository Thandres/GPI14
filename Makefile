rule:= ./target/aufgabeX
file:= aufgabeX
aufgaben:= 1 2 3 4 5

all: $(foreach n,$(aufgaben),$(rule:%X=%$n))

$(rule:%X=%1) : $(file:%X=%1.c)
	cc -o $(rule:%X=%1) $(file:%X=%1.c)

$(rule:%X=%2) : $(file:%X=%2.c)
	cc -o $(rule:%X=%2) $(file:%X=%2.c)

$(rule:%X=%3) : $(file:%X=%3.c)
	cc -o $(rule:%X=%3) $(file:%X=%3.c)

$(rule:%X=%4) : $(file:%X=%4.c)
	cc -o $(rule:%X=%4) $(file:%X=%4.c)

$(rule:%X=%5) : $(file:%X=%5.c)
	cc -o $(rule:%X=%5) $(file:%X=%5.c)
#$(rule:%X=%Y) : $(file:%X=%Y.c)
#	cc -o $(rule:%X=%Y) $(file:%X=%Y.c)
#$(foreach n,$(aufgaben),$(rule:%X=%$n)) :$(foreach n,$(aufgaben),$(file:%X=%$n.c))
#	$(foreach n,$(aufgaben),cc -o $(rule:%X=%$n) $(file:%X=%$n.c);) echo finished