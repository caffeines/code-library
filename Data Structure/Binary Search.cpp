
int a[100];
int binarySearch( int l, int r ,int n ) {

    while ( l < r ) {
        int mid = (l+r)/2; /// divide into two

        if( a[mid] == n )
            return mid; /// key found and returning position
        if( n < a[mid] ) {
            r = mid-1; /// left portion less than key
        }
        else if( n > a[mid] ) {
            l = mid+1; /// right portion less than key
        }
    }
    return -1; /// key not found

}
