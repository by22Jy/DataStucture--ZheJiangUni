Position BinarySearch( List L, ElementType X )
{
    int l = 1,r = L->Last;
    while(l!=r){
        int center = (l+r)>>1;
        if(L->Data[center]>=X) r = center;
        else l = center+1;
    }
    if (L->Data[l] == X) return l;
    else return NotFound;
}