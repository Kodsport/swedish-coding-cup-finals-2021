def ask(a,b,c,d):
    print("? " + str(a) + " " + str(b) + " " + str(c) + " " + str(d))
    ans = int(input())
    return ans

def solve(lo, hi):
    if (lo == hi):
        x = ask(0,0,lo,hi+1)
        if x:
            return 1
        else:
            return 0
    elif lo > hi:
        return 0
    a = 2*lo
    b = 2*hi
    mid = (a+b)//2
    x = ask(lo, (mid+1)//2, mid//2+1, hi+1)
    while x:
        if x == -1:
            b = mid - 1
        elif x == 1:
            a = mid + 1
        mid = (a+b)//2
        x = ask(lo, (mid+1)//2, mid//2+1, hi+1)
    ans = 0
    if (mid%2 == 0 and ask(0,0,mid//2, mid//2+1)):
        ans+=1
    if (hi - (mid//2+1) < ((mid+1)//2-1) - lo):
        ans += 2*solve(mid//2+1,hi)
    else:
        ans += 2*solve(lo,(mid+1)//2-1)
    return ans

n = int(input())
print("! " + str(solve(0,n-1)))
