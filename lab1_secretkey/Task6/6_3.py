import six

def xor(first, second):
   return bytearray(x^y for x,y in zip(first, second))

def PCKS5Padding(msg):
    padding = 16 - len(msg) % 16
    return msg + six.int2byte(padding) * padding

IV1 = "923578330bc2842af29d0ee6e2c313f4"
IV2 = "b1b94d690bc2842af29d0ee6e2c313f4"
IV1 = bytearray.fromhex(IV1)
IV2 = bytearray.fromhex(IV2)
msg = PCKS5Padding(bytes("Yes", "utf-8"))

msg = xor(msg, xor(IV1, IV2))
print(msg.hex())

