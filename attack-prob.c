// poisson = poisson distribution of 0 to z
// k = current number of blocks (remember these are the actual poisson dist events) mined by the attacker
// z = current number of blocks (remember these are the expected/average poisson dist events) mined by the honest blocks
// attacker's success probabilty eqn: 1 - (poisson * (1 - ((q/p) ^ (z-k))))

// if "p > q" => (q/p) ^ z, attacker's probability to catchup increases exponentially as the amount of blocks (z) gets larger thus leaving him way behind
// if "p <= q" => 1, attacker's probability is too high thus there's a 100% guarantee he'll catch up with honest nodes

#include <math.h>
#include <stdio.h>

double factorial(int n)
{
	double res = 1;
	for (int i = 1; i <= n; ++i)
		res *= i;
	return res;
}

// z = number of blocks the attacker has to mine so as to catch up with the honest chain
// q = probability of attacker finds the next block and catches up with the honest chain
double attacker_probability_success(double q, int z)
{
	// probability of honest node finds the next block and leaves the attacker way behind
	double p = 1.0 - q;
	double lambda = z * (q / p);	// used in Poisson distribution
	double succ_chance = 1.0;

	int k;
	for (k = 0; k <= z; ++k) {
		double lambdaExp = exp(-1 * lambda);
		double lambdaToK = pow(lambda, k);
		double poisson = (lambdaExp * lambdaToK) / factorial(k);

		succ_chance -= poisson * (1 - (pow(q / p, z - k)));
	}

	return succ_chance;
}

int main(void)
{
	// when attacker's success chance is 10%
	int i;
	double q = 0.1;
	printf("q=%.1f\n", q);
	for (i = 0; i <= 10; ++i) {
		printf("when z=%d: \t%.7f\n", i,
		       attacker_probability_success(q, i));
	}

	// when attacker's success chance is 30%
	printf("\n\n");
	q = 0.3;
	printf("q=%.1f\n", q);
	for (i = 0; i <= 50; i += 5) {
		printf("when z=%d: \t%.7f\n", i,
		       attacker_probability_success(q, i));
	}

	return 0;
}
