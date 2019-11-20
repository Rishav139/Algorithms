n=int(input())
x=int(input())
for i in range(1,1000):
    if x%pow(2,i)==0:
        i+=1
    else:
        print(i-1)
        break
