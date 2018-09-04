from cs1graphics import *

size=int(raw_input('What is the unit size of a grid cell? '))
w=13*size
h=15*size
paper = Canvas(h,w)
numTri=26

#background
background=Rectangle(15*size,13*size)
background.setFillColor('burlywood4')
background.move((15*size)/2,(13*size)/2)
background.setBorderColor('burlywood4')
paper.add(background)

#foreground
foreground=Rectangle(13*size,11*size)
foreground.setFillColor('navajowhite')
foreground.move((15*size)/2,(13*size)/2)
foreground.setBorderWidth(1)
paper.add(foreground)

#middle
middle=Rectangle(size,11*size)
middle.setFillColor('burlywood4')
middle.move((15*size)/2,(13*size)/2)
middle.setBorderWidth(1.5)
middle.setDepth(0)
paper.add(middle)


#border covers
cover=Rectangle(size,13*size)
cover.setFillColor('burlywood4')
cover.setBorderWidth(0)
cover.move((15*size)/2,(13*size)/2)
cover.setDepth(0)
paper.add(cover)

#black line
line=Path(Point(7.5*size,0),Point(7.5*size,13*size))
line.setDepth(0)
line.setBorderWidth(2)
paper.add(line)



#triangles and points looping
for n in range(numTri):
    triangle=Polygon(Point((n+1)*size,size),Point((1.5+n)*size,6*size),Point((n+2)*size,size))
    if n>12:
        triangle=Polygon(Point((n-12)*size,12*size),Point((n-11.5)*size,7*size),Point((n-11)*size,12*size))
    if n in (0,2,4,7,9,11,14,16,18,21,23,25):
        triangle.setFillColor('tan')
    else:
        triangle.setFillColor('darkorange3')
    triangle.setBorderWidth(1)
    paper.add(triangle)


    for n,numCol in [(0,24),(1,23),(2,22),(3,21),(4,20),(5,19),(7,18),(8,17),(9,16),(10,15),(11,14),(12,13),(13,1),(14,2),(15,3),(16,4),(17,5),(18,6),(20,7),(21,8),(22,9),(23,10),(24,11),(25,12)]:
        num=Text(str(numCol),12,Point((1.5+n)*size,0.5*size))
        if n>12:
            num=Text(str(numCol),12,Point((n-11.5)*size,12.5*size))
        num.setDepth(0)
        paper.add(num)


cy=(1.45*size)

for tri,numCheck,color in [(0,2,'white'),(5,5,'black'),(8,3,'black'),(12,5,'white'),(13,2,'black'),(18,5,'white'),(21,3,'white'),(25,5,'black')]:
    checker=Circle(0.45*size)
    checker.setFillColor(color)
    cx=(1.5*size)+tri*size
    if tri>12:
        cx=(1.5*size)+(tri-13)*size
        cy=(11.55*size)
    for n in range(numCheck):
        points=checker.clone()
        a=cy+n*size*0.9
        if tri>12:
            a=cy-n*size*0.9
        points.move(cx,a)
        paper.add(points)
    checker.move(cx,cy)
    paper.add(checker)



    
