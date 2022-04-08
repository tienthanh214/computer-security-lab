# import library 
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

# constant 
PLAINTEXT = b"This is a top secret."
CIPHERTEXT = bytes.fromhex("764aa26b55a4da654df6b19e4bce00f4ed05e09346fb0e762583cb7da2ac93a2")
iv = bytes.fromhex("aabbccddeeff00998877665544332211")

# read dictionary
with open('words.txt') as f:
	word_list = f.read().split('\n')

def decrypt(text, key):
	cipher = AES.new(key, AES.MODE_CBC, iv)
	return cipher.encrypt(pad(text, 16))

if __name__ == '__main__':
	for key in word_list:
		key_pad = key + '#' * (16 - len(key) % 16)
		key_pad = bytearray(key_pad, 'utf-8')
		if (decrypt(PLAINTEXT, key_pad) == CIPHERTEXT):
			print('Key:', key)
			
