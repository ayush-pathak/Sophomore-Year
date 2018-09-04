from cs1graphics import *

size= 30
paper=Canvas()
paper.setWidth(300)
paper.setHeight(300)

numCircles=10


for n in range(numCircles):
    cir=Circle(10)
    cir.setFillColor('black')
    cx=(0.75*size)
    cy=(1.25*size)*n
    cir.move(cx,cy)
    paper.add(cir)
