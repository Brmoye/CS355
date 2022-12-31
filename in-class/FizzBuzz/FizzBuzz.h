#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

class FizzBuzz
{
	private:
		int limit;
		
	public:
		FizzBuzz(int lim = 100);
		void run();
		void setLimit();
		int menu();
		
};

#endif // FIZZBUZZ_H