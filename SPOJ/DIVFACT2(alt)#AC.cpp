#include <bits/stdc++.h>
#define max 100000000
#define ULL unsigned long long
using namespace std;
const int L1D_CACHE_SIZE = 32768;
std::vector<int64_t> p;
ULL endind;

void segmented_sieve(int64_t limit)
{
  p.push_back(2);
  int segment_size = L1D_CACHE_SIZE;
  int sqrt = (int) std::sqrt((double) limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;
  std::vector<char> sieve(segment_size);
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
    int64_t high = std::min(low + segment_size - 1, limit);
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    for (; n <= high; n += 2)
      if (sieve[n - low])
      {
        p.push_back(n);
        count++;
      }
  }
  endind = count;
}

inline ULL pow(ULL base,ULL exp,ULL mod)
{
    ULL ans = 1;
    while(exp>0)
    {
        if(exp&1)
        {
            ans = (ans*base)%mod;
        }
        base = (base*base)%mod;
        exp>>=1;
    }
    return ans;
}

inline unsigned long long check(unsigned long long n, unsigned long long mod)
{
    if(n>=mod)
        return n%mod;
    else
        return n;
}

inline ULL toBase(ULL n, ULL p) {
    ULL high=1,pow;
    pow = n/p;
    while (pow!= 0) {

        high += pow;
        pow = pow/p;
    }
    return high;
}

inline ULL bin(ULL n,bool z)
{
    ULL low=0,high=endind,mid;
    while(low<=high)
    {
        mid = (low+high)>>1;
        if(p[mid] == n)
        {
            return mid;
        }
        if(p[mid] > n)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return (z==0) ? low : high;
}

int main()
{
    segmented_sieve(max);
    int t;
    unsigned long long power;
    unsigned long long n,mod,i,j,total,sqt,a,b,low,high;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&n,&mod);
        i=1,j=0;
        total=1;
        sqt = (int)sqrt(n);
        while(i <= sqt)
        {
            int flag=1;
            if(i == p[j])
            {
                power = toBase(n,p[j]);
                flag=0;
                total = check(total*power,mod);
                j++;
            }
            if(i==sqt && flag==0)
            {
                i++;
                continue;
            }
            a = n/i, b = (n/(i+1))+1;
            low = bin(b,0), high = bin(a,1);
            if(p[low] > a)
            {
                i++;
                continue;
            }
            power = pow(1+i,high-low+1,mod);;
            total = check(total*power,mod);
            i++;
        }
        printf("%llu\n",total);
    }
}
