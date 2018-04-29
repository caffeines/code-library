int maxSubArraySum(int a[],int n)
{
    int current_max=0,final_max=0;

    for(int i=0;i<n;i++)
    {
        current_max = MAX(a[i],current_max+a[i]);
        final_max = MAX(final_max,current_max);
    }
    return final_max;
}
