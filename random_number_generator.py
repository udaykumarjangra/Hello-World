import struct
import time

def lastbit(f):
    return struct.pack('!f', f)[-1] & 1

def getrandbits(k):
    result = 0
    for _ in range(k):
        time.sleep(0)
        result <<= 1
        result |= lastbit(time.process_time())
    return result
    
print(getrandbits(10))
