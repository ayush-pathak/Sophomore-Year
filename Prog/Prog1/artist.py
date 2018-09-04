from cs1graphics import *
from time import sleep

paper = Canvas(400,400)
paper.setTitle('Bear and Bird')

#sun
sun=Circle(30)
sun.setFillColor('yellow')
sun.setDepth(0)
sun.moveTo(350,40)
paper.add(sun)

#grass
grass= Rectangle(400,100)
grass.moveTo(200,350)
grass.setFillColor('green')
grass.setBorderWidth(0)
paper.add(grass)
#sky
sky= Rectangle(400,400)
sky.setFillColor('skyblue')
sky.moveTo(200,100)
sky.setBorderWidth(0)
paper.add(sky)

#treetop
tree=Layer()
top= Polygon(Point(350,80),Point(330,140),Point(370,140))
tree.add(top)
tree.scale(1.2)
tree.move(-60,160)
top.setFillColor('lightgreen')
top.setBorderColor('darkgreen')
top.setBorderWidth(2)
paper.add(tree)

#trunk
trunk=Rectangle(10,20)
trunk.moveTo(350,140)
trunk.setFillColor('brown')
trunk.setDepth(100)
trunk.setBorderColor('transparent')
tree.add(trunk)

#bird
bird=Layer()
wing1=Polygon(Point(100,200),Point(150,190),Point(100,175))
wing1.setFillColor('grey')
bird.add(wing1)
                   
wing2=wing1.clone()
wing2.move(-30,0)
wing2.flip()
wing2.setFillColor('grey')
bird.add(wing2)

body=Circle(30)
body.moveTo(85,185)                  
body.setFillColor('black')
bird.add(body)

beak=Polygon(Point(85,180),Point(85,190),Point(90,185))
beak.move(5,5)

beak.setFillColor('yellow')
bird.add(beak)

eye1=Circle(5)
eye1.moveTo(78,175)
eye1.setFillColor('blue')
bird.add(eye1)

eye2= eye1.clone()
eye2.move(15,0)
bird.add(eye2)

bird.adjustReference(85,185)

paper.add(bird)

#bear
bear= Layer()

leftear=Circle(20)
leftear.moveTo(150,300)
leftear.setFillColor('brown4')
leftear.setBorderWidth(0)
bear.add(leftear)

rightear=Circle(20)
rightear.moveTo(200,300)
rightear.setFillColor('brown4')
rightear.setBorderWidth(0)
bear.add(rightear)          

face=Circle(30)
face.moveTo(175,320)
face.setFillColor('brown4')
face.setBorderWidth(0)
bear.add(face)

bearbody= Rectangle(90,30)
bearbody.moveTo(140,330)
bearbody.setDepth(100)
bearbody.setFillColor('brown4')
bearbody.setBorderWidth(0)
bear.add(bearbody)

leg1= Rectangle(10,20)
leg1.setFillColor('brown4')
leg1.moveTo(150,350)
leg1.setBorderWidth(0)
bear.add(leg1)

leg2=leg1.clone()
leg2.moveTo(110,350)
bear.add(leg2)

beareye1= Circle(5)
beareye1.setFillColor('black')
beareye1.moveTo(160,310)
bear.add(beareye1)

beareye2=beareye1.clone()
beareye2.moveTo(185,310)
bear.add(beareye2)

bearmouth= Circle()
bearmouth.moveTo(174,327)
bearmouth.setFillColor('black')
bearmouth.scale(0.3)
bear.add(bearmouth)
bear.adjustReference(140,330)

paper.add(bear)

#text

roar=Text('ROAR!!!', 20)
roar.moveTo(230,250)
roar.scale(2)

#animation


##bird.moveTo(-25,-25)
##bear.moveTo(-80,350)
###bird flying towards tree
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,10)
##sleep(0.25)
##bird.move(0,10)
##sleep(0.25)
##bird.move(0,10)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##sleep(0.25)
##bird.move(0,10)
##sleep(0.25)
##bird.move(0,10)
##sleep(0.25)
##bird.move(10,0)
##bird.flip()
##
###bear moving in
##sleep(0.25)
##bear.move(80,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##
###bear roaring
##bear.adjustReference(-45,-15)
##sleep(0.25)
##bear.rotate(-15)
##sleep(0.25)
##bearmouth.scale(3.25)
##sleep(0.25)
##paper.add(roar)
##sleep(0.25)
##paper.remove(roar)
##bearmouth.scale(0.3)
##bear.rotate(15)
##bird.move(0,-30)
##
###bird flying away followed by bear
##sleep(0.25)
##bird.move(-10,-10)
##bear.move(10,0)
##sleep(0.25)
##bird.flip()
##bear.move(10,0)
##sleep(0.25)
##bird.move(10,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bird.move(20,0)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##sleep(0.25)
##bear.move(10,0)
##
##
