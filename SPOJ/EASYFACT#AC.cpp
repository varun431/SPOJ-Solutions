#include <bits/stdc++.h>
#define max 100000007
#define ULL long long
using namespace std;
const int L1D_CACHE_SIZE = 32768;
vector<int> p;
int endind;

void segmented_sieve(int limit)
{
  int segment_size = L1D_CACHE_SIZE;
  int sqrt = (int)std::sqrt((double) limit);
  int count = (limit < 2) ? 0 : 1;
  int s = 2;
  int n = 3;
  vector<char> sieve(segment_size);
  vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;
  vector<int> primes;
  vector<int> next;
  for (int low = 0; low <= limit; low += segment_size)
  {
    fill(sieve.begin(), sieve.end(), 1);
    int high = min(low + segment_size - 1, limit);
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
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
        p.push_back(n);
        count++;
      }
  }
  endind = count;
}

int read()
{
    int input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
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

inline int check(ULL n, int mod)
{
    if(n>=mod)
        return int(n%mod);
    else
        return int(n);
}

inline int pow(ULL base,int exp,int mod)
{
    int ans = 1;
    while(exp>0)
    {
        if(exp&1)
        {
            ans = check(ans*base,mod);
        }
        base = check(base*base,mod);
        exp>>=1;
    }
    return ans;
}

/* To find the multiples of a prime number */
inline int toBase(int n, int p, int mod) {
    int high=1,pow;
    pow = n/p;
    while (pow!= 0)
    {
        high += pow;
        pow = pow/p;
    }
    return high;
}

inline int bin(int n,bool z)
{
    int low=0,high=endind,mid;
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
    int n,mod,i,j,total,sqt,a,b,low,high,t,ans;
    ULL power;
    t = read();
    while(t--)
    {
        n = read(), mod = read();
        i=1,j=0;
        total=1;
        sqt = sqrt(n);
        bool lastcheck = ((n/sqt)==sqt);
        while(i <= sqt)
        {
            int flag=1;
            if(i==p[j])
            {
                power = toBase(n,p[j],mod);
                flag=0;
                total = check(total*power,mod);
                if(total==0)
                    break;
                j++;
            }
            if(flag==0 && i==sqt && lastcheck)
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
            power = pow(1+i,high-low+1,mod);
            total = check(total*power,mod);
            if(total==0)
                break;
            i++;
        }
        ans = total-1;
        if(ans < 0)
            write(mod-1);
        else
            write(ans);
    }
}
