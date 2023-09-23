from decimal import getcontext, Decimal

getcontext().prec = 10**16

a = input()
b = input()

a = Decimal(a)
b = Decimal(b)

print(a/b)
