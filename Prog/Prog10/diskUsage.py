import os

def diskUsage(path):
    total = os.path.getsize(path)
    if os.path.isdir(path):
        for item in os.listdir(path):
            total = total + diskUsage(os.path.join(path, item))
    print  total, path
    return total
    
    
    
    


    
