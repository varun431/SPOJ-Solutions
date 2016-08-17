#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;

const int L1D_CACHE_SIZE = 32768;
std::vector<int64_t> p;

void segmented_sieve(int64_t limit, int segment_size = L1D_CACHE_SIZE)
{
  int sqrt = (int) std::sqrt((double) limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;

  // vector used for sieving
  std::vector<char> sieve(segment_size);

  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  std::vector<int> primes;
  std::vector<int> next;

  for (int64_t low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, limit);

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
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    p.push_back(2);
    for (; n <= high; n += 2)
      if (sieve[n - low])
      {
        p.push_back(n);
        count++;
      }
  }
}

LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(LL n)
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

LL sod(LL num)
{
    LL count, sum, i,n=num;
    sum = 1;
    for(i=0; p[i]*p[i]<=num ; i++)
    {
        count = 1;
        while(num%p[i] == 0)
        {
            count=count*p[i] + 1;
            num/=p[i];
        }
        sum = sum*count;
    }
    if(num>2)
    {
        sum *= (1+num);
    }
    return sum-n;
}

int main()
{
    segmented_sieve(100000000);
    unsigned t;
    t = read();
    while(t--)
    {
        LL n;
        n = read();
        if(n==2)
        {
            printf("1\n");
            continue;
        }
        write(sod(n));
    }
}
