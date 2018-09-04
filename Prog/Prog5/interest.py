#########################
#  Function Defintions  #
#########################

def greeting():
    print 'This interest calculator will ask you to select an interest rate,\nfollowed by a principle value. It will then calculate and display\nthe principle, interest rate, and balance after one year. You will\nthen be invited to execute the process again or terminate.\n'



def getRate(choices):  
    letters=['A','B','C','D','E','F']
    notSelection=True
    while notSelection:                                       #finding out the interest rate
        try:
            print'Please select an interest rate:'
            for x in range(len(choices)):
                print letters[x]+')'+str(choices[x])+'%'
            choice=raw_input('Enter '+letters[0]+' - '+letters[x]+':')
            choice=choice.upper()
            interestRate=choices[letters.index(choice)]
            notSelection=False
        except (ValueError,IndexError):                       #Provides a catch if a valid selection is not made
            print 'That is not a valid selection.\n'
    return interestRate*0.01                                  #Returning the rate as a float makes the results function easier to format



def getPrinciple(limit):
    notValue=True
    print'\n'
    while notValue:
        initial=raw_input('Enter the principle: ')
        try:                                                  #Series of checks to make sure principle is a valid string 
            if initial[0]=='$':
                initial=initial.strip('$')
            if initial[0]=='-':                               #negative values are not allowed, so if starts with - you know its negative
                print 'Please enter a positive amount.\n'
                notValue=True
            elif float(initial)>=int(limit):
                print 'The principle must be less than $'+str(limit)+'.\n'
                notValue=True
            elif initial.count('.')>0:
                temp=initial.split('.')
                if len(temp[1])>2:
                    print'The principle must be in dollars and cents.\n'
                    notValue=True
                else:
                    notValue=False
            else:
                notValue=False
        except ValueError,TypeError:                          #these except statements are to catch if someone uses a blank string or uses a space beacause the
            print'Please enter a number.\n'                   #if statements are not able to check an empty string or blank line
            notValue=True
        except IndexError:
            print'Please enter a number.\n'
            notValue=True
    return float(initial)                                     #this is after all the checks are complete we know it is valid and now we return it as a float so that
                                                              #we can do valid math operations that we couldn't do as a string

def computeBalance(principle,rate):
    balance=principle+(principle*rate)
    return balance

    
def results(principle,rate,balance):                          #This is formating the table and making sure the tables are of correct spacing
    first='Initial Principle'
    second='Interest Rate'
    third='End of Year Balance'
    print'\n'
    print'{:<10}''{:^19}''{}'.format(first,second,third)      #Hardcoding the spacing 
    print'{:=<55}'.format('=')
    principleDisplay='$%.2f'%principle
    rateDisplay='%.2f'%rate
    balanceDisplay='$%.2f'%balance
    print'{:<20}{:<16}{}'.format(principleDisplay,rateDisplay,balanceDisplay)

def askYesorNo(prompt):
    notResponse=True
    while notResponse:
        answer=raw_input(prompt)
        try:
            answer=answer.lower()
            if answer[0]!='y' and answer[0]!='n':
                print'Please enter Yes or No.'
                notResponse=True
            if answer[0]=='y':
                notResponse=False
                notAnotherCalc=True
                return notAnotherCalc
            if answer[0]=='n':
                notResponse=False
                print'Quitting Program. Goodbye'
                notAnotherCalc=False
                return notAnotherCalc
        except IndexError:
            print'Please enter Yes or No.'
            notResponse=True
                
################
#  Calculator  #
################


notAnotherCalc=True
greeting()
while notAnotherCalc:
    from random import sample,randint
    choices=sorted(sample(range(1,20),randint(2,6)))
    limit=1000000
    prompt='Another Computation? [y/n]'
    rate=getRate(choices)
    principle=getPrinciple(limit)
    balance=computeBalance(principle,rate)
    results(principle,rate,balance)
    notAnotherCalc=askYesorNo(prompt)






