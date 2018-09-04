data= open('dup.txt')

numbers= data.readline().strip('\n').split()
first=numbers.pop(0)

while first!=0:
    temp=[]
    for n in range(len(numbers)):
        temp.append(int(numbers[n]))
    new=[]
    for x in range(len(temp)):
        if temp[x-1]!=temp[x]:
            new.append(temp[x])
        elif temp[x] not in new:
            new.append(temp[x])
    for y in range(len(new)):
        print new[y],
    print '$'
    numbers=data.readline().strip('\n').split()
    first=numbers.pop(0)

    if numbers==[]:
        break
    
    


