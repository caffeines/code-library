#define ll long long
ll BigMod(ll base,ll power,ll mod)
{
    if(power == 0) return 1;
    if(power%2)
    {
        ll temp = (BigMod(base,power-1,mod));
        return ((base%mod)*(temp%mod))%mod;
    }
    else
    {
        ll temp = BigMod(base,power/2,mod);
        return ((temp%mod)*(temp%mod))%mod;
    }
}
