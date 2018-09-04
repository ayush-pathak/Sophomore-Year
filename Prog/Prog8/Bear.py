from cs1graphics import *
from time import sleep

class Bear(Layer):
    """A layer instance representing a Bear.

    The user can choose and alter the color, make the bear roar and walk """


    def __init__(self, bodyColor='brown', earColor='pink', eyeColor='black'):
        """Creates a new instance of the Bear class

        The reference point of the bear is the bottom middle of the Bear.

        bodyColor     the initial color of the body of the Bear
        earColor      the initial color of the ears of the Bear
        eyeColor      the initial color of the eyes of the Bear
        """
        Layer.__init__(self)

        self._leg1 = Rectangle(10,30,Point(-35,10))
        self._leg1.adjustReference(5,-15)
        self._leg1.setFillColor(bodyColor)
        self.add(self._leg1)

        self._leg2 = Rectangle(10,30,Point(35,10))
        self._leg2.adjustReference(5,-15)
        self._leg2.setFillColor(bodyColor)
        self.add(self._leg2)

        self._leg3 = Rectangle(10,30,Point(-37,10))
        self._leg3.adjustReference(-5,-15)
        self._leg3.setFillColor(bodyColor)
        self.add(self._leg3)

        self._leg4 = Rectangle(10,30,Point(37,10))
        self._leg4.adjustReference(-5,-15)
        self._leg4.setFillColor(bodyColor)
        self.add(self._leg4)

        self._face = Circle(30,Point(40,-30))
        self._face.setDepth(30)
        self._face.setFillColor(bodyColor)
        self.add(self._face)

        self._ear1 = Circle(12,Point(10,-50))
        self._ear1.setBorderWidth(2)
        self._ear1.setBorderColor(bodyColor)
        self._ear1.setFillColor(earColor)
        self.add(self._ear1)

        self._ear2 = Circle(12,Point(70,-50))
        self._ear2.setBorderWidth(2)
        self._ear2.setBorderColor(bodyColor)
        self._ear2.setFillColor(earColor)
        self.add(self._ear2)

        self._eye1 = Circle(3,Point(47,-38))
        self._eye1.setFillColor(eyeColor)
        self._eye1.setBorderColor(eyeColor)
        self._eye1.setDepth(30)
        self.add(self._eye1)

        self._eye2 = Circle(3,Point(33,-38))
        self._eye2.setFillColor(eyeColor)
        self._eye2.setBorderColor(eyeColor)
        self._eye2.setDepth(30)
        self.add(self._eye2)

        self._mouth=Spline(Point(33,-18),Point(40,-8),Point(47,-18))
        self._mouth.adjustReference(7,10)
        self._mouth.setBorderWidth(3)
        self._mouth.setDepth(0)
        self.add(self._mouth)

        self._roar = Circle(5,Point(40,-20))
        self._roar.setFillColor('black')
        self._roar.setDepth(0)
        self._roarOpen = False

        self._body=Rectangle(90,30,Point(0,-15))
        self._body.setFillColor(bodyColor)
        self.add(self._body)

    def roarIsOpen(self):
        """Returns True if roar is open; False otherwise"""
        return self._roarOpen

    def toggleRoar(self):
        """ Switches the state of the roar to the opposite

        That is, adds the roar if not active; removes if active.

        The default behavior is the roar is not active
        """
        increment=1
        if self._roarOpen==False:
            for i in range(80):
                sleep(0.01)
                self._mouth.scale(1-increment/100.0)
            self.remove(self._mouth)
            self.add(self._roar)
            for j in range(80):
                sleep(0.01)
                self._roar.scale(1+increment/100.0)
            self._roarOpen = not self._roarOpen

        else:
            for i in range(80):
                sleep(0.01)
                self._roar.scale(1-increment/100.0)
            self.remove(self._roar)
            self.add(self._mouth)
            for j in range(80):
                sleep(0.01)
                self._mouth.scale(1+increment/100.0)
            self._roarOpen = not self._roarOpen
        
    def walk(self):
        """Make the bear"""
        for i in range(45):
            sleep(0.01)
            self._leg1.rotate(1)
            self._leg2.rotate(1)
            self._leg3.rotate(-1)
            self._leg4.rotate(-1)
        for k in range(45):
            sleep(0.01)
            self._leg1.rotate(-1)
            self._leg2.rotate(-1)
            self._leg3.rotate(1)
            self._leg4.rotate(1)
            
    def setBodyColor(self,newColor):
        """Change the color of the body of the bear

        newColor     the color which the bear will become"""
        self._leg1.setFillColor(newColor)
        self._leg2.setFillColor(newColor)
        self._leg3.setFillColor(newColor)
        self._leg4.setFillColor(newColor)
        self._ear1.setBorderColor(newColor)
        self._ear2.setBorderColor(newColor)
        self._face.setFillColor(newColor)
        self._body.setFillColor(newColor)
        
    def setEarColor(self,newColor):
        """Change the ear color of the bear

        newColor     the color which the ears will become"""
        self._ear1.setFillColor(newColor)
        self._ear2.setFillColor(newColor)

    def setEyeColor(self,newColor):
        """Change the eye color of the bear

        newColor     the color which the eyes will become"""
        self._eye1.setFillColor(newColor)
        self._eye1.setBorderColor(newColor)
        self._eye2.setFillColor(newColor)
        self._eye2.setBorderColor(newColor)
        
    
        
if __name__ =='__main__':
    #normal behavior
    paper=Canvas(600,600)
    normal=Bear()
    normal.move(200,200)
    paper.add(normal)

    raw_input('Press enter to continue')
    #change the body color
    bodyChange= Bear()
    bodyChange.move(200,400)
    paper.add(bodyChange)
    bodyChange.setBodyColor('purple')

    raw_input('Press enter to continue')
    #change eye color
    eyeChange = Bear()
    eyeChange.move(400,400)
    paper.add(eyeChange)
    eyeChange.setEyeColor('yellow')

    raw_input('Press enter to continue')
    #change ear color
    earChange = Bear()
    earChange.move(400,200)
    earChange.setEarColor('purple')
    paper.add(earChange)

    raw_input('Press enter to continue')
    #toggleRoar
    roaring = Bear()
    roaring.move(200,500)
    paper.add(roaring)
    roaring.toggleRoar()
        
    
