#include <bits/stdc++.h>
#define max 1000000000
using namespace std;

const int L1D_CACHE_SIZE = 32768;
vector<int> prime;

void segmented_sieve(int64_t limit)
{
  prime.push_back(2);
  int segment_size = L1D_CACHE_SIZE;
  int sqt = (int)sqrt((double)limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;

  // vector used for sieving
  vector<char> sieve(segment_size);

  // generate small primes <= sqrt
  vector<char> is_prime(sqt + 1, 1);
  for (int i = 2; i * i <= sqt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqt; j += i)
        is_prime[j] = 0;

  vector<int> primes;
  vector<int> next;

  for (int64_t low = 0; low <= limit; low += segment_size)
  {
    fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = min(low + segment_size - 1, limit);

    // store small primes needed to cross off multiples
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    // sieve the current segment
    for (size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    for (; n <= high; n += 2)
      if (sieve[n - low])
      {
        prime.push_back(n);
      }
    //prime.push_back(1000000007);
  }
}

void write(int n)
{
    char out[32],i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

int main()
{
    segmented_sieve(max);
    int i,k,j,count=0;
    for(i=0; prime[i]<=max; i+=500)
        //printf("%d\n",prime[i]);
        write(prime[i]);
    //cout<<prime[0]<<" "   <<prime[1];
}
