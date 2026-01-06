all:
	@gcc -Ofast -o ./bin ./attack-prob.c -lm

clean:
	@rm -f ./bin