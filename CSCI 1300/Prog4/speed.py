data=open('speed.txt')

segements=int(data.readline().strip('\n'))

while segements!= -1:
    distance=0
    oldtime=0
    speed=[]
    time=[]
    for n in range(segements):
        trip=data.readline().strip('\n').split()
        if len(trip)==2:
            speed.append(int(trip[0]))
            time.append(int(trip[1]))
            distance += speed[n]*(time[n]-oldtime)
            oldtime=time[n]
    print str(distance)+' miles'
    segements=int(data.readline().strip('\n'))
