data= open('rps.txt')

p1=data.readline().strip('\n')
p2=data.readline().strip('\n')
while p1!='E' or p2!='E':
    p1=' '.join(p1).split()
    p2=' '.join(p2).split()
    c1=0
    c2=0
    for x in range(len(p1)):
        if (p1[x],p2[x])==('P','S') or (p1[x],p2[x])==('R','P') or (p1[x],p2[x])==('S','R'):
            c2 += 1
        elif (p2[x],p1[x])==('P','S') or (p2[x],p1[x])==('R','P') or (p2[x],p1[x])==('S','R'):
            c1 += 1
    print 'P1:',+c1
    print 'P2:',+c2

    p1=data.readline().strip('\n')
    p2=data.readline().strip('\n')
