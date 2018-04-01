#define N 100001
int arr[N];
int deco_array[1000];
int blk_size;

void build(int n)
{
    int blk_idx = -1;
    blk_size = sqrt(n);
    for(int i=0;i<n;i++)
    {
        if(i%blk_size == 0)
            blk_idx++;

        deco_array[blk_idx] += arr[i];
    }
}

void update(int index, int val)
{
    int new_val = val - arr[index];
    deco_array[(index/blk_size)] += new_val;
    arr[index] = val;
}

int query(int left,int right)
{
    int sum = 0;
    while(left%blk_size && left<right)
    {
        sum += arr[left];
        left++;
    }
    while(left+blk_size<=right)
    {
        sum +=deco_array[left/blk_size];
        left+=blk_size;
    }
    while(left<=right)
    {
        sum+=arr[left];
        left++;
    }
    return sum;
}
