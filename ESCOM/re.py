#! /usr/bin/env python
from Crypto.Hash import SHA256
from Crypto.Cipher import AES
import random
hash = SHA256.new()

llav=open('llave.txt','r')
llave=llav.read(5)

print llave
