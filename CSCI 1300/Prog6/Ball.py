class Ball:
    def __init__(self,initialX=float(0),initialY=float(0),velocityX=float(0),velocityY=(0)): #provides initial values for velocity and postion
        self._posX=(initialX)
        self._posY=(initialY)
        self._velX=(velocityX)
        self._velY=(velocityY)
        
    def getPositionX(self):                      #the getPosition or getVelocity functions are simply in nature as it just
        return self._posX                        #returns the current value of the position or velocity in either direction  
    
    def getPositionY(self):
        return self._posY
    
    def getVelocityX(self):
        return self._velX
    
    def getVelocityY(self):
        return self._velY

    def advance(self,world):                     #the postion of the ball is advanced for each tick of the clock by
        self._posX+=self._velX                   #one factor of the velocity in both directions
        self._posY+=self._velY

        gravity=world.getGravity()               #this is a needed function to get the value of gravity for the simulated world
        self._velY+=gravity                      #the value of the velocity in the Y direction is directly affected by gravity and
                                                 #must be accounted for by adding it to self._velY once for each tick of the clock 
