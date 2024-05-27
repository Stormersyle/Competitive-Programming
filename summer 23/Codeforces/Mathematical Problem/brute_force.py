import math

def is_square(x):
    t=(int)(math.sqrt(x))
    return ((t**2==x) or ((t-1)**2==x) or ((t+1)**2==x))

def digit_set(x):
    s=[]
    while (x>0):
        s.append(x%10)
        x=(x//10)
    s.sort()
    return tuple(s)

d={}
for x in range(1000000, 10000000):
    if is_square(x):
        ds=digit_set(x)
        if ds in d:
            d[ds].append(x)
        else:
            d[ds]=[x]


for ds, nums in d.items():
    if len(nums)>=7:
        print(ds)
        print(nums)
        print("next\n")
