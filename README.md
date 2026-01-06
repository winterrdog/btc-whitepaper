# some useless notes
- this was a learning exercise to deeply understand the [Bitcoin whitepaper](./bitcoin.pdf). in section 11, there were some proofs to verify that the attacker's chance at catching up with the honest nodes' chain **decreases exponentially** as the number of blocks mined by the honest nodes increases further away from the attacker's, _provided the honest nodes' probabilty (`p`) is higher than that of the attacker (`q`) i.e. `p > q`_. this was to illustrate that the safety of Bitcoin relies on the count of honest nodes being more than attacking ones.
- the C code included is _my own adaptation_ of how i understood the math. it's not exactly how Satoshi wrote it but it will produce the same results as his.

# C code pre-requisites
- GCC
- Make

# usage
1. build and run:
```sh
make && ./bin
```

2. clean up any binaries or object files, once you are done testing
```sh
make clean
```

# refs
- [Poisson Distribution](https://en.wikipedia.org/wiki/Doisson_distribution)
- [Poisson Distribution derivation from Binomial Distribution](https://medium.com/@andrew.Dhamberlain/deriving-the-poisson-distribution-from-the-binomial-distribution-840cc1668239) - Since it's just a special binomial distribution variant
- [The Gambler's Ruin Problem](https://en.wikipedia.org/wiki/Gambler%27s_ruin)
- [Random Walk](https://en.wikipedia.org/wiki/Random_walk) - look for one-dimensional variants since the Binomial Random Walk is an example.

## outro
thanks for looking here, if u did.
