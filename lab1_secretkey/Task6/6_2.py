#!/usr/bin/python3

# XOR two bytearrays
def xor(first, second):
   return bytearray(x^y for x,y in zip(first, second))

p1 = "This is a known message!"
c1 = "a469b1c502c1cab966965e50425438e1bb1b5f9037a4c159"
c2 = "bf73bcd3509299d566c35b5d450337e1bb175f903fafc159"

# Convert ascii string to bytearray
p1 = bytes(p1, 'utf-8')

# Convert hex string to bytearray
c1 = bytearray.fromhex(c1)
c2 = bytearray.fromhex(c2)

p2 = xor(p1, xor(c1, c2))
print(p2)
