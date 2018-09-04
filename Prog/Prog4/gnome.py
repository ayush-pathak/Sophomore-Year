data=open('gnome.txt')

number=int(data.readline())

print 'Gnomes:'
for x in range(number):
    temp=data.readline().split()
    for n in range(len(temp)):
        temp[n]=int(temp[n])
    if temp[0]>temp[1]>temp[2] or temp[0]<temp[1]<temp[2]:
        print 'Ordered'
    else:
        print 'Unordered'
