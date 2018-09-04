orignalDNA=raw_input('Enter a DNA Sequence: ')
forwardPat=raw_input('Enter a pattern: ')

#finding forward pattern in sequence
startPat=orignalDNA.find(forwardPat) #returns start index of  forward pattern


#reversing the forward
reversePat=forwardPat[::-1]


#getting the string for reverse

temp=orignalDNA[startPat+len(forwardPat):]
endPat=temp.find(reversePat)+(startPat+len(forwardPat)) #finding the index in the orignal DNA
endPat+=len(forwardPat)
invertPair=orignalDNA[startPat:endPat]

pieces=orignalDNA.split(invertPair)

#new DNA string

newDNA=pieces[0]+invertPair[::-1]+pieces[-1]

print 'Mutated DNA sequence: '+newDNA
